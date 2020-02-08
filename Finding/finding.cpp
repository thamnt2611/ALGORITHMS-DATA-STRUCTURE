#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 7
int A[N+1];
void genData(char* filename){
	FILE* fp;
	fp=fopen(filename, "w");
	for (int i=1; i<=N; i++){
		int x= 1+rand()%(2*N);
		fprintf(fp, "%d ", x);
	}
	fclose(fp);
}

void readData(char* filename){
	FILE* fp;
	fp=fopen(filename, "r");
	for(int i=1; i<=N; i++){
		fscanf(fp, "%d ", &A[i]);
	}
	fclose(fp);
}

void printList(int A[]){
	for(int i=1; i<=N; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}
void swap(int *x, int *y){
	int tem;
	tem=*x;
	*x=*y;
	*y=tem;
}

void heapify(int A[], int i, int n){
	int L=2*i;
	int R=2*i+1;
	int max=i;
	if(L<=n && A[L]>A[max])	max=L;
	if(R<=n && A[R]>A[max]) max=R;
	if(max!=i) {
		swap(&A[i], &A[max]);
		heapify(A, max, n);
	}
}

void buildHeap(int A[], int n){
	for(int i=n/2; i>=1;i--){
		heapify(A, i, n);
	}
}

void heapSort(int A[], int n){
	buildHeap(A, n);
	for(int i=n; i>=1; i--){
		swap(&A[i], &A[1]);
		heapify(A, 1, i-1);
	}
}

int binarySearch(int A[], int b, int L, int R){
	if(L==R) return 0;
	if(L>R) return 0;
	int cnt;
	int mid=(L+R)/2;
	if (A[mid]==b) cnt+=binarySearch(A, b, L, mid-1)+ binarySearch(A, b, mid+1, R);
	else if (A[mid]<b) cnt+= binarySearch(A, b, L, mid+1);
	else cnt+= binarySearch(A, b, mid+1, R);
	return cnt;
}
// count the number of pairs (ai,aj) that have sum : b

// algo1 -- O(n2)
int algo1(int A[], int b, int n){
	int cnt=0;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(A[i]+A[j]==b) cnt++;
		}
	}
	return cnt;
}

//algo2--O(nlogn)1
int algo2(int A[], int b, int n){
	int cnt=0;
	for(int i=1; i<=n;i++){
		cnt+= binarySearch(A, b-A[i], i+1, n);
	}
	return cnt;
}

//algo3--O(n)
int algo3(int A[], int b, int n){
	int i=1; int j=n; int cnt=0;
	while(i<j){
		if(A[i]+A[j]==b){
			int cnti=1; int cntj=1;
			while(i<n && A[i+1]==A[i]){
				cnti++;
				i++;
			}
			while(j>1 &&A[j]==A[j-1]){
				cntj++;
				j--;
			}
			
		}
		
		if(i<j){
			cnt+=cnti*cntj;
			i++;
			j--;

		}
		else{
			cnt+=cnti*(cnti-1)/2;
			i++;
			j--;
		}
		
	}
	return cnt;
}
int main(){
//	genData("file_input1");
	readData("file_input1");
	printList(A);
	heapSort(A, N);
	printList(A);
	printf("%d\n", algo3(A, 8, N));
//	
}
