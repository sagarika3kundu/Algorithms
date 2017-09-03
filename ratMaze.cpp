#include <bits/stdc++.h>
using namespace std;
 
bool isSafe(int b[][100], int r, int c, int n){
		if( (b[r][c] == 1) && (r>=0 && r<n) && (c>=0 && c<n) )
				return true;
}
 
void print(int s[][100], int n){
	int i, j;
	for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cout << s[i][j]<< " ";
			}
			cout << "\n";
	}
	cout << "\n";
}
 
bool ratMaze(int b[][100], int r, int c, int n, int s[][100]){
	if(r == n-1 && c == n-1)
				{	
			        s[r][c] = 1;
					return true;
				}	
	if(isSafe(b, r, c, n)){
	    s[r][c] = 1;
	    if(ratMaze(b, r+1, c, n, s))
	        return true;
	    if(ratMaze(b, r, c+1, n, s))
	        return true;
	   s[r][c] = 0;
	   return false;
	}
 
	return false;
}
int main(){
	int n;
	cout << "enter the value of n\n";
	cin >> n;
	int i, j;
	int b[100][100] = {0};
	int s[100][100] = {0};
	cout << "enter the values row-wise\n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin >> b[i][j];
	if(!ratMaze(b, 0, 0, n, s) ){
		cout << "solution does not exist\n";
	}
 else
 print(s, n);
	return 0;
}