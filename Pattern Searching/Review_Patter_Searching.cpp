#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100

char T[]="bacababaaba";
char P[]="aba";  
//BOYER MOORE    best case O(m/n)
			// worst case O(mn)
int max(int a, int b){
	if (a>=b) return a;
	return b;
}
// the highest index of each character in P
int last[256];
void computeLast(char* P){
	for(int i=strlen(P)-1; i>=0; i--){
		int a=P[i];
		if(last[a]==0) last[a]=i;
//		printf("%d ", last[a]);
	}
}
void BoyerMoore(char* T, int m, char* P, int n){
	computeLast(P);
	int i=0;
	while(i<=m-n){
//		printf("%d ", i);
		int j=n-1;
		while(P[j]==T[i+j]){
//			printf("%d ", j);
			j--;
			
		}
		if(j==-1) printf("Pattern found at index %d\n", i);
		int a=T[i+j];
		i=i+max(1, j-last[a]);
//			printf("%d ", max(1, j-last[a]));
	}
}
//NAIVE SEARCH  
void NaiveSearch(char* T,int m, char* P, int n){
	for(int i=0; i<=m-n; i++){
		int j;
		for(j=0; j<n; j++){
			if(P[j]!=T[i+j]) break;
		}
		if(j==n) printf("Pattern found at index %d\n", i);
	}
}

//RABIN KARP  average & best case O(n+m)
			//worst case O(m+n)  t"AAAAAAAA" p"AA"
void RabinKarp(char* T, int m, char* P, int n, int q){
	int dp=0;
	int dt=0;
	int d=256;
	for(int j=0; j<n; j++){
		dp=(dp*d+P[j])%q;
		dt=(dt*d+T[j])%q;
	}
	// h= pow(d, n-1)% q
	int h=1;
	for(int i=1; i<n; i++){
		h=(h*d)%q;
	}
	for(int i=0; i<=m-n; i++){
		printf("%d %d\n", dt, dp);
		if(dt==dp){
			int j;
			for(j=0; j<n; j++){
				if(T[i+j]!=P[j]) break;
			}
			if(j==n) printf("Pattern found at index %d\n", i);
		}
		if(i<m-n){
			dt=(d*(dt-T[i]*h)+T[i+n])%q;
		}
		if(dt<0){
			dt+=q;
		}
	}
}





int main(){
//	NaiveSearch(T, strlen(T), P, strlen(P));
//	BoyerMoore(T, strlen(T), P, strlen(P));
	int q= 101; // a prime number
	RabinKarp(T, strlen(T), P, strlen(P), q);
}
