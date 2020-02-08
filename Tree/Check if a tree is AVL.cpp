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
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
} 
// use limited period  (min, max)
int isBSTUtil1(node* r, int min, int max){
	if(r==NULL) return 1;
	if(r->data>min && r->data<max){
		return isBSTUtil1(r->left, min,r->data) && isBSTUtil1(r->right, r->data, max);
	}
	return 0;
}
int isBST1(node* r){
	return isBSTUtil1(r, INT_MIN, INT_MAX);
}
 // use Inorder Traversal
 
int isBST2(node* r){
 	static int pre=0;
 	if(r==NULL) return 1;
 	int nl= isBST2(r->left);
 	if(r->data<pre) return 0;
 	else pre=r->data;
 	int nr= isBST2(r->right);
 	return nr&&nl;
} 
/* Driver program to test above functions*/

int isHeightBalance(node* r){
	// return height of r if is height_balance
	// return -1 if the tree is not balance
	if(r==NULL) return 0;
	int hl=isHeightBalance(r->left);
	int hr=isHeightBalance(r->right);
	printf("%d: hl-%d hr-%d\n", r->data,hl, hr );
	if(hr<0||hl<0) return -1;
	if(hl-hr>1||hr-hl>1) return -1;
	if(hl>hr) return 1+ hl;
	else return 1+ hr;
}
// Note this method when wanting to store other information: using pointer in parameter
int isHeightBalance2(node* r, int* height){
	if(r==NULL){
		*height=0;
		return 1;
	}
	int hl=0;
	int hr=0;
	int cl= isHeightBalance2(r->left, &hl);
	int cr= isHeightBalance2(r->right, &hr);
	*height=(hl>hr? hl: hr)+1;
	printf("%d : %d\n",r->data,*height);
	if(cl==0||cr==0) return 0;
	if(hl-hr>1|| hr-hl>1) return 0;
	return 1;
	
}

int main() 
{ 
  struct node *root = newNode(4); 
  root->left        = newNode(3); 
  root->right       = newNode(5); 
  root->left->left  = newNode(1); 
  root->left->right = newNode(2);  
  root->left->left->left=newNode(6);
  int height=0;
  if(isHeightBalance2(root, &height)==0) printf("Not balance\n");
  else{
  	printf("Balance\n");
  }
  if(isBST2(root)) 
    printf("Is BST"); 
  else
    printf("Not a BST"); 
  return 0; 
}   

