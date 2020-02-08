#include<stdio.h>
#include<conio.h>

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int LCS(char* X, int m, char* Y, int n){
	char L[m+1][n+1];
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i==0||j==0) L[i][j]=0;
			else{
				if(X[i-1]==Y[j-1]) L[i][j]=L[i-1][j-1]+1;
				else{
					L[i][j]=max(L[i-1][j], L[i][j-1]);
				}
			}
		}
	}
	return L[m][n];
}

int main(){
	
}
