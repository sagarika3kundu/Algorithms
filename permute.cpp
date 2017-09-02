#include <bits/stdc++.h>
using namespace std;

void swap(char *x, char *y){
	char temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, int l, int r){
int i;
if(l == r)                    //n-1 elements are at fixed place implies nth element is at fixed place.
	{
		for(i=0; i<=r; i++)
			cout << a[i];
		cout << "\n";
	}
else{
	
	for(i= l; i <= r; i++) {
		swap((a+l), (a+i));
		permute(a, l+1, r);
		swap((a+l), (a+i));
				}
	}
}

int main() {
	cout << "enter no of characters\n";
	int n,i;
	cin >> n;
	char a[n];
	for(i =0; i <n; i++)
		cin >> a[i];
	permute(a, 0, n-1);
	return 0;
}
