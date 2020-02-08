#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<queue> 
  
using namespace std; 
#define N 6
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
		}
	}
	fclose(fp);
}
// print adjacent matrix
void printGraphMatrix(int A[][N+1]){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}


// BFS traversal: print vertices base on BFS
void BFS(int A[][N+1], int v){
	visited[v]=1;
	queue<int> Q;
	Q.push(v);
	while (!Q.empty()){
		v=Q.front(); Q.pop();
		printf("%d ", v);
		
		for(int i=1; i<=N; i++){
			if(A[v][i]!=0 && visited[i]!=1){
				visited[i]=1;
				Q.push(i);
			}
		}
	}
}

int BFSshortestPath(int A[][N+1], int u, int v){
	if(u==v) return 0;
	queue<int> Q;
	Q.push(u); visited[u]=1;
	truoc[u]=0;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		if(k==v){
			int d=0;
			while(truoc[k]!=0){
				d++;
				k=truoc[k];
			}
			return d;
		}
		for(int i=1; i<=N; i++){
			if(A[k][i]!=0&& visited[i]==0){
				visited[i]=1;
				truoc[i]=k;
				Q.push(i);
			}
		}
	}
	return -1;
}

//DFS traversal: print vertices base on DFS
void DFS(int A[][N+1], int v){
	visited[v]=1;
//	printf("%d ",v);   // in ra qua trinh duyet
	for(int i=1; i<=N; i++){
		if(A[v][i]!=0 && visited[i]==0){
			truoc[i]=v;
			DFS(A, i);
		}
	}
	visited[v]=2;	
}
// check whether graph is continuous
int checkContinuous(int A[][N+1]){
	int cnt=0;
	for(int i=1; i<=N; i++){
		if(visited[i]==0){
			cnt++;
			if (cnt==2){
				return 0;
			}
			DFS(A, i);
		}
	}
	return 1;
}
// print thanh phan lien thong cua do thi
void printContinuous(int A[][N+1]){
	int cnt=0;
	for(int i=1; i<=N; i++){
		if(visited[i]==0){
			cnt++;
			printf("tplt-%d: ",cnt);
			DFS(A, i);
			printf("\n");
		}
	}
}
//find whether or not exist the path from s->t in the graph
void findPath_s_t(int A[][N+1], int s, int t){
	truoc[s]=0;
	DFS(A, s);
	printf("\n");	
	if(truoc[t]==0){
		printf("No path");
	}
	else{
		while(t!=0){
			printf("%d ",t);
			t=truoc[t];
		}
	}
}
//check the graph whether have cycle
int found=0;
void DFSforFindCycle(int v){
		visited[v]=1;
		printf("%d ", v);
		for(int i=1; i<=N; i++){
			if(A[v][i]!=0 && visited[i]==0){
				truoc[i]=v;
				DFSforFindCycle(i);
			}
			else if(i!= truoc[v]&&A[v][i]!=0 && visited[i]==1){
				printf("\n have cycle");
				found=1;
				break;
			}
		}
		visited[v]=2;
	}

int findCycle(int A[][N+1]){
	for(int i=1; i<=N; i++){
		if(visited[i]==0){
			DFSforFindCycle(i);
		}
	}
	return found;
}
void renewVisited(){
	for(int i=1; i<=N; i++){
		visited[i]=0;
	}
}
void DFSforOrientGraph(int A[][N+1], int v){
	visited[v]=1;
	for(int i=1; i<=N; i++){
		if(visited[i]==0 && A[v][i]!=0){
			truoc[i]=v;
			A[v][i]=2;
			DFSforOrientGraph(A, i);
		}
	}
	visited[v]=2;
}

void orientGraph(int A[][N+1]){
	if (checkContinuous(A)==0) printf("khong dinh huong duoc\n");
	else{
		renewVisited();
		for(int v=1; v<=N; v++){
			if(visited[v]==0){
				DFSforOrientGraph(A, v);
			} 
			
		}
		for(int i=1; i<=N; i++){
			for(int j=i; j<=N; j++){
				if(A[i][j]==2) printf("%d-->%d\n",i, j);
				else if(A[i][j]==1) printf("%d-->%d\n", j, i);
			}
		}	
	}
}


int main(){
	//genData("file_input_graph");
	readData("file_input_graph");
	printGraphMatrix(A);
//	BFS(A, 1);
//	renewVisited();
	printf("%d ",BFSshortestPath(A, 1,6));
//	printf("%d", checkContinuous(A));
//	findPath_s_t(A, 1,6);
//	printf("%d",findCycle(A));
//	orientGraph(A);
}
