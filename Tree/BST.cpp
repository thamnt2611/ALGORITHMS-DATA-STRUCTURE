#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
	if(v<r->data){
		r->leftChild=insert(r->leftChild, v);
	}
	else if(v>r->data){
		r->rightChild=insert(r->rightChild, v);
	}
	else{
		if(r->leftChild==NULL){
			r->leftChild=insert(r->leftChild, v);
		}
		else if(r->leftChild==NULL){
			r->rightChild=insert(r->rightChild, v);
		}
		else{
			r->leftChild=insert(r->leftChild, v);
		}
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


Node* deleteNode(Node* r, int v){
	if(r==NULL) return NULL;
	if(v<r->data){
		r->leftChild=deleteNode(r->leftChild,v);
	}
	else if(v>r->data){
		r->rightChild=deleteNode(r->rightChild, v);
	}
	else{
		if(r->leftChild==NULL){
			Node* temp=r->rightChild;
			free(r);
			return temp;
		}
		else if(r->rightChild==NULL){
			Node* temp=r->leftChild;
			free(r);
			return temp;
		}
		else{
//			buoc xoa nut minNode
//			cach 1
//			Node* p= minNode(r->rightChild);
//			r->data=p->data;
//			r->rightChild=deleteNode(r->rightChild, p->data);


//			cach2
//			tim duoc minNode va parent cua no
			Node* min=r->rightChild;
			Node* minPar=r->rightChild;
			while(min->leftChild!=NULL){
				minPar=min;
				min=min->leftChild;
			}
			r->data=min->data;
			minPar->leftChild=min->rightChild;
			free(min);
			
			return r;
		}
	}

}
//Find maximum count of duplicate nodes in a Binary Search Tree
//use inorder
int countDouble(Node* r, int* cnt){
}



int main(){
//	root=insert(root,50);
//	root=insert(root,30);
//	root=insert(root,70);
//	root=insert(root,20);
//	root=insert(root,40);
//	root=insert(root,60);
//	root=insert(root,80);
//	inOrder(root);
//	printf("\n");
//	NthInOrder(root, 4);
//	printf("\n");
//	postOrder(root);
//	printf("\n");
//	preOrder(root);
//	printf("\n");
	
//	printf("%d %d\n", find(root, 70)->leftChild->data, find(root, 70)->rightChild->data);
//	printf("%d\n", minNode(root)->data);
//	printf("\n");
//	inOrder(deleteNode(root, 50));
	
	root=insert(root,6);
	root=insert(root,5);
	root=insert(root,4);
	root=insert(root,5);
	root=insert(root,7);
	root=insert(root,7);
	root=insert(root,7);
	inOrder(root);
	printf("\n");
	int cnt=0;
	printf("%d\n", countDouble(root,&cnt));
}
