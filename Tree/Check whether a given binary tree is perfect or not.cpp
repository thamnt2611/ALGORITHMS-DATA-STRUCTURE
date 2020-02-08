#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}node; 
  
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 
// find a depth of a leaf
int findDepthOfLeaf(node* r){
	int d=0;
	node* p=r;
	while(p!=NULL){
		d++;
		p=p->left;
	}
	return d;
}
// check if every node has 2 child and all leaves have the same level
int isPerfectRec(node* r, int d, int level){
	if(r==NULL) return 1;
	
	if(r->left==NULL && r->right==NULL){
		return(d==level+1);
	}
	if(r->left==NULL || r->right==NULL){
		return 0;
	}
	return isPerfectRec(r->left, d, level+1) && isPerfectRec(r->right, d, level+1);
}

int isPerfect(node* r){
	int d=findDepthOfLeaf(r);
	return isPerfectRec(r, d, 0);
}
/* Driver program to test above functions*/
int main() 
{ 
  struct node *root = newNode(4); 
  root->left        = newNode(3); 
  root->right       = newNode(5); 
  root->left->left  = newNode(1); 
  root->left->right = newNode(2);
  root->right->left  = newNode(6); 
  root->right->right = newNode(7);  
  if(isPerfect(root))
  	printf("Perfect\n");
  else
    printf("Imperfect\n");
  return 0; 
} 
