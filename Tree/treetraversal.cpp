//Binary Tree traversal preorder, inorder, postorder using recursion

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data) {
	node *root = new node;
	root->data = data;
	root->left = new node;
	root->right = new node;
	root->left = NULL;
	root->right = NULL;

	return root;

}

//Preorder recursive
void preorderR(node *root) {
	if(root != NULL) {
		cout<<root->data<<" ";
		preorderR(root->left);
		preorderR(root->right);
	}
}

//Inorder recursive
void inorderR(node *root) {
	if(root != NULL) {
		inorderR(root->left);
		cout<<root->data<<" ";
		inorderR(root->right);
	}
}

//Postorder recursive
void postorderR(node *root){
	if(root != NULL){
		postorderR(root->left);
		postorderR(root->right);
		cout<<root->data<<" ";
	}
}


int main() {
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"Preorder:\n";
	preorderR(root);

	cout<<"\nInorder:\n";
	inorderR(root);

	cout<<"\nPostorder:\n";
	postorderR(root);

	return 0;
}	
