/*
כתוב פונקציה אשר מקבלת מצביע למערך דינאמי דו-ממדי )ז"א, מצביע לאיבר ראשון
של מערך מצביעים( ומספרי שתי שורות של המערך.
על הפונקציה למממש החלפת תכני השורות הנתונות במערך תוך זמן (1(O.
על הפונקציה להיות אוניברסאלית כלפי טיפוס איברי המערך
*/


#include <stdio.h>
#include <stdlib.h>

#define N 3
#define L 3

int swapLines(int *pa,int *pb)
{
	void *temp = *pa;
		*pa = *pb;
		*pb = temp;

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
/*
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
*/
pa = &array;
pb = &array+1;

printf("%p and %p",pa, pb);

swapLines (&pa, &pb);

/*
printf("your array is after swap line1 and line2");

for (i=0;i<N;i++)
	{
	printf("\n");
	for (j=0;j<L;j++)
		{

		printf("%d",array[i][j]);
		printf("	");
		}
	}
*/

printf("\n %p and %p",pa, pb);

}
