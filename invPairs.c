//Apply Merge Sort to count inversion pairs in an array. 
//Two elements a[i] and a[j] form an inversion pair if a[i] > a[j] and i < j. 
//Example: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3). 
#include<stdio.h>
#include<stdlib.h>
 
int inv_count = 0; //taken as global variable so that we need not add left part, right and merged inv_count values.
 
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
//to find second second smallest	
	i = 0; j = 0; k =0;
while ((i < leftCount ) && (j < rightCount))    
{       if (L[i] <= R[j]){        
					A[k++] = L[i++];     
					}    
		else       
				{         
					A[k++] = R[j++];           
					inv_count = inv_count + (leftCount - i);
//since we are taking values from right array,it means the values(remaining) of left array are smaller than it. 
//Hence forming inversion pairs
				}   
}
while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
	}
 
// Recursive function to sort an array of integers. 
void Sort(int *A,int n) {
	int mid,i, *L, *R;
	if(n<2) return;
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
	Merge(A,L,mid,R,n-mid); 
        free(L);
        free(R);
}
 
int main() {
	int n,i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int A[n]; 
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	Sort(A,n);
	 printf("%d",inv_count);
	return 0;
}
