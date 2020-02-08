#include<stdio.h>
#include<stdlib.h>
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



int isSubsetSum(int A[], int n, int sum){
	if(sum==0) return 1;
	if(sum<0) return 0;
	if(n<0&&sum>0) return 0; 
	return isSubsetSum(A, n-1, sum)||isSubsetSum(A, n-1, sum-A[n-1]);
}

int maxSizeSumSet(int A[], int n, int sum){
	if(sum==0) return 0;
	if(n<0 && sum!=0) return -1;
	int a=maxSizeSumSet(A, n-1, sum-A[n-1]);
	int b=maxSizeSumSet(A, n-1, sum);
	printf("%d %d\n", a, b);
	if(a==-1&& b==-1){
		return -1;
	}
	else{
		if(a>b){
			return 1+a;
		}
		return b;
	}
}

int main(){
//	readData("Seq_input.txt");
//	printSeq();
//	if(isSubsetSum(A, N, 13)){
//		printf("It has!");
//	}
//	else{
//		printf(" It doesn't have!\n");
//	}
	int A[6]={2, 3, 5, 7, 10, 15};
	printf("%d ", maxSizeSumSet(A, 6, 10));
}
