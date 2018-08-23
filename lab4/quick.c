#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int partition (int arr[], int low, int high)
{
		int temp=0;
	

    int pivot = arr[high];    // pivot element
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)    //agar pivot se kam hoga to
        {
            i++;    // increment index of smaller element
            
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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int par_index = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, par_index - 1);
        quickSort(arr, par_index + 1, high);
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
	clock_t s,e;

	srand(time(0));
	
	printf("Enter the size of array\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		arr[i]=rand()/1000000;
	
	s=clock();	
    quickSort(arr, 0, n-1);
	e=clock();
	
    printf("Sorted array: n");
    printArray(arr, n);
	
	printf("the time taken by quick sort is %lf secs \n",((double)(e-s))/CLOCKS_PER_SEC);
	

    return 0;
}
