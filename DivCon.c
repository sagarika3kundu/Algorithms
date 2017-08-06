//Finding second smallest and second largest element using Divide and Conquer
#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
//leftCount is size of left array
//rightCount is size of right array
//the smallest size of array entering MergeDuo is 2 and largest is 3
//we are modyfing in array A itself and replacing values at first 4 indices as smallest,second smallest,largest and second largest resp.
void MergeDuo(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
//to find second second smallest	
	i = 0; j = 0; k =0;
	while(k<2) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
//to find second largest	
	i=leftCount-1; j=rightCount-1;
	while(k<4){
		if(L[i] > R[j]) A[k++] = L[i--];
		else A[k++] = R[j--];
	}
	}

// Recursive function to sort an array of integers. 
void Sort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 4) {
		if(n==3){
		int lo = min(min(A[0], A[1]), A[2]);
   		int hi = max(max(A[0], A[1]), A[2]);
    A[1]=A[0]+A[1]+A[2]-lo-hi;
    A[0]= lo;
    A[2] =hi;  }
    else{
    	A[0]=min(A[0], A[1]);
    	A[1]=max(A[0], A[1]);
    }
		return;} // base condition. If the array has less than four element sort it. 
//the array will never have one element as we are not allowing 3
	mid = n/2;  // find the mid index. 

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	Sort(L,mid);  // sorting the left subarray
	Sort(R,n-mid);  // sorting the right subarray
	MergeDuo(A,L,mid,R,n-mid);  // Merging smallest,second smallest,largest,second largest among L and R into A
        free(L);
        free(R);
}

int main() {
	int n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int A[n]; // creating an array of integers. 
	int i,numberOfElements;
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	numberOfElements = sizeof(A)/sizeof(A[0]); 

	// Calling Sort to sort the array. 
	Sort(A,numberOfElements);

	//printing the second smallest and second largest
	 printf("%d %d",A[1],A[3]);
	return 0;
}
