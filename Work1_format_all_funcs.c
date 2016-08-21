//Or Halevy 305346835
//Daniel buzuky 203550744

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

/* Declarations of other functions */

int * powerArray(int sz);  //for first question


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
		case 3: Ex3(); break;
				}
		} while (all_Ex_in_loop && select);
	return 0;
}
/* Function definitions */

//Exercise 1
void main(){
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

/*
//Exercise 2
void Ex2()
{
	int n; //The lenght of the series
	printf("Please insert the lenght of the binary series: ");
	scanf("%d", &n);

	printf("\n\nthe sequence starts on the %dst place\n\n", binarysequence(n));
}


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

//Exercise 4
void Ex4()
{
	int lim;
	printf("the number to check ");
	scanf("%d", &lim);

	ambnumbers(lim);
}

void ambnumbers(int n)
{
	int i;
	int optionalnum;

	for (i = 1; i <= n; i++) //check the numbers until "i"
	{
		optionalnum = divids(i);

		if (optionalnum > i)
		{
			if (divids(optionalnum) == i)
				printf("Found %d and %d \n", i, optionalnum);
		}
	}
}

int divids(int checknum)
{
	int k;
	int sum = 1; //if check 1=>  num 1

	if (checknum == 1)
		return 1;

	for (k = 2; k*k < checknum; k++) //start on 2
	{
		if (checknum % k == 0)
			sum += k + (checknum / k);
	}

	if (k*k == checknum)
		sum += k;

	return sum;
}
*/

