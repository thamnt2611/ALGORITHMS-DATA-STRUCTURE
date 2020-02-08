#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
	struct Node* next;
};
Node* root=NULL;
Node* makeNode(int v){
	Node* p=(Node*)malloc(sizeof(Node));
	p->data=v;
	p->leftChild=NULL;
	p->rightChild=NULL;
	p->next=NULL;
}
Node* top;

Node* pop(){
	Node* p= top;
	top=top->next;
	p->next=NULL;
	return p;
}

int isStackEmpty(){
	if(top==NULL) return 1;
	return 0;
}

void push(Node* p){
	if(top==NULL){
		top=p;
	}
	else{
		p->next=top;
		top=p;
	}
}

Node* constructTreeUsingStack(int pre[], int size){
	int i=0;
	root=makeNode(pre[i]);
	push(root); i++;
	while(i<size){
		if(pre[i]<top->data){
			Node* p=makeNode(pre[i]);
			top->leftChild=p;
			push(p);
			
		}
		else{
			Node* q;
			
			while(!isStackEmpty()){
				if(top->data>pre[i]) break;
				q= pop();
//				printf("aa");
			}
			Node* p=makeNode(pre[i]);
			q->rightChild=p;
			push(p);
		}
		i++;
	}
	return root;
}


//O(n) : su dung khoang gioi han
Node* constructTreeUtil(int pre[], int max, int min, int *preIndex, int key, int size){
	// (max...min) : khoang ma key thuoc vao
	// *preIndex: chua index khi duyet het pre[]

	if(*preIndex>size) return NULL;
	Node* r=NULL;
	if(key>min&&key<max){
		r=makeNode(key);
		*preIndex=*preIndex+1;
		
		if(*preIndex<size){
			r->leftChild=constructTreeUtil(pre, key, min, preIndex, pre[*preIndex], size);
			
			r->rightChild=constructTreeUtil(pre, max, key, preIndex, pre[*preIndex], size);
		}
	}
	return r;
}

Node* constructTree(int pre[], int size){
	int preIndex=0;
	return constructTreeUtil(pre, INT_MAX, INT_MIN, &preIndex, pre[0], size);
}




void inOrder(Node* r){
	if(r!=NULL){
		inOrder(r->leftChild);
		printf("%d ", r->data);
		inOrder(r->rightChild);
	}
}


// construct AVL tree from sorted array
Node* constructAVL(int A[], int L, int R){
	if(R<L) return NULL;
	int mid=L+(R-L)/2;
	Node* r=makeNode(A[mid]);
	r->leftChild=constructAVL(A, L, mid-1);
	r->rightChild=constructAVL(A, mid+1, R);
//	printf("%d ", r->data);
	return r;
}


int main(){
	int pre[7]={50, 30, 20, 40, 70, 60, 80};
	int A[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	Node* root=constructTree(pre, 7);
//	inOrder(root);
//	root= constructTreeUsingStack(pre, 7);
	root=constructAVL(A, 0, 9);
	inOrder(root);
}
