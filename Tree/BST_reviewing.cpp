#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <bits/stdc++.h> 
using namespace std;
typedef struct Node{
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
};
Node* root=NULL;
Node* makeNode(int v){
	Node* p=(Node*)malloc(sizeof(Node));
	p->data=v;
	p->leftChild=NULL;
	p->rightChild=NULL;
}

Node* insert(Node* r, int v){
	Node* p=makeNode(v);
	if(r==NULL) return p;
	if(v<=r->data){
		r->leftChild=insert(r->leftChild, v);
	}
	else{
		r->rightChild=insert(r->rightChild, v);
	}
	return r;
}

void inOrder(Node* r){
	if(r!=NULL){
		inOrder(r->leftChild);
		printf("%d ", r->data);
		inOrder(r->rightChild);
	}
}

void NthInOrder(Node* r, int n){
	static int cnt=0;  // works as a global variable
	if(r==NULL) return;
	if(cnt<=n){
		NthInOrder(r->leftChild, n);
		cnt++;
		if(cnt==n) printf("%d ", r->data);
		NthInOrder(r->rightChild,n);
	}
}

void postOrder(Node* r){
	if(r==NULL) return;
	postOrder(r->leftChild);
	postOrder(r->rightChild);
	printf("%d ", r->data);
}

void preOrder(Node* r){
	if(r==NULL) return;
	printf("%d ", r->data);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}
Node* find(Node* r, int v){
	if(r->data==v|| r==NULL)
		return r;
	if(r->data<v) 
		return find(r->rightChild, v);
	if(r->data>v) 
		return find(r->leftChild, v);
}

Node* minNode(Node* r){
	if(r==NULL) return NULL;
	if(r->leftChild==NULL) return r;
	return minNode(r->leftChild);
}


int countLeaves(Node* r){
	if(r==NULL) return 0;
	if(r->leftChild==NULL&&r->rightChild==NULL) return 1;
	int cleft= countLeaves(r->leftChild);
	int cright=countLeaves(r->rightChild);
	return cleft+cright;
}
// print leaves not using recursive
void printLeaves(Node* r){
	stack<Node*> s;
	s.push(r);
	while(!s.empty()){
		while(s.top()->leftChild!=NULL){
			s.push(s.top()->leftChild);
		}
		Node* p=s.top();
		s.pop();
		if(p->leftChild==NULL && p->rightChild==NULL){
			printf("%d ", p->data);
			
			if(!s.empty()){
				Node* q=s.top();
				s.pop();
				if(q->rightChild!=NULL){
					s.push(q->rightChild);
				}	
			}
		}
		else{
			s.push(p->rightChild);
		}
		
	}
}

Node* minNode(Node* r){
	if(r==NULL) return NULL;
	if(r->leftChild==NULL) return r;
	Node* p=r->leftChild;
	while(p!=NULL){
		p=p->leftChild;
	}
	return p;
}

Node* deleteNode(Node* r, int v){
	if(r==NULL) return NULL;
	if(v<r->data){
		r->leftChild= deleteNode(r->leftChild);
	}
	else if(v>r->data){
		r->rightChild= deleteNode(r->rightChild);
	}
	else{
		if(r->leftChild==NULL){
			Node* p=r->rightChild;
			free(r);
			return p;
		}
		if(r->rightChild==NULL){
			Node* p=r->leftChild;
			free(r);
			return p;
		}
		
		Node* p=minNode(r->rightChild);
		r->data=p->data;
		r->rightChild=deleteNode(r->rightChild, p->data);
		
	}
}     



int main(){
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,70);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,26);
	root=insert(root,40);
	root=insert(root,60);
	root=insert(root,90);
	root=insert(root,80);
	root=insert(root,100);
	inOrder(root);
	printf("\n");
	int numLeaves= countLeaves(root);
	printf("%d\n", numLeaves);
	printLeaves(root);
	

}
