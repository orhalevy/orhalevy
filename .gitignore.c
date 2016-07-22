#include <stdio.h>

void main(){
	int arr[10]={50 ,60 ,60 ,72 ,81 ,81 ,81 ,81 ,93 ,93} ,i;
	int *arr2,j=1;
	int size = sizeof(arr)/sizeof(int);

	for (i=0;i<=10;i++)
	{
		printf("%d, ",arr[i]);

	}

	arr2 = (int*) malloc(sizeof(arr)*sizeof(int));

    for (j=0;j>i-1;j++)
    {
    	if (arr[i]!=arr[i+1])
    	{
    		arr2[j]=arr[i];
    		i++;
    		j++;
    	}
    	else
    		i++;
    }

	for (i=0;i<=10;i++)
		{
			printf("%d, ",arr2[i]);

		}

	free(arr2);
}
