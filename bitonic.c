//find bitonic point
#include <stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b?a:b);
int bitonic(int arr[], int low, int high) {  
	if(high<low) return;
	// Find mid    
	int mid = (high + low)/2;        
	// Check if mid is the Bitonic Point     
	if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid+1])       
	return mid; 
	// Decide whether we need to go to left half or right half     
	if (arr[mid] < arr[mid+1])       //implies we are in ascending part
	return bitonic(arr, mid+1,high);    
	return bitonic(arr, low, mid-1); 
}   
 
int main(void) {
	int n,i,bitpnt;
	printf("enter the size of array\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	bitpnt=bitonic(arr,0,n-1);
	printf("%d\n",arr[bitpnt]);
	return 0;
}
