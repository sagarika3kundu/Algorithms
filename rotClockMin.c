#include <stdio.h>
#include<stdlib.h>
int findMin(int arr[], int low, int high) {     
	// This condition is needed to handle the case when array is not     
	// rotated at all     
	if (high < low)  return arr[0];       
     
	// Find mid    
	int mid = (high + low)/2;        
	
	// Check if mid itself is minimum element     
	if (arr[mid] < arr[mid - 1])       
	return arr[mid];       
	// Decide whether we need to go to left half or right half     
	if (arr[high] > arr[mid])      //implies it is sorted and not rotated anywhere within.Hence we need to go to left half. 
	return findMin(arr, low, mid-1);    
	return findMin(arr, mid+1, high); 
}   
 
int main(void) {
	int n,i,min;
	printf("enter the size of array\n");
scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	min=findMin(arr,0,n-1);
	printf("%d\n",min);
	return 0;
}
