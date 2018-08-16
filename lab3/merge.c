#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void merge(int arr[], int left, int middle, int right)
{
	
	int i, j , k;
	
	int n1=middle- left + 1;
	
	int n2=right - middle;
	
	int lef[n1], righ[n2];
	
	for(i=0;i<n1;i++)
		lef[i]=arr[left+i];

	for(j=0;j<n2;j++)
		righ[j]=arr[middle+1+j];
	
	i=0;j=0;k=left;
	
	while(i<n1 && j<n2)
	{
		if(lef[i]<=righ[j])
			{
				arr[k]=lef[i];	
				i++;
			}
		else
			{
				arr[k]=righ[j];
				j++;			
			}
			k++;	
	}

		while(i<n1)
			{
				arr[k]=lef[i];
				i++;
				k++;
			}

		while(j<n2)
			{
				arr[k]=righ[j];
				j++;
				k++;			
			}		

}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int middle = left+(right-left)/2;
 
        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
 
        merge(arr, left, middle, right);
    }
}
int main()
{
	srand(time(0));
	int i;
	int arr[10000],n;
	printf("enter the number of elements");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		arr[i]=rand()/1000;
		
	
	clock_t s,e;
	
	s=clock();		
	mergeSort(arr,0,n-1);
	e=clock();

	
	
		
		

	printf("Time taken is %lf",((double)(e-s))/CLOCKS_PER_SEC);
				


}


