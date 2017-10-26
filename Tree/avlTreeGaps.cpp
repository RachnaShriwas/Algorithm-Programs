// C program to insert a node in AVL tree
#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
struct Node
{
    int key;
    int sum;
    struct Node *left;
    struct Node *right;
    int height;
    int numNodes;
    int mn;
    int mx;
    int minGap;
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getNumNodes(struct  Node *N)
{
    if(N == NULL)
        return 0;
    return N->numNodes;
}

int buildSum(struct Node *root)
{
   if(root == NULL) return 0;
   else
        root->sum = buildSum(root->left) + buildSum(root->right) + root->key;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key = node->sum = node->mx = node->mn = key;
    node->left = NULL;
    node->right = NULL;
    node->numNodes  = 1;
    node->height = 1;  // new node is initially added at leaf
    node->minGap = INT_MAX;
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Update number of nodes
    y->numNodes = getNumNodes(y->right) + getNumNodes(y->left) + 1;
    x->numNodes = getNumNodes(x->right) + getNumNodes(x->left) + 1;

     // Update sum of nodes
    y->sum = (y->key) + ((y->left !=NULL)?(y->left->sum):0) + ((y->right !=NULL)? (y->right->sum) : 0);
    x->sum = (x->key) + ((x->left !=NULL)?(x->left->sum):0) + ((x->right !=NULL)? (x->right->sum) : 0);

    // Update the min of nodes
    y->mn = y->key;
    if(y->left !=NULL)
        y->mn = min(y->mn,y->left->mn);
    if(y->right !=NULL)
        y->mn = min(y->mn,y->right->mn);

    x->mn = x->key;
    if(x->left !=NULL)
        x->mn = min(x->mn,x->left->mn);
    if(x->right !=NULL)
        x->mn = min(x->mn,x->right->mn);

    // Update the max of nodes
    y->mx = y->key;
    if(y->left !=NULL)
        y->mx = max(y->mx,y->left->mx);
    if(y->right !=NULL)
        y->mx = max(y->mx,y->right->mx);

    x->mx = x->key;
    if(x->left !=NULL)
        x->mx = max(y->mx,x->left->mx);
    if(x->right !=NULL)
        x->mx = max(y->mx,x->right->mx);

    // Update the minGap of nodes
    y->minGap = INT_MAX;
    if(y->left !=NULL)
        y->minGap = min(y->left->minGap,y->key - y->left->mx);
    if(y->right !=NULL)
        y->minGap = min(y->minGap,min(y->right->minGap,y->right->mn - y->key));

    x->minGap = INT_MAX;
    if(x->left !=NULL)
        x->minGap = min(x->left->minGap,x->key - x->left->mx);
    if(x->right !=NULL)
        x->minGap = min(x->minGap,min(x->right->minGap,x->right->mn - x->key));

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Update number of nodes
    x->numNodes = getNumNodes(x->right) + getNumNodes(x->left) + 1;
    y->numNodes = getNumNodes(y->right) + getNumNodes(y->left) + 1;

    // Update sum of nodes
    x->sum = (x->key) + ((x->left !=NULL)?(x->left->sum):0) + ((x->right !=NULL)? (x->right->sum) : 0);
    y->sum = (y->key) + ((y->left !=NULL)?(y->left->sum):0) + ((y->right !=NULL)? (y->right->sum) : 0);

    // Update the min of nodes
    x->mn = x->key;
    if(x->left !=NULL)
        x->mn = min(x->mn,x->left->mn);
    if(x->right !=NULL)
        x->mn = min(x->mn,x->right->mn);

    y->mn = y->key;
    if(y->left !=NULL)
        y->mn = min(y->mn,y->left->mn);
    if(y->right !=NULL)
        y->mn = min(y->mn,y->right->mn);

    // Update the max of nodes
    x->mx = x->key;
    if(x->left !=NULL)
        x->mx = max(y->mx,x->left->mx);
    if(x->right !=NULL)
        x->mx = max(y->mx,x->right->mx);

    y->mx = y->key;
    if(y->left !=NULL)
        y->mx = max(y->mx,y->left->mx);
    if(y->right !=NULL)
        y->mx = max(y->mx,y->right->mx);

    // Update the minGap of nodes
    x->minGap = INT_MAX;
    if(x->left !=NULL)
        x->minGap = min(x->left->minGap,x->key - x->left->mx);
    if(x->right !=NULL)
        x->minGap = min(x->minGap,min(x->right->minGap,x->right->mn - x->key));

    y->minGap = INT_MAX;
    if(y->left !=NULL)
        y->minGap = min(y->left->minGap,y->key - y->left->mx);
    if(y->right !=NULL)
        y->minGap = min(y->minGap,min(y->right->minGap,y->right->mn - y->key));

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    // Update the number of nodes
    node->numNodes = 1 + getNumNodes(node->left) +
                           getNumNodes(node->right);

    // Update the min of nodes
    node->mn = node->key;
    if(node->left !=NULL)
        node->mn = min(node->mn,node->left->mn);
    if(node->right !=NULL)
        node->mn = min(node->mn,node->right->mn);

    // Update the max of nodes
    node->mx = node->key;
    if(node->left !=NULL)
        node->mx = max(node->mx,node->left->mx);
    if(node->right !=NULL)
        node->mx = max(node->mx,node->right->mx);

    // Update the minGap of nodes
    node->minGap = INT_MAX;
    if(node->left !=NULL)
        node->minGap = min(node->left->minGap,node->key - node->left->mx);
    if(node->right !=NULL)
        node->minGap = min(node->minGap,min(node->right->minGap,node->right->mn - node->key));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case  Zig-Zig Rotation
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case  Zag-Zag Rotation
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case  Zig-Zag Rotation
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case  Zag-Zig Rotation
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */
struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Recursive function to delete a node with given key
// from subtree with given root. It returns root of
// the modified subtree.
struct Node* deleteNode(struct Node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // Update the number of nodes
    root->numNodes = 1 + getNumNodes(root->left) +
                           getNumNodes(root->right);

    // Update the sum of nodes
    root->sum = root->key;
    if(root->left !=NULL)
        root->sum += root->left->key;
    if(root->right !=NULL)
        root->sum += root->right->key;

    // Update the min of nodes
    root->mn = root->key;
    if(root->left !=NULL)
        root->mn = min(root->mn,root->left->mn);
    if(root->right !=NULL)
        root->mn = min(root->mn,root->right->mn);

    // Update the max of nodes
    root->mx = root->key;
    if(root->left !=NULL)
        root->mx = max(root->mx,root->left->mx);
    if(root->right !=NULL)
        root->mx = max(root->mx,root->right->mx);

    // Update the minGap of nodes
    root->minGap = INT_MAX;
    if(root->left !=NULL)
        root->minGap = min(root->left->minGap,root->key - root->left->mx);
    if(root->right !=NULL)
        root->minGap = min(root->minGap,min(root->right->minGap,root->right->mn - root->key));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
        }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int rank(struct Node* root, int key)
{
    if(key == root->key)
    {
        return getNumNodes(root->right) + 1;
    }
    else if(key > root->key)
    {
        if(root->right == NULL)
            return 1;
        return rank(root->right,key);
    }
    else
    {
        if(root->left == NULL)
            return 1;
        return getNumNodes(root->right) + 1 + rank(root->left,key);
    }
}

struct Node* findRank(struct Node *root, int k)
{
    if(rank(root,root->key) == k)
    {
        return root;
    }
    else if(rank(root,root->key) > k)
    {
        return findRank(root->right,k);
    }
    else
    {
        return findRank(root->left,k - rank(root,root->key));
    }
}

struct Node* search(struct Node* root, int x)
{
    if(root == NULL || root->key == x)
    {
        return root;
    }
    else if(root->key < x)
    {
        return search(root->right,x);
    }
    else
    {
        return search(root->left,x);
    }
}

//count of numbers x<=i<y
int num(struct Node* root, int x, int y)
{
    return rank(root, x) - rank(root, y) + (search(root,x)!=NULL? 1 : 0) + (search(root,x)!=NULL? 1 : 0) - 1;
}

//sum of all numbers in data structure where key <= x
int prefixSum(struct Node* root,int x)
{
    if(root == NULL)
        return 0;
    else if(root->key == x)
        return root->key + (root->left!=NULL?root->left->sum:0);
    else if(root->key < x)
        return ((root->left!=NULL?root->left->sum:0) + root->key + prefixSum(root->right,x));
    else
        return prefixSum(root->left,x);
}

int sumRange(struct Node* root, int x, int y)
{
    return prefixSum(root, y) - prefixSum(root, x-1);
}

float average(struct Node* root, int x, int y)
{
    return ((float)sumRange(root,x,y)/(float)num(root,x,y));
}

int maxGap(struct Node* root, int key)
{
    return search(root,key)->mx - search(root,key)->mn;
}

int getMinGap(struct Node* root, int key)
{
    return search(root,key)->minGap;
}

int getMin(struct Node* root, int key)
{
    return search(root,key)->mn;
}

int getMax(struct Node* root, int key)
{
    return search(root,key)->mx;
}

/* Drier program to test above function*/
int main()
{
  struct Node *root = NULL;

  /* Constructing tree given in the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

//    buildSum(root);

    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);

    root = deleteNode(root, 10);

    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);
//    buildSum(root);
    cout<<"rank: "<<rank(root,4)<<endl;
    cout<<"node with rank k: "<<findRank(root,7)->key<<endl;
    cout<<"prefix sum: "<<prefixSum(root,7)<<endl;
    cout<<"range sum: "<<sumRange(root,-1,9)<<endl;
    cout<<"avg: "<<average(root,-1,9)<<endl;
    cout<<"min: "<<getMin(root,9)<<endl;
    cout<<"max: "<<getMax(root,1)<<endl;
    cout<<"maxgap: "<<maxGap(root,9)<<endl;
    cout<<"mingap: "<<getMinGap(root,9)<<endl;
    return 0;
}
