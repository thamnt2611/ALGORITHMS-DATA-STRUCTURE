   #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 7
int A[N+1][N+1];
int visited[N+1];
int truoc[N+1];	// truoc[v]:  vertice before v on the path
int d[N+1];		// distance between s--> cac dinh con lai

// generate data for graph
void genData(char* filename){
	FILE* fp=fopen(filename, "w");
	for(int i=1; i<=N; i++){
		for(int j=i; j<=N; j++){
			if (i==j) fprintf(fp, "%d ", 0);
			else{
				fprintf(fp, "%d ", 5+rand()%25);
			}
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}
//read data from file to make adjacent matrix
void readData(char* filename){
	FILE* fp= fopen(filename,"r");
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			fscanf(fp, "%d ",&A[i][j]);
			if(A[i][j]==0) A[i][j]=1000;
		}
	}
	fclose(fp);
}
// print adjacent matrix
void printGraphMatrix(int A[][N+1]){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%-5d", A[i][j]);
		}
		printf("\n");
	}
}

int findMin(int d[]){
	int min=1000000;
	int minIndex;
	for(int i=1; i<=N; i++){
		if (visited[i]==0 && d[i]<min){
			min=d[i];
			minIndex=i;
		}
	}
	return minIndex;
}

void PrimMST(int A[][N+1], int v){
	// initiation
	for(int i=1; i<=N; i++){
		d[i]=A[v][i];
		truoc[i]=v;
	}
	d[v]=0; truoc[v]=0;visited[v]=1;
	int k=2;
	while(k<=N){
		v=findMin(d);
		printf("%d--\n", v);
		visited[v]=1;
		k++;
		for(int u=1; u<=N; u++){
			if(visited[u]==0){
				if(d[u]>A[v][u]){
					d[u]=A[v][u];
					truoc[u]=v;
				}
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		printf("%d ",truoc[i]);
	}
	
}

int main(){
	readData("file_input_graph_1.txt");
	printGraphMatrix(A);
	PrimMST(A, 7);
	
}
