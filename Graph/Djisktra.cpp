#include<bits/stdc++.h>
#include <iostream> 
#include <utility>
#include<stdio.h>
using namespace std;
int n, m;
void addEdge(vector<pair<int,int> > adj[], int u, int v, int wt){
	adj[u].push_back(make_pair(v, wt));
	
}

void loadData(char* filename, vector<pair<int,int> > adj[]){
	FILE* fp=fopen(filename, "r");
	fscanf(fp, "%d %d ", &n, &m);
	printf("%d %d \n", n, m);
	int u, v, wt;
	for(int i=1; i<=m; i++){
		fscanf(fp, "%d ", &u);
		fscanf(fp, "%d ", &v);
		fscanf(fp, "%d ", &wt);
		printf("%d %d %d\n", u, v, wt);
		addEdge(adj, u, v, wt);
	}
	fclose(fp);
}

//void printGraph(vector<pair<int,int> > adj[]){
//	for(int u=1; u<=n; u++){
//		int v, w;
//		cout << "Node " << u << "makes an edge with\n";
//		
//		for(auto it = adj[u].begin(); it!= adj[u].end(); it++){
//			
//			v=it->first;
//			w=it->second;
//			cout <<"\tNode " << v << " with edge weight = " << w <<"\n";
//		}
//		cout << "\n";
//		
//	}
//}


int main(){
	vector<pair<int,int> > adj[n];
	loadData("file_input_graph.txt", adj);
//	printGraph(adj);
}
