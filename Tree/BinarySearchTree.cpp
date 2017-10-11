//Binary Search Tree
//Insert, Search and Delete

#include<bits/stdc++.h>
using namespace std;

class bstNode {
	private:
	struct node {
		int data;
		node *left, *right, *parent;
	}*root;
	public:
	
	bstNode() {
		root = NULL;
	}

	void insertNode(int data);
	void deleteNode(int data);
	bool search(int data);
	void print(node *root);
	void printTree() {
		print(root);
	}
};

//Insert a new node in BST
void bstNode::insertNode(int data) {
	node *temp = new node;
	if(root == NULL) {
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		temp->parent = NULL;
		root = temp;
		return;
	}
	temp = root; 
	bool left = true;
	while(1) {
		if(data <= temp->data) {
			if(temp->left)
				temp = temp->left; 
			else 
				break;
		}
		else {
			if(temp->right) {
				temp = temp->right;
			}
			else {
				left = false;
				break;
			}
		}
	}
//	cout<<"inserting node after "<<temp->data<<" "<<left<<endl;
	node *n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->parent = temp;
	if(left)
		temp->left = n;
	else
		temp->right = n;	
}

//returns true if found in the tree else return false
bool bstNode::search(int data) {
	node *temp = root;
	while(temp) {
		if(temp->data == data)
			return true;
		else if(data < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return false;
}

//delete node from BST assuming node is present in the tree
void bstNode::deleteNode(int data) {
	//find whether temp is left or right child of the parent
	node *temp = root;
	bool left = true;
	while(temp) {
		if(data == temp->data)
			break;
		else if(data < temp->data) {
			left = true;
			temp = temp->left;
		}
		else {
			left = false;
			temp = temp->right;
		}
	}

	//case 1: temp is a leaf node
	if(temp->left == NULL && temp->right == NULL) {
		if(left)
			temp->parent->left = NULL;
		else
			temp->parent->right = NULL;

		delete(temp);
		return;
	}	
	
	//case 2: temp has only one child
	if(temp->left != NULL && temp->right == NULL) {
		if(left)
			temp->parent->left = temp->left;
		else
			temp->parent->right = temp->left;
		delete(temp);
		return;
	}
	else if(temp->right != NULL && temp->left == NULL) {
		if(left)
			temp->parent->left = temp->right;
		else
			temp->parent->right = temp->right;
		delete(temp);
		return;
	}

	//case 3: temp has both childs
	if(temp->left != NULL && temp->right != NULL) {
		cout<<temp->data<<" has both children\n";
		//find inorder successor of temp
		node * t = temp->left;
		while(t->right) 
			t = t->right;

		cout<<"inorder successor "<<t->data<<endl;

		//replace temp data with inorder successor's data
		temp->data = t->data;

		//delete inorder successor
		//t has no child
		if(t->left == NULL && t->right == NULL)
			t->parent->right = NULL;

		//t has left child
		if(t->left != NULL)
			t->parent->right = t->left;

		delete(t);
		return;
	}
}

//print inorder traversal of BST
void bstNode::print(node *temp) {
	if(temp != NULL) {
		print(temp->left);
		cout<<temp->data<<" ";
		print(temp->right);
	}
	else 
		return;
}

int main() {
	bstNode b;
	b.insertNode(1);
	b.insertNode(5);
	b.insertNode(2);		
	b.insertNode(6);
	b.insertNode(3);

	cout<<"Binary Search Tree is:\n";
	b.printTree();

	cout<<"\nSearching for 8:\n";
	if(b.search(8))
		cout<<"found in the tree";
	else
		cout<<"not found in the tree";

	cout<<"\nDeleting 5 from the tree\n";
	b.deleteNode(5);
	cout<<"Tree after deletion\n";
	b.printTree();	
	
	return 0;
}
