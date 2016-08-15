/*
כתוב פונקציה אשר מקבלת מצביע למערך דינאמי דו-ממדי, כמות שורות במערך
ומספרי שתי עמודות של המערך.
על הפונקציה למממש החלפת תכני העמודות הנתונות במערך*/


#include <stdio.h>
#include <stdlib.h>

#define N 2
#define L 3



void array_swap (int *a, int *b, int n)
{
	int i;
	for (i=0; i<n; i++)
		swap(a+i,b+i);
}

void swap(int a, int b)
{
   int temp;

   temp = b;
   b   = a;
   a   = temp;
}

void main(){
int **array;
int *pa, *pb;
int line1=1, line2=2;
int i,j;

array = (int **)malloc(N * sizeof(int *));   // `N` is the number of rows

if(array == NULL)
{
    printf("There is not enough memory first creation.\n");
}

for(i = 0; i < L; i++)
{
    array[i] =(int *) malloc(i * sizeof(int));

    if(array[i] == NULL)
    {
        printf("There is not enough memory second creation.\n");
    }
}

printf("your original array");

for (i=0;i<N;i++)
{
	printf("\n");
	for (j=0;j<L;j++)
	{

		printf("%d",array[i][j]);
		printf("	");
	}
}

pa = &array; //עמודה ראשונה
pb = &array+1; //עמודה שנייה


// i=rows-  L שורות
// j=columns-N  עמודות

array_swap (pa, pb, N);


printf(" \n\nyour array is after swap line1 and line2 \n");

for (i=0;i<N;i++)
	{
	printf("\n");
	for (j=0;j<L;j++)
		{

		printf("%d",array[i][j]);
		printf("	");
		}
	}

}






