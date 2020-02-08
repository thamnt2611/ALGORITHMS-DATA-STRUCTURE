#include<stdio.h>
#include<conio.h>
#define N 7
int A[N+1];

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
	int L= 2*i;
	int R=2*i+1;
	int max=i;
	if (L<=n && A[L]>A[max]) {
		max=L;
	}
	if(R<=n && A[R]>A[max]){
		max=R;
	}
	if(max!=i){
		swap(&A[max], &A[i]);
		heapify(A, max, n);
	}
}

void buildHeap(int A[], int n){
	for(int i=n/2; i>=1; i--){
		heapify(A, i, n);
	}
}

void heapSort(int A[], int n){
	buildHeap(A, n);
	for(int i=n; i>=1; i--){
		swap(&A[1], &A[i]);
		heapify(A, 1, i-1);
	}
}

int binarySearch(int A[], int b, int L, int R){
	if(L<=R){
		int mid=(L+R)/2+1;
		if(A[mid]==b) return mid;
		if(A[mid]<b) return binarySearch(A, b, mid+1, R);
		return binarySearch(A, b, L, mid-1);
	}
}

int main(){
	readData("file_input1");
	printList(A);
	heapSort(A,N);
	printList(A);
	printf("%d ", binarySearch(A, 12, 1, N));
}
