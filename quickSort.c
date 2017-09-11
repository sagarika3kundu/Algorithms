#include <stdio.h>
int n;
//kth element in a M*N matrix (a[M][N]) is a[k/n][k%n]
int partition(int a[][100], int start, int end){
	int piv_elem = a[start/n][start%n];
	int i = start + 1;
	int j;
	for(j = start+1; j<= end; j++){
		if(a[j/n][j%n] < piv_elem){
		    int temp = a[i/n][i%n];
		    a[i/n][i%n] = a[j/n][j%n];
		    a[j/n][j%n] = temp;
			i++;
		}
	}
	int temp = a[(i-1)/n][(i-1)%n];
    a[(i-1)/n][(i-1)%n] = a[start/n][start%n];
	a[start/n][start%n] = temp;
	return i-1;
}
 
void quicksort(int a[][100], int start, int end){
	if(start < end){
		int piv = partition(a, start, end);
		quicksort(a,start, piv-1);
		quicksort(a,piv+1, end);
	}
}
 
int main(void) {
	int m, i, j;
	scanf("%d %d",&m, &n);
	int a[m][100];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	quicksort(a, 0, (m*n)-1);
	for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	return 0;
}
