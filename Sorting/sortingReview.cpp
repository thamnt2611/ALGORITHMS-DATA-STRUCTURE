#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 7
int A[N+1];
int i;
FILE* fp;

void genData(char* filename){
	fp=fopen(filename, "w");
	for(i=1; i<=N; i++){
		fprintf(fp,"%d ", 1 + rand()%20);
	}
	fclose(fp);
}
void readData(char* filename){
	fp=fopen(filename, "r");
	for (i=1; i<=N; i++){
		fscanf(fp, "%d ", &A[i]);
	}
	fclose(fp);
}

void printSeq(){
	for (i=1; i<=N; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}
void printArray(int A[], int n){
	for (i=1; i<=n; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

void swap( int* x, int* y){   // de hoan doi gia tri cac phan tu trong mang 
	int tem;				// thi can phai dung toi con tro--> quan trong
	tem= *x;
	*x=*y;
	*y=tem;
}

//QUICK SORT
int partition(int A[], int l, int r, int indexPivot){
	int pivot=A[indexPivot];
	swap(&A[indexPivot], &A[r]);
	int storeIndex=l;
	for(int i=l; i<r; i++){
		if(A[i]<pivot){
			swap(&A[i], &A[storeIndex]);
			storeIndex++;
		}
	}
	swap(&A[r], &A[storeIndex]);
	return storeIndex;
}

void quickSort(int A[], int l, int r){
	if(r>l){
		int index=l+(r-l)/2;
		index=partition(A, l, r, index);
		if(index>l){
			quickSort(A, l, index-1);
		}
		if(index<r){
			quickSort(A, index+1, r);
		}
	}
}

//INSERTION SORT
void insertionSort(int A[], int n){
	for(int i=2; i<=n; i++){
		int j=i-1;
		int last=A[i];
		while(A[j]>last&&j>0){
//			printf("%d ", A[j]);
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=last;
		printArray(A, n);
	}
}
// SELECTION SORT
void selectionSort(int A[], int n){
	for(int i=1; i<=n; i++){
		int minIndex=i;
		for(int j=i; j<=n; j++){
			if(A[j]<A[minIndex]){
				minIndex=j;
			}
		}
		swap(&A[i], &A[minIndex]);
	}
}
// MERGE SORT
// merge cach 1
void merge1(int A[], int l, int mid, int r){
	int n=mid-l+1; int m=r-mid;
	int L[n+1];
	int R[m+1];
	for(int i=1; i<=n; i++){
		L[i]=A[l+i-1];
	}
	for(int i=1; i<=m; i++){
		R[i]=A[i+mid];
	}
	int i=1;
	int j=1;
	int k=l;
	while(i<=n&&j<=m){
		if(L[i]<R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<=n){
		A[k]=L[i];
		i++; k++;
	}
	while(j<=m){
		A[k]=R[j];
		j++; k++;
	}
	
}
// merge cach 2
void merge2(int A[], int l, int mid, int r){
	int n= r-l+1;
	int T[n];
	int i=l; int j=mid+1; int k=0;
	while(i<=mid&&j<=r){
		if(A[i]<A[j]){
			T[k]=A[i];
			i++;
		}
		else{
			T[k]=A[j];
			j++;
		}
		k++;
	}
	while(i<=mid){
		T[k]=A[i];
		i++; k++;
	}
	while(j<=r){
		T[k]=A[j];
		j++; k++;
	}
	for(int i=l; i<=r; i++){
		A[i]=T[i-l];
	}
}

void mergeSort(int A[], int l, int r){
	if(r>l){
		int mid= l+(r-l)/2;
		mergeSort(A,l, mid);
		mergeSort(A,mid+1, r);
		merge2(A, l, mid, r);
	}
}
//HEAP SORT
void heapify(int A[], int i, int n){
	int L=2*i;
	int R=2*i+1;
	int max=i;
	if(L<=n &&A[L]>A[max]){
		max=L;
	}
	if(R<=n&& A[R]>A[max]){
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
		swap(&A[i], &A[1]);
		heapify(A, 1, i-1);
	}
}


void swapArray(int B[], int n){
	int storeIndex=0;
	for(int i=0; i<n; i++){
		if(B[i]<0){
			swap(&B[i], &B[storeIndex]);
			storeIndex++;
		}
	}
}

int main(){
//	genData("file_input1");
	readData("file_input1");
	printSeq();
	quickSort(A, 1, N);
	printSeq();
//	int B[5]={-1, 2, 4, -8, 0};
//	printArray(B, 5);
//	swapArray(B, 5);
//	printArray(B, 5);

}
