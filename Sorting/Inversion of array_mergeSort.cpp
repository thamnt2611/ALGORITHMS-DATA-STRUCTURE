#include <stdio.h>
int merge1(int A[], int l, int mid, int r){
    int cnt=0;
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
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			cnt+=n-i+1;
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
	
	return cnt;
}
int mergeSort(int A[], int l, int r){
	if(r>l){
		int mid= l+(r-l)/2;
		int lcnt= mergeSort(A,l, mid);
		int rcnt= mergeSort(A,mid+1, r);
		int mcnt= merge1(A, l, mid, r);
		return lcnt+rcnt+mcnt;
	}
	return 0;
}
int main() {
	//code
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
	    int N;
	    scanf("%d", &N);
	    int A[N+1];
	    for(int i=1; i<=N; i++){
	        scanf("%d", &A[i]);
	    }
	    printf("%d\n", mergeSort(A, 1, N));
	    
	}
	return 0;
}
