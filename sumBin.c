// Given a sorted array and a number X, search two elements of array s.t. their sum is X. 
#include <stdio.h>
#include<stdlib.h>
 
int main(void) {
	// your code goes here
	int high,low,n,i,x,flag=0;
	printf("enter size of array\n");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter element whose sum is needed\n");
	scanf("%d",&x);	
	low=0;
	high=n-1;
	while(high>=low){
		if(arr[low]+arr[high]==x)
			{
				flag=1;
				break;
			}
		else if(arr[low]+arr[high]<x)
			low++;   //increasing the value of sum
		else
			high--;  //decreasing the value of sum
	}
	if(flag==0)
		printf("the sum could not be done\n");
	else
		printf("the lower index is %d and higher index is %d\n",low,high);
	return 0;
}
