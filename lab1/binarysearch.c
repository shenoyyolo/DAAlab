#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int iterbinsearch(int arr[],int l,int r,int x)
{
	
	
	
	while(l<=r)
	{
		int m=l+(r-l)/2;
		
		if(arr[m]==x)
			return m;
		
		if(arr[m]>x)
			l=m-1;
		else
			r=m+1;	         
	
	}
	return -1;	
		
}

void main()
{

	int arr[10000];
	
	int result;
	
	clock_t s,e;
	int n;
		int x;

		printf("enter the size of array\n");
		
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		arr[i]=rand()/10000;

		for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);

	
	qsort((void*)arr,n,sizeof(arr[0]),cmpfunc);
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);

	printf("enter the number to be searched\n");
	scanf(" %d",&x);
	printf("Lauda Lassan\n");
	printf("%i", x);
	printf("%i %i %i", x, x, x);
	//s=clock();
	result=iterbinsearch(arr,0,n-1,x);
	//e=clock();
	
	if(result==-1)
	{
		printf("The number is not present\n");
		
	}
	else
		{		
		printf("The number is found in position %d \n",result);

		}
	
	//printf("The time taken by iterative binary search was %lf\n",((double)(e-s))/CLOCKS_PER_SEC);




}

