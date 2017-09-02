#include <bits/stdc++.h>
using namespace std;
#define n 8
bool isSafe(int b[n][n], int r, int c){
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

bool nQueen(int b[n][n],  int c){
	if(c>=n)
		return true;
	int i;
	for(i =0; i<n ; i++){
		//if the row in the curent column is unsafe, we move to the next row.
		if(isSafe(b, i, c)){
			//if the row in the curent column is safe, we mark it.
		b[i][c] = 1;
			//and proceed to the next column.
		if(nQueen(b, c+1))
			return true;
			//we unmark the row if the next column can have no solution.
		b[i][c] = 0;
		}
	}
		return false;
}
int main(){
	cout << "enter the value of n\n";
	int i, j;
	int b[8][8] = {0};
	
	if(!nQueen(b, 0)){
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