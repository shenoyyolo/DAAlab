#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void inssort(int arr[],int n)
{
	int i,ins,j;

	for(i=1;i<n;i++)
	{
		ins=arr[i];
		j=i-1;
		
		while(j>=0 && arr[j]>ins)
		{
			arr[j+1]=arr[j];			
			j=j-1;
		}
			arr[j+1]=ins;				
			
	}
}

void selsort(int arr[],int n)
{

	int mini,i,j,temp;

	for(i=0;i<n;i++)
	{
		mini=i;
		
		for(j=i+1;j<n;j++)
		if(arr[j]<arr[mini])
			{
				mini=j;
			}
		temp=arr[mini];
		arr[mini]=arr[j];
		arr[j]=temp;
				
	}
	
}

void main()
{
	clock_t s,e;
	
	int arr[100000],a,b;
	int ins,i,j,n;
	
	printf("enter number of elements\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)	
	arr[i]=rand();
	
	s=clock();	
	inssort(arr,n);
	e=clock();

	
		printf("the time taken by insertion sort is %lf seconds\n",((double)(e-s))/CLOCKS_PER_SEC);	
		
		s=clock();
		selsort(arr,n);
		e=clock();
		printf("the time taken by selection sort is %lf seconds\n",((double)(e-s))/CLOCKS_PER_SEC);		


}	

