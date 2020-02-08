#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* rightSibling;
	struct Node* leftMostChild;
};
Node* root=NULL;

Node* find(Node* r, int u){
	if(r==NULL) return NULL;
	if(r->data==u) return r;
	Node* q=r->leftMostChild;
	Node* p=NULL;
	while(q!=NULL){
		p= find(q, u);
		if(p!=NULL){
			break;
		}
		q=q->rightSibling;
	}
	return p;
}

Node* makeNode(int v){
	Node* p=(Node*)malloc(sizeof(Node));
	p->data=v;
	p->leftMostChild=NULL;
	p->rightSibling=NULL;
	return p;
}

Node* insertWrong(Node* r, int v, int u){  // cai loi sai ngu nguoi cai toi thich choi troi bien doi
	Node* q= find(r, u);
	if(q==NULL) {
		return r;
	}
	Node* p= makeNode(v);
	q=q->leftMostChild;   // khong noi duoc node parent voi node con-- 
	if (q==NULL) {		//neu q->leftMostChild==NULL--> q=NULL
		q=p;			// sau do q=p
	}
	else{
		while(q->rightSibling!=NULL){
			q=q->rightSibling;
		}
		q->rightSibling=p;
	}

	return r;
}
Node* insert(Node* r, int v, int u){
	Node* p= find(r, u);
	if(p==NULL) return r;
	if(p->leftMostChild==NULL) p->leftMostChild=makeNode(v);
	else{
		Node* q=p->leftMostChild;
		while(q->rightSibling!=NULL){
			q=q->rightSibling;
		}
		q->rightSibling=makeNode(v);
	}
	return r;
}


void printTree(Node* r){
	if(r==NULL) return;
	printf("%d:", r->data);
	Node* q=r->leftMostChild;
	while(q!=NULL){
		printf("%d ", q->data);
		q=q->rightSibling;
	}
	printf("\n");
	q=r->leftMostChild;
	while(q!=NULL){
		printTree(q);
		q=q->rightSibling;
	}
}

int countNode(Node* r){
	if(r==NULL) return 0;
	int cnt=1;
	Node* q=r->leftMostChild;
	while(q!=NULL){
		cnt+=countNode(q);
		q=q->rightSibling;
	}
	return cnt;
}

int countLeaves(Node* r){
	if(r==NULL) return 0;
	if(r->leftMostChild==NULL) return 1;
	int cnt=0;
	Node* q=r->leftMostChild;
	while(q!=NULL){
		cnt+=countLeaves(q);
		q=q->rightSibling;
	}
	return cnt;
}

int height(Node* r){
	if(r==NULL) return 0;
	Node* q=r->leftMostChild;
	int h=1;
	int max=0;
	while(q!=NULL){
		int t=height(q);
		if(t>max) max=t;
		q=q->rightSibling;
	}
	return h+max;
}

int depth(Node* r, int v){
	if(r==NULL) return 0;
	if(r->data==v) return 0;   
	Node* q=r->leftMostChild;
	int d=0;
//	if(q==NULL) return 0;
	while(q!=NULL){
		if(q->data==v){
			d=1;
			
		}
		else{
			d= 1+depth(q,v);
			q=q->rightSibling;
		}
	}
	
	return d;
}

void preOrder(Node* root){
	if(root==NULL) return;
	printf("%d ", root->data);
	Node* q=root->leftMostChild;
	while(q!=NULL){
		preOrder(q);
		q=q->rightSibling;
	}
}

void postOrder(Node* r){
	if(r==NULL) return;
//	if(r->leftMostChild==NULL){
//		printf("%d ", r->data);
//		return;
//	}
	postOrder(r->leftMostChild);
	printf("%d ", r->data);
	postOrder(r->rightSibling);
}


void inOrder(Node* r){
	if(r==NULL) return;
		
	Node* q= r->leftMostChild;
	inOrder(q);
	printf("%d ", r->data);
	if(q!=NULL) q=q->rightSibling;
	while(q!=NULL){
		inOrder(q);
		q=q->rightSibling;
	}

	
}

int main(){
	root = makeNode(10);
	root->leftMostChild= makeNode(11);
	root= insert(root, 1, 10);
	root= insert(root, 3, 10);
	root= insert(root, 5, 11);
	root= insert(root, 4, 11);
	root= insert(root, 6, 4);
	root= insert(root, 9, 4);
	root= insert(root, 8, 3);
	root= insert(root, 2, 3);
	root= insert(root, 7, 3);
	
	printTree(root);
	inOrder(root);
//	printf("%d ", find(root, 11)->data);
//	printf("\n %d", countNode(root));
//	printf("\n %d", countLeaves(root));
//	printf("\n %d", height(find(root, 11)));
	printf("\n %d", depth(root, 9));
}

