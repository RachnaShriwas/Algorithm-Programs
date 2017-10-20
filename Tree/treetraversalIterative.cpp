//Tree traversal preorder, inorder, postorder iterative

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right, *parent;
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

///Inorder iterative
/*
1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.
*/
void inorder(node *root) {
	node* s[200];
	int i = -1;
	node *current = root;

	while(1) {
		//cout<<"\ncurrent data: "<<current->data<<" "<<current<<" left : "<<current->left;
		if(current != NULL) {
			//cout<<"pushed "<<current->data<<endl;
			s[++i] = current;
			current = current->left;
			//cout<<" current in if = "<<current<<endl;
		}
		else {
			//cout<<"\nin else";
			if(i >= 0) {
				//cout<<"popped "<<s[i]->data<<endl;
				current = s[i];
				cout<<current->data<<" ";
				i--;
				current = current->right;
				//cout<<"current now is : "<<current<<endl;
			}
			else
				break;
		}
		//if(!current && i < 0)
			//break;
		//cout<<"\ncurrent at last: "<<current<<endl;
	}
}

///preorder iterative
/*
1) Create an empty stack nodeStack and push root node to stack.
2) Do following while nodeStack is not empty.
….a) Pop an item from stack and print it.
….b) Push right child of popped item to stack
….c) Push left child of popped item to stack
*/
void preorder(node *root) {
    if(root == NULL)
        return;

    node* s[200];
    int i = -1;
    s[++i] = root;

    while(i >= 0) {
        node *temp = s[i];
        i--;
        cout<<temp->data<<" ";

        if(temp->right)
            s[++i] = temp->right;
        if(temp->left)
            s[++i] = temp->left;
    }
}

///postorder iterative
/*
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/
void postorder(node *root) {
    if(root == NULL)
        return;

    node *temp = root;
    node *s[200];
    int i = -1;

    do{
        while(temp) {
            if(temp->right)
                s[++i] = temp->right;
            s[++i] = temp;

            temp = temp->left;
        }

        temp = s[i];
        i--;

        if(temp->right && s[i] == temp->right) {
            i--;
            s[++i] = temp;
            temp = temp->right;
        }
        else {
            cout<<temp->data<<" ";
            temp = NULL;
        }
    }while(i >= 0);
}


int main() {
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout<<"Iterative preorder:\n";
	preorder(root);

	cout<<"\nIterative inorder:\n";
	inorder(root);

    cout<<"\nIterative postorder:\n";
	postorder(root);

	cout<<endl;
	return 0;
}
