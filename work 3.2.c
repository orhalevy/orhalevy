#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

	FILE *input, *output;
	int size,i,j=0,small,big;
	int *arr;
	double avg;

	input=fopen("in.txt","r");
	output=fopen("out.txt","w");

		if( !input ) //if file not opened- alert
			{
			printf("File cannot be open.\n");
			return;
			}

		printf("insert the biggest number");
		scanf("%d",&small);
		printf("insert the smallest number");
		scanf("%d",&big);

	fscanf(input,"%d",&size); // read the first numbers (X) from the in.txt

	arr = (int *) malloc(size*sizeof(int)); //create array with (X) numbers

	for (i=0 ; i <= size-1; i++) // read all the files, summerize and put in the new arr
		{
			fscanf (input, "%d", &arr[i]);

		}


	printf("\n\nElements value: \n\n"); //print all the new array
	for (i=0 ; i <= size-1 ; i++)
		{
			printf("arr[%d] = %d\n",i, arr[i]);
		}


	for (i=0 ; i <= size-1; i++) // print that between big and small
			{
				if ( small < arr[i] && arr[i] < big )
				{
				fprintf(output,"%d\t",arr[i]);
				j++;
			}
			}


	printf("between %d and %d there amount of numbers:",small,big,j);

		printf("\n%d   ",j);

		fprintf(output,"\n%d   ",j); // print amount of numbers bigger than average


fclose( output ); //free & close files
fclose( input );
free (arr);
}
