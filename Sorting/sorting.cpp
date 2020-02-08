#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 10
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
void printMatrix(int A[], int n){
	for (i=0; i<n; i++){
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
// INSERTION SORT
void insertionSort(int A[], int n){
	int k;
	for (k=2; k<=N; k++){
		int j=k;
		int last = A[k];
		while (j>=1 && last< A[j-1]){
//			swap(&A[j], &A[j-1]);
//			j--;
			A[j]=A[j-1];
			j--;
		}
		A[j]=last;
	}
}
// SELECTION SORT
void selectionSort(int A[], int n){
	for(i=1; i<=n; i++){
		int min=10000000;
		int minIndex;
		int j;
		for(j=i; j<=n; j++){
			if (A[j]<min){
				min =A[j];
				minIndex=j;
			}
		}
		swap(&A[i], &A[minIndex]);
	}
}
// BUBBLE SORT
void bubbleSortSlow(int A[], int n){
	for (i=1; i<=n; i++){
		for(int j=1; j<=n-i; j++){
			if(A[j]>A[j+1]){
				swap(&A[j], &A[j+1]);
			}
		}
	}
}
void bubbleSortOptimal(int A[], int n){
	int swapped;
	for (i=1; i<=n; i++){
		swapped=0;
		for(int j=1; j<=n-i; j++){
			if(A[j]>A[j+1]){
				swap(&A[j], &A[j+1]);
				swapped=1;
			}
		}
		if(swapped==0) break;
	}
}
// HEAP SORT
void heapify(int A[], int i, int n){
	int L=2*i;
	int R=2*i+1;
	int max=i;
	if(L<=n && A[L]>A[i]) max=L;		//L, R phai nho hon n vi co the co nut chi co mot nut con
	if(R<=n && A[R]>A[max]) max=R;
	if(max!=i){
		swap(&A[i], &A[max]);
		heapify(A, max, n);
	}
}

void buildHeap(int A[], int n){
	for(int i=N/2; i>=1; i--){		//moi cai i deu phai khai bao cuc bo
		heapify(A, i, n);			//nhung bien nhu i tu nay nho phai cuc bo
	}
	
}
void heapSort(int A[], int n){
	buildHeap(A, n);
	for(int i=N; i>1; i--){
		swap(&A[1], &A[i]);
		heapify(A, 1, i-1);
		printSeq();
		printf("\n");
	}
}
//QUICK SORT
int partition(int A[], int L, int R, int indexPivot){
	// value is used to be pivot
	int pivot= A[indexPivot];
	
	// A: ----------pivot
	swap(&A[indexPivot], &A[R]);
	int storeIndex=L;
	
	//A: A[storeIndex]---------pivot
	for (int i=L; i<=R-1; i++){
		if(A[i]<pivot){
			swap(&A[i], &A[storeIndex]);
			storeIndex++;
		}
	}
	//lap den day thi tu L-> storeIndex: A[i]<pivot
	// A: --(<pivot)--A[storeIndex]--(>pivot)--pivot
	swap(&A[storeIndex], &A[R]);
	// to this the sequence will be like : <<<<A[storeIndex]=pivot<<<<<<
	
	return storeIndex;
}

void quickSort(int A[], int L, int R){
	if(L<R){
		
		int index = (L+R)/2;
		index = partition(A, L, R, index);
		if (index>L){
			quickSort(A, L, index-1);
		}
		if (index<R){
			quickSort(A, index+1, R);
		}
		
		
	}
}

// MERGE SORT
// merge cach 1
void merge1(int A[], int l, int m, int r){
	// merge A after divide from l-->r
	int i, j, k;
	int n1=m-l+1;// so phan tu ben trai
	int n2=r-m;// so phan tu ben phai
	// do A co first index==1 nen cho L, R cung nhu vay
	int L[n1+1], R[n2+1]; 
	// copy data to temp arrays
	for(i=1; i<=n1; i++){
		L[i]=A[l+i-1];
	}
	for(j=1; j<=n2; j++){
		R[j]=A[m+j];
	}
	// merge temp arrays
	i=1;// first index of L[]
	j=1;// first index of L[]
	k=l;//first index of A[]
	while(i<=n1 && j<=n2){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	// copy the remaining of L or R if there are any
	while(j<=n2){
		A[k]=R[j];
		j++;
		k++;
	}

	while(i<=n1){
		A[k]=L[i];
		i++;
		k++;
	}
}

// merge cach 2
void merge2(int A[], int l, int mid, int r){
	int TA[N];
	int i=l;
	int j=mid+1;
	for(int k=l; k<=r; k++){
		if(i>mid){
			TA[k]=A[j];
			j++;
		}
		else if(j>r){
			TA[k]=A[i];
			i++;
		}
		else{
			if(A[i]<=A[j]){
				TA[k]=A[i];
				i++;
			}
			else{
				TA[k]=A[j];
				j++;
			}
		}
	}
	for(int i=l; i<=r; i++){
		A[i]=TA[i];
	}
	
	
}

void mergeSort(int A[], int l, int r){
	if (r>l){
		//same as (l+r)/2 but avoids overflow for large l+r
		int mid=l+(r-l)/2;
		mergeSort(A, l, mid);
		mergeSort(A, mid+1, r);
		merge2(A, l, mid, r);
	}
}
int main(){
	genData("file_input1");
	readData("file_input1");
	printSeq();
	mergeSort(A, 1, N);
	printf("\n");
	printSeq();
}



//  find the difference
//  heapify wrong


//void heapify(int A[], int i, int n){
//	int L=2*i;
//	int R=2*i+1;
//	int max=i;
//	if(L<=n && A[L]>A[i]) max=L;
//	if(R<=n && A[R]>A[max]) max=R;
//	if(max!=i){
//		swap(&A[i], &A[max]);
//		heapify(A, max, n);
//	}
//}
//
//void buildHeap(int A[], int n){
//	for(i=N/2; i>=1; i--){
//		heapify(A, i, n);
//	}
//	
//}
//void heapSort(int A[], int n){
//	buildHeap(A, n);
//	for(i=N; i>1; i--){
//		swap(&A[1], &A[i]);
//		heapify(A, 1, i-1);
//		printSeq();
//		printf("\n");
//	}
//}
