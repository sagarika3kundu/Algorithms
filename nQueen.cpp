#include <bits/stdc++.h>
using namespace std;
 
bool isSafe(int b[][100], int r, int c, int n){
	int i, j;
	for(i = 0; i < c; i++){
		if(b[r][i])
			return false;
	}
	for(i = r, j = c; i >= 0 && j >= 0; i--, j--){
		if(b[i][j])
			return false;
	}
	for(i = r, j = c; i < n && j >= 0; i++, j--){
		if(b[i][j])
			return false;
	}
	return true;
}
 
bool nQueen(int b[][100],  int c, int n){
	if(c>=n)
		return true;
	int i;
	for(i =0; i<n ; i++){
		//if the row in the curent column is unsafe, we move to the next row.
		if(isSafe(b, i, c, n)){
			//if the row in the curent column is safe, we mark it.
		b[i][c] = 1;
			//and proceed to the next column.
		if(nQueen(b, c+1, n))
			return true;
			//we unmark the row if the next column can have no solution.
		b[i][c] = 0;
		}
	}
		return false;
}
int main(){
	int n;
	cout << "enter the value of n\n";
	cin >> n;
	int i, j;
	int b[100][100] = {0};
 
	if(!nQueen(b, 0, n)){
		cout << "solution does not exist\n";
	}
	else{
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
			cout << b[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}
