#include<stdio.h>
#define max(a,b) a>b?a:b

void countSort(int a[], int n){
	int i, k=0;
	for(i=0; i<n;i++)
		k = max( k, a[i]);
	int aux[k+1];
	for(i=0; i<k+1; i++)
		aux[i] = 0;
	for(i=0; i<n; i++)
		aux[a[i]]++;
	int sorted[n];
	int j =0;
	for(i=0; i<k+1; i++){
		int temp = aux[i];
		while(temp--){
			sorted[j++] = i;
		}
	}
	for(i=0; i<n; i++)
		printf("%d ",sorted[i]);
}
int main(void) {
	int n, i;
	printf("enter no of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	countSort(a, n);
	return 0;
}
