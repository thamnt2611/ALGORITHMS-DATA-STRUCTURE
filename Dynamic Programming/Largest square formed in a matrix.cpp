#include <stdio.h>
#include<stdlib.h>
int main() {
	//code
	int T,n, m;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
	    scanf("%d %d", &n, &m);
	    int* A=(int*)calloc(n*m, sizeof(int));
	    int cnt=0;
	    for(int x=0; x<n; x++){
	        for(int y=0; y<m; y++){
	            scanf("%d", (*(A+x)+y));
	            
	        }
	    }
	    for(int x=0; x<n; x++){
	        for(int y=0; y<m; y++){
	            printf("%d- ", *(*(A+x)+y));
	        }
	        printf("\n");
	    }
	    
	    int C[n][m];
	    int max=0;
	    for(int x=0; x<n; x++){
	        for(int y=0; y<m; y++){
	            if(A[x][y]==0) C[x][y]=0;
	            else{
	                if(x-1>=0&&y-1>=0){
	                    C[x][y]=(C[x][y-1]+C[x-1][y-1]+C[x-1][y])/3+1;
	                }
	                else{
	                    C[x][y]=1;
	                }
	            }
	            if(C[x][y]>max) max=C[x][y];
	        }
	    }
	    printf("%d\n", max);
	    free(A);
	}
	return 0;
}
