#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partitionend (int arr[], int low, int high)
{
		int temp=0;
    int pivot = arr[high];    // pivot element
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)    //agar pivot se kam hoga to
        {
            i++;    //chote ka index badhao
            
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
        }
    }
 			temp=arr[i+1];
			arr[i+1]=arr[high];
			arr[high]=temp;  
    return (i + 1);
	
}

int partitionstart (int arr[], int low, int high)
{
		int temp=0;
    int pivot = arr[low];    // pivot element
    int i = (low + 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)    //agar pivot se kam hoga to
        {
            i++;    //chote ka index badhao
            
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
        }
    }
 			temp=arr[i+1];
			arr[i+1]=arr[high];
			arr[high]=temp;  
    return (i - 1);
	
}

int partitionrandom(int arr[], int low, int high)
{
	int temp=0;
    int pivotIndex = low + rand()%(high - low + 1); //generates a random number as a pivot
    int pivot;
    int i = low- 1;
    int j;
    pivot = arr[pivotIndex];
   
			temp=arr[pivotIndex];
			arr[i+1]=arr[high];
			arr[high]=temp;  


    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
         		temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
        }
 
    }
 			temp=arr[i+1];
			arr[i+1]=arr[high];
			arr[high]=temp; 
    return i + 1;
}


void quickSortend(int arr[], int low, int high)
{
    if (low < high)
    {
        int par_index = partitionend(arr, low, high);
 
        quickSortend(arr, low, par_index - 1);
        quickSortend(arr, par_index + 1, high);
    }
}

void quickSortstart(int arr[], int low, int high)
{
    if (low < high)
    {
        int par_index = partitionstart(arr, low, high);
 
        quickSortstart(arr, low, par_index - 1);
        quickSortstart(arr, par_index + 1, high);
    }
}


void quickSortrandom(int arr[], int low, int high)
{
    if (low < high)
    {
        int par_index = partitionrandom(arr, low, high);
 
        quickSortrandom(arr, low, par_index - 1);
        quickSortrandom(arr, par_index + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d \n", arr[i]);
    
}

int main()
{
    int arr[10000];

    int n,i; 
	clock_t s1,e1,s2,e2,s3,e3;

	srand(time(0));
	
	printf("Enter the size of array\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		arr[i]=rand()/1000000;
	
	s1=clock();	
    quickSortend(arr, 0, n-1);
	e1=clock();
	
	
	
	printf("the time taken by quick sort end pivot is %lf secs \n",((double)(e1-s1))/CLOCKS_PER_SEC);
	
	s2=clock();	
    quickSortstart(arr, 0, n-1);
	e2=clock();
	
	printf("the time taken by quick sort start pivot is %lf secs \n",((double)(e2-s2))/CLOCKS_PER_SEC);
   	


	s3=clock();	
    quickSortrandom(arr, 0, n-1);
	e3=clock();	
	printf("the time taken by quick sort random pivot is %lf secs \n",((double)(e3-s3))/CLOCKS_PER_SEC);
   	 return 0;



}




















