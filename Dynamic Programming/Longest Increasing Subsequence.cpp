#include<stdio.h>
#define N 9
int A[N];
int i;
FILE* fp;

void genData(char* filename){
	fp=fopen(filename, "w");
	for(i=0; i<N; i++){
		fprintf(fp,"%d ", 1 + rand()%20);
	}
	fclose(fp);
}
void readData(char* filename){
	fp=fopen(filename, "r");
	for (i=0; i<N; i++){
		fscanf(fp, "%d ", &A[i]);
	}
	fclose(fp);
}

void printSeq(){
	for (i=0; i<N; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}
void printMatrix(int A[], int n){
	for (i=0; i<n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

int LIS(int A[], int n){
	int L[n];
	L[0]=1;
	int M[n];// M[i] stores index of previous item in longest increasing seq
	M[0]=-1;
	int longest=0;
	int end;
	for(int i=1; i<n; i++){
		int j=i-1;
		int max=0;
	
		while(j>=0){
			if(A[j]<A[i]){
				if(L[j]>max){
					max=L[j];
					M[i]=j;
				} 
			}
			j--;
		}
		L[i]=max+1;
		if(L[i]>longest){
			longest=L[i];
			end=i;
		} 
	}
	int i=end;
	while(i>=0){
		printf("%d ", A[i]);
		i=M[i];
	}
	return longest;
}

int main(){
//	genData("Seq_input.txt");
	readData("Seq_input.txt");
	printSeq();
	printf("%d \n", LIS(A, N));
}
