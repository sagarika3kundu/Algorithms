//Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. 
//Expected time complexity is O(logn). 
#include <stdio.h>
#include<stdlib.h>
//to find first occurence of x.
int first(int arr[],int low,int high,int x,int n){
if(high<low) return -3; //base condition
 
int mid=(high + low)/2;
if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x)       
	return mid;    
else if(x > arr[mid])       
	return first(arr, (mid + 1), high, x, n);   
else    
	return first(arr, low, (mid -1), x, n);  
}

//to find last occurence of x
int last(int arr[],int low,int high,int x,int n){
if(high<low) return -5; //base condition
 
int mid=(high + low)/2;
if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x )    
	return mid; 
else if(x < arr[mid])  
	return last(arr, low, (mid -1), x, n); 
else   
	return last(arr, (mid + 1), high, x, n);
}
int main(void) {
	int n,i,f,l,x;
	printf("enter the size of array\n");
scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the element to be searched\n");
	scanf("%d",&x);
	f=first(arr,0,n-1,x,n);
	l=last(arr,0,n-1,x,n);
	printf("%d\n",l-f+1); //will output -1 if element does not exist i.e. (-5-(-3)+1)
	return 0;
}
