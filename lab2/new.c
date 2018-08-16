#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cmpfunc(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int iterbinsearch(int arr[],int left, int right, int x)
{

	while(left<right)
		{
			int middle=left+(right-left)/2;
	
			if(arr[middle]==x)
				return middle;
				
			if(arr[middle]>x)
					right=middle-1;//ignore right half
				else 
					left=middle+1;//ignore left half


		}
return -1;


}

int recurbinsearch(int arr[],int left,int right,int x)
{
	if(right>=1)
	{
		int middle=left+(right-left)/2;
		
		
			if(arr[middle]==x)
				return middle;

			if(arr[middle]>x)
				return (arr,left,middle-1,x);
			else
				return(arr,middle+1,right,x);
	
	}
		return -1;
}

void main()
{

	int arr[]={1,2,3,4,5};

	int result;

	clock_t s,e;
	
	int n,x;

	printf("Enter the size of the array\n");
	scanf("%d",&n);                        //size taken

		for(int i=0;i<n;i++)
			//{
				//arr[i]=rand()/10000;		//array made of random numbers
				printf("%d\n",arr[i]);		
		
			//}

qsort((void*)arr,n,sizeof(arr[0]),cmpfunc); //sorting

	
		for(int i=0;i<n;i++)			
			printf("%d\n",arr[i]);	//printing sorted array

	
	printf("enter the number to be searched\n");
	scanf("%d",&x);

		s=clock();
		result=iterbinsearch(arr,0,n-1,x);
		e=clock();

	if(result==-1)
		{
			printf("The number is not present\n");
			
		}
		else
			{		
			printf("The number is found in position %d \n",result);
	
			}
	
		printf("The time taken by iterative binary search  is %lf\n",((double)(e-s))/CLOCKS_PER_SEC);

		s=clock();
		result=recurbinsearch(arr,0,n-1,x);
		e=clock();

	if(result==-1)
		{
			printf("The number is not present\n");
			
		}
		else
			{		
			printf("The number is found in position %d \n",result);
	
			}
	
		printf("The time taken by recursive binary search is %lf\n",((double)(e-s))/CLOCKS_PER_SEC);



}



