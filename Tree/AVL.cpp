#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int key;
	int height;
	struct Node* left;
	struct Node* right;
};

Node* makeNode(int v){
	Node* p=(Node*)malloc(sizeof(Node));
	p->key=v;
	p->height=1;
	p->left=NULL;
	p->right=NULL;
	return p;
}
int height(Node* r){
	if(r==NULL) return 0;
	return r->height;
}
void preOrder(Node* r){
	if(r==NULL) return;
	printf("%d ", r->key);
	preOrder(r->left);
	preOrder(r->right);
	printf("\n");
}

int max(int a, int b){
	return (a>b)? a:b;
}
//xoay kieu nay:
//	y			x
//	 \		   / \
//	  x  -->  y  ..
//	 / \	   \
//	T2	..	   T2
Node* leftRotate(Node* y){
	Node* x= y->right;
	Node* T2=x->left;
	
	x->left=y;
	y->right=T2;
	
	y->height=max(height(y->left), height(y->right))+1;
	x->height=max(height(x->left), x->right->height)+1;
	return x;
}


Node* rightRotate(Node* y){
	Node* x=y->left;
	Node* T2=x->right;
	
	x->right=y;
	y->left=T2;
	
	y->height=max(height(y->left), height(y->right))+1;
	x->height=max(height(x->left), height(x->right))+1;
	return x;
}

int getBalance(Node* x){
	if(x==NULL) return 0;
	return height(x->left) - height(x->right);
}

Node* insert(Node* r, int v){
	
	if(r==NULL){
		Node* p= makeNode(v);
		return p;
	}
	if(r->key > v){
		r->left=insert(r->left, v);
	}
	else if(r->key < v){
		r->right=insert(r->right, v);
	}
	else{
		return r;
	}
	
	r->height=1+max(height(r->left), height(r->right));
	int balance=getBalance(r);
	//left left case
	if(balance>1 && v<r->left->key){
		return rightRotate(r);
	}
	// left right case
	if(balance>1 && v>r->left->key){
		r->left=leftRotate(r->left);
		return rightRotate(r);
	}
	// right right case
	if(balance<-1&& v>r->right->key){
		return leftRotate(r);
	}
	// right left case
	if(balance<-1&& v<r->right->key){
		r->right= rightRotate(r->right);
		return leftRotate(r);
	}
	return r;
}



int main(){
	struct Node* root=NULL;
	root= insert(root, 31);
	root= insert(root, 19);
	root= insert(root, 24);
	root= insert(root, 12);
	root= insert(root, 17);
	root= insert(root, 25);
	root= insert(root, 35);
	root= insert(root, 37);
	root= insert(root, 14);
	preOrder(root);
}
