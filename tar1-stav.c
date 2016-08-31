/// student1:stav vaknin
/// ID#: 313581654
///student1:alona rabinkin
/// ID#: 317945988


#include <stdio.h>
#include <stdlib.h>
#include "List.h"


int * powerArray(int n);//question 1
int ** productMatrix( int ** a, int **b, int n, int m, int t);
int  ArrayOf( int **a, int n, item **ansArray ,int m, list **ansList);
/* 
void main()
{
	//iterator
	int i, j;
	//variables of question 1
	int * res = NULL;
	int size;
	//variables of question 2
	int **newMat = NULL;
	int **mat1;//[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int **mat2;//[4][5] = {{13,14,15,16,17},{18,19,20,21,22},{23,24,25,26,27},{28,29,30,31,32}};
	//variables of question 3
	item *ansArray = NULL;
	int **a;
	list ansList = BuildList();
	list *pAnsList = &ansList;
	int m = 2,n = 3;
	int ansSize;

	int x = 1;
	while(x!=0)
	{
		printf("\nenter number of question or 0 to exit:\n");
		scanf("%d",&x);
		while(x<0||x>3)
		{
			printf("enter number of question or 0 to exit:\n");
			scanf("%d",&x);
		}
		if(x==1)
		{
			printf("enter size of power array:\n");
			scanf("%d",&size);
			res = powerArray(size);
			for(i=0;i<size;i++)
				printf("%d ",res[i]);
			printf("\n");
		}
		if(x==2)
		{
			mat1=(int**)malloc(3*sizeof(int*));
			for(i=0;i<3;i++)
			{
				mat1[i]=(int*)calloc(4,sizeof(int));
				for(j=0;j<4;j++)
					mat1[i][j] = 1+i+j;
			}
			mat2=(int**)malloc(4*sizeof(int*));
			for(i=0;i<4;i++)
			{
				mat2[i]=(int*)calloc(5,sizeof(int));
				for(j=0;j<5;j++)
					mat2[i][j] = 13+i+j;
			}
			newMat=productMatrix(mat1, mat2, 3, 4, 5);
			for(i=0;i<3;i++)
			{
				for(j=0;j<5;j++)
					printf("%d ",newMat[i][j]);
				printf("\n");
			}

		}
		if(x==3)
		{
			a=(int**)malloc(n*sizeof(int*));
			for(i=0;i<n;i++)
			{
				a[i]=(int*)calloc(m,sizeof(int));
			}
			for(i = 0; i < n; ++i)
			{
				for(j = 0; j < m; ++j)
				 {
					printf("Please enter element (%d, %d): ", i, j);
					scanf("%d", &(a[i][j]));
				 }
			}
			ansSize = ArrayOf( a, n, &ansArray , m, &pAnsList);
			for(i=0;i<ansSize;i++)
				printf("%d %d %d, ",ansArray[i].data, ansArray[i].i, ansArray[i].j);

			//printList
		}
	}

	//freeing question 1 memory if used
	if(res != NULL)
		free(res);

	//freeing question 2 memory if used
	if(newMat != NULL)
	{
		for(i=0;i<3;i++)
			free(newMat[i]);
		free(newMat);
	}

	//freeing question 3 memory if used
	if(a != NULL)
	{
		for(i=0;i<n;i++)
			free(a[i]);
		free(a);
	}
	if(ansArray != NULL)
	{
	
		free(ansArray);
	}
	FreeList(ansList);
}
*/
int * powerArray(int n)
{
	int *arr=(int*)calloc(n,sizeof(int));
	int i;
	arr[0]=1;
	for(i=1;i<n;i++)
	{
		arr[i]=arr[i-1]*2;
	}
	return arr;
}

int ** productMatrix( int ** a, int **b, int n, int m, int t)
{
	int i,j,k;
	int **matNew=(int **)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		matNew[i]=(int *)calloc(t,sizeof(int));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<t;j++)
		{
			for(k=0;k<m;k++)
			{
				matNew[i][j]+=(a[i][k])*(b[k][j]);
			}
		}
	}
	return matNew;
}
//m=cols,n=rows
int ArrayOf( int **a, int n, item **ansArray ,int m, list **ansList)
{
	int i,j,k;
	int count = 0;
	position pos = **ansList;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(i+j == a[i][j])
			{
				InsertItem(**ansList, pos, a[i][j],i,j);
				count++;
				pos = pos->next;
			}
		}
	*ansArray = (item *)malloc(count*sizeof(item));
	pos = **ansList;
	pos = pos->next;
	i=0;
	while(pos!=NULL)
	{
		(*ansArray)[i] = *pos;
		pos = pos->next;
		i++;
	}
	return count;
}
