//Or Halevy 305346835
//Daniel buzuky 203550744

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Function declarations */

void Ex1();
void Ex2();
//void Ex3();

/* Declarations of other functions */

int * powerArray(int sz);  //for first question
int ** productMatrix( int ** mat1, int **mat2, int rows_mat1, int columns_mat2);


/* ------------------------------- */

int main() {
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number)  ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do {
		for (i = 1; i<5; i++)
			printf("Ex%d--->%d\n", i, i);
		printf("EXIT-->0\n");
		do {
			select = 0;
			printf("please select 0-4 : ");
			scanf("%d", &select);
		} while ((select<0) || (select>4));
		switch (select) {
		case 1: Ex1(); break;
		case 2: Ex2(); break;
	//	case 3: Ex3(); break;
				}
		} while (all_Ex_in_loop && select);
	return 0;
}
/* Function definitions */

//----------------------------------------


//Exercise 1
void Ex1(){
	int * arr,j;
	int n;

	//Get array size from the user
	printf("Please input the wanted size for the array: ");
	scanf("%d", &n);

	//Send the value to createArr function
	arr = powerArray(n);
	if(!arr){ //Check if the creation and fill was successful
		puts("Error creating array\n");
		exit(1);
	}

	puts("Printing array: ");
	for(j=0; j<n; j++){
		printf("%d ", arr[j]);
	}

	//Just add an empty line at the end, and free the memory.
	puts("");
	free(arr);

}



int * powerArray(int sz){
//This function creates a new array with given size
//and returns a pointer to the array.
	int prev=2, i;
	int *arr = (int *) malloc(sz*sizeof(int));
	if(!arr){
		//If an error accoured during the allocation
		//print an error msg, and return null
		puts("Error allocating memory for array");
		return NULL;
	}

	printf("Memory was allocated: %p\n", arr);
	//Done allocating memory

	//**Note: As arr[0] will ALWAYS have the value: 1,
	//I decided to hard-code it.

	arr[0]=1;
	//This part of the function will fill the array
	for(i=1; i<sz; i++){
		arr[i]=prev;
		prev*=2;
	}//End of loop

	return arr;
}

//----------------------------------------

//Exercise 2

void Ex2(){
int **mat1, **mat2; //mat1, mat2
int rows_mat1,columns_mat1,rows_mat2,columns_mat2; //rows & columns mat1+2
int *pointer; //The pointer to the Multiplied matix
int i,j;

printf("\nEnter the rows of the First matrix  =>       ");
scanf("%d",&rows_mat1);

printf("\nEnter the columns of the First matrix  =>       ");
scanf("%d" ,&columns_mat1);


printf("\nEnter the rows of the Second matrix  =>       ");
scanf("%d",&rows_mat2);
printf("\nEnter the columns of the Second matrix  =>       ");
scanf("%d",&columns_mat2);


if(columns_mat1!=rows_mat2){ // A necessary condition that matrix could multiply each other
    printf("Invalid Order of matrix (can't multiply those martices"); // number of columns mat1 not even the number of rows mat2
    exit(EXIT_SUCCESS);
}

mat1= (int**) malloc(rows_mat1*sizeof(int*)); //malloc first mat- rows

for(i=0;i<columns_mat1;i++) //malloc first mat- columns
    mat1[i]=(int*)malloc(columns_mat1*sizeof(int));

//Input Matrix1

	printf("\nNow we will input first matrix: \n");

    for(i=0;i<rows_mat1;i++) //scan from user the integers of mat 1
	{
        for(j=0;j<columns_mat1;j++)
		{
		printf("\nfill in the [%d],[%d] =>       ",j+1, i+1);
	
        scanf("%d",&mat1[i][j]);
		}
	}
    /*
	ADDITIONAL
        //Printing Input Matrix 1
        printf("\n Entered Matrix 1: \n");
        for(i=0;i<rows_mat1;i++){
            for(j=0;j<columns_mat1;j++)
                printf("%d ",mat1[i][j]);
            printf("\n");
        }
     */

mat2= (int**) malloc(rows_mat2*sizeof(int*)); //malloc second mat - rows

for(i=0;i<columns_mat2;i++) //malloc second mat - columns
    mat2[i]=(int*)malloc(columns_mat2*sizeof(int));

//Input Matrix2

	printf("\nNow we will input second matrix: \n");

    for(i=0;i<rows_mat2;i++) //scan from user the integers of mat 2
	{
        for(j=0;j<columns_mat2;j++)
		{
			printf("\nfill in the [%d],[%d] =>       ",j+1, i+1);
            scanf("%d",&mat2[i][j]);
		}
	}

/*
 ADDITIONAL
    //Printing Input Matrix 2
       printf("\n Entered Matrix 2: \n");
for(i=0;i<rows_mat2;i++){
    for(j=0;j<columns_mat2;j++)
        printf("%d ",mat2[i][j]);
    printf("\n");
}
*/



    pointer = *productMatrix( mat1, mat2, rows_mat1, columns_mat2);

    printf("address new array is: %p and point to %d \n\n\n)", &pointer, *pointer);
}




int **productMatrix( int ** mat1, int **mat2, int rows_mat1, int columns_mat2){

    int **multiplied_mat;
    int i,j,k; //columns & rows new array and index k

multiplied_mat=(int**)calloc(rows_mat1,sizeof(int*));

for(i=0;i<columns_mat2;i++)
    multiplied_mat[i]=(int*)calloc(columns_mat2,sizeof(int));


//Multiplication

    for(i=0;i<rows_mat1;i++){
        for(j=0;j<columns_mat2;j++){
                multiplied_mat[i][j]=0;
                for(k=0 ; k < columns_mat2 ; k++ ) // here!
                    multiplied_mat[i][j]+= mat1[i][k]*mat2[k][j];

        }
        printf("\n");
    }


    /*
     ADDITIONAL
        //Printing third mat
         *
   printf("\nThe Multiplication of two matrix is\n");
   for(i=0;i<rows_mat1;i++){
       printf("\n");
       for(j=0;j<columns_mat2;j++){
            printf("%d\t",multiplied_mat[i][j]);
   }
    printf("\n");
    }
    */





return multiplied_mat; //return address new array
}


//----------------------------------------

/*
//Exercise 3
void Ex3()
{
	int n;
	printf("\nEnter the number of rows you wish to see in pascal triangle ");
	scanf("%d", &n);
	pascaltriangle(n);
}
void pascaltriangle(int n)
{
	int rows = n, line;
	int index, basis, space, tab;
	printf("\n\n");
	tab = rows;
	for (index = 0; index <= rows; index++)
	{
		basis = 1; //base is 1
		for (space = tab; space >= 0; space--) //the space will return tab to get the troangle better
			printf(" ");
		tab--; //every row get the tab -1 (smaller)
		for (line = 0; line <= index; line++)
		{
			printf("%d ", basis);
			basis = (basis*(index - line) / (line + 1));
		}
		printf("\n"); //new line to the triangle
	}
}
*/
