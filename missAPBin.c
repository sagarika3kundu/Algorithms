// Given an array that represents elements of arithmetic progression in order. 
//One element is missing in the progression, find the missing number. 
#include <stdio.h>
#include<stdlib.h>
#define min(a,b) (a<b?a:b);
int findMiss(int arr[], int low, int high) {  
	if(high<low) return;
	// Find mid    
	int mid = (high + low)/2;        
	int term,d;
	// Check if mid-1 is missing     
	if (arr[mid] - arr[mid - 1] > arr[mid+1] - arr[mid])       
	return mid; //since that element must be in mid position
	// Check if mid+1 is missing   
	if (arr[mid] - arr[mid - 1] < arr[mid+1] - arr[mid])       
	return mid+1; //since that element must be in mid+1 position
	// Decide whether we need to go to left half or right half     
	//cal the correct value at mid using a+(n-1)d formula
	d=min(arr[mid] - arr[mid - 1] , arr[mid+1] - arr[mid]);
	term=arr[0]+(mid)*d;
	if (arr[mid] == term)       
	return findMiss(arr, mid+1,high);    
	return findMiss(arr, low, mid-1); 
}   
 
int main(void) {
	int n,i,miss,d,t;
	printf("enter the size of array\n");
scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	miss=findMiss(arr,0,n-1);
	d=min(arr[1] - arr[0] , arr[2] - arr[1]);
	t=arr[0]+(miss)*d;
	printf("%d\n",t);
	return 0;
}
