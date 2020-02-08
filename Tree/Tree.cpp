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
	if (r==NULL) return NULL;
	if(r->data==u) return r;
	else{
		Node* p= r->leftMostChild;
		while (p!=NULL){
			Node* q= find(p, u);
			if (q!=NULL) return q;
			p=p->rightSibling;
		}
		return NULL;
	}
	
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
	Node* q= find(r, u);
	if(q==NULL) {
		return r;
	}
	if (q->leftMostChild==NULL) {
		q->leftMostChild=makeNode(v);
	}
	else{
		Node* p=q->leftMostChild;
		while(p->rightSibling!=NULL){
			p=p->rightSibling;
		}
		p->rightSibling=makeNode(v);
	}

	return r;
}


void printTree(Node* r){
	if (r==NULL) return;
	printf("%d :", r->data);
	Node* p=r->leftMostChild;
	while (p!=NULL){
		printf("%d ", p->data);
		p=p->rightSibling;
	}
	printf("\n");
	p=r->leftMostChild;
	while (p!=NULL){
		printTree(p);
		p=p->rightSibling;
	}
}

int countNode(Node* r){
	int cnt=0;
	if(r==NULL) return 0;
	Node* q= r->leftMostChild;
	while (q!=NULL){
		cnt+=countNode(q);
		q=q->rightSibling;
	}
	return cnt+1;
}

int countLeaves(Node* r){
	if(r==NULL) return 0;
	int c=0;
	if(r->leftMostChild==NULL) return 1;
	Node* q=r->leftMostChild;
	while (q!=NULL){
		c+= countLeaves(q);
		q=q->rightSibling;
	}
	return c;
	
}

int height(Node* r){
	if(r==NULL) return 0;
	int max=0;
	Node* q= r->leftMostChild;
	while(q!=NULL){
		if(max<height(q)) max=height(q);
		q=q->rightSibling;
	}
	//lien he voi height cua cai cao hon  
	return max +1;
}

int depth(Node* r, int v){
	if (r->data==v) return 1;
	Node* q=r->leftMostChild;
	int d=1;
	while(q!=NULL){
		if(q->data==v) {
			d=d+1;
			break;
		}
		q=q->rightSibling;
	}
	if(d==1){
		q=r->leftMostChild;
		while (q!=NULL){
			if(depth(q, v)!=1){
				d=1+depth(q,v);
				break;
			}
			q=q->rightSibling;
		}
	}
	return d;
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
	printf("\n %d", countNode(root));
	printf("\n %d", countLeaves(root));
	printf("\n %d", height(find(root, 11)));
	printf("\n %d", depth(root, 9));
}

