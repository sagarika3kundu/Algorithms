//here we have assumed that the max no of characters in each word will not be more than 100
//we have considered only alphabets as inputs.
//if we want to sort according to ascii we shall not subtract 65 from the index value of freq.
#include <iostream>
using namespace std;
void countSort(char a[][100], int n, int len, int m){
	int i,j;
	int freq[57] = {0};
	int output[n][len]= {0};
	for(i=0;i<n;i++)
		freq[(a[i][m-1])-65]++;
	for(i=1;i<57;i++)
		freq[i]+=freq[i-1];
	for(i=n-1;i>=0;i--){
		for(j=0; j<len; j++)
			output[freq[(a[i][m-1])-65]-1][j] = a[i][j];
		freq[(a[i][m-1])-65]--;
		}
	for(i=0;i<n;i++)
		for(j=0; j<len; j++)
			a[i][j] = output[i][j];
 
}
void radixSort(char a[][100], int n, int len){
	int m = len;
	while(m!=0){
		countSort(a, n, len, m);
		m--;
	}
}
 
int main() {
	int n, len, i, j;
	cout << "enter no of words\n";
	cin >> n;
	cout << "enter fixed no of characters in each word\n";
	cin >> len;
	char a[n][100];
	for(i=0; i<n; i++)
		for(j=0;j<len;j++)
			cin >> a[i][j];
	radixSort(a, n, len);
	for(i=0; i<n; i++){
		for(j=0;j<len;j++)
			cout << a[i][j];
		cout << "\n";
	}
	return 0;
}
