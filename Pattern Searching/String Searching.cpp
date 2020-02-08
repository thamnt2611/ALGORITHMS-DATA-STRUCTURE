#include<stdio.h>
#include<string.h>
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
	for(int j=strlen(P)-1; j>=0; j--){
		int a= P[j];
		if(last[a]==0) last[a]=j;
	}
}
void BoyerMoore(char* T, int m, char* P, int n){
	computeLast(P);
	int s=0;
	while(s<=m-n){  
		int i=n-1;
		while(i>=0&& T[i+s]==P[i]){
			i--;
		}
		if(i==-1){
			// found string
			printf("%d\n", s);
			s++;// tim duoc thi s van dich de tim tiep
		}
		else{
			int a=T[i+s];// ma ascii cua bad character
			s=s+max(i-last[a], 1);
			// suitable for 3 cases:
			//- last[a]>i: s=s+1
			//- last[a]<i: s=s+i-last[a]
			//- last[a]=0(bad character not in P): s=s+i;
		}
	}
}
//NAIVE SEARCH  
void NaiveSM(char* T, int m, char* P, int n){
	for(int s=0; s<=m-n; s++){
		int i=s;
		do{
			i++;
		}while(i<s+n && P[i-s]==T[i]);
		if(i==s+n) printf("%d\n", s); 
	}
}

//RABIN KARP  average & best case O(n+m)
			//worst case O(m+n)  t"AAAAAAAA" p"AA"
void RabinKarp(char* T, int m, char* P, int n, int q){
	int t=0; // hash value of n continuous characters in T
	int p=0; // hash value of P
	int h=1; 
	int d=256; // so luong ky tu
	for(int i=0; i<n; i++){
		t= (d*t+ T[i])%q;
		p= (d*p+ P[i])%q;
	}
	// h= pow(d, n-1)% q
	for(int i=1; i<n; i++){
		h=(h*d)%q;
	}
	
	for(int s=0; s<=m-n; s++){
		printf("%d %d\n", t, p);
		if(t==p){
			int i=0;
			while(i<n){
				if(T[i+s]!=P[i]){
					break;
				}
				i++;
			}
			if(i==n){
				printf("Pattern found at index %d\n", s);
			}
		}
		// not transfer when s==m-n
		if(s<m-n){
			t=(d*(t-T[s]*h)+ T[s+n])%q;
			// simple like:
			//t=234567	p=234	d=10	q=infinite
			//first t= 234  h=100
			//b2: t=10(234-2*100)+ 5= 345
			
		}
		// in case t<0
		if(t<0){
			t=t+q;
		}
	}
}





int main(){
//	NaiveSM(T, strlen(T), P, strlen(P));
//	BoyerMoore(T, strlen(T), P, strlen(P));
	int q= 101; // a prime number
	RabinKarp(T, strlen(T), P, strlen(P), q);
}
