///minimum number of machines required to perform all jobs
///implementation using binay search
///O(n logn) when depth is equivalent to n
#include<bits/stdc++.h>
#include "avlTreeTemplate.cpp"

using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

struct Node* modifiedSearch(struct Node* root, int x)
{
    if(root == NULL || root->key == x)
    {
        return root;
    }
    else if(root->key < x)
    {
        if(root->right==NULL || root->right->mn > x)
        {
            return root;
        }
        return modifiedSearch(root->right,x);
    }
    else
    {
        if(root->left!=NULL && root->left->mx < x)
        {
            return search(root,root->left->mx);
        }
        else if(root->left == NULL)
        {
            return NULL;
        }
        return modifiedSearch(root->left,x);
    }
}

int main()
{
    vector<pair<int,int> > jobs;
    jobs.push_back(make_pair(1,3));
    jobs.push_back(make_pair(4,5));
    jobs.push_back(make_pair(6,7));
    jobs.push_back(make_pair(8,9));

    sort(jobs.begin(),jobs.end());

    struct Node *machine = NULL;
    struct Node *temp;
    temp = machine;
    machine = insert(machine,jobs[0].second);
    for(int i=1;i<jobs.size();i++)
    {
        temp = modifiedSearch(machine,jobs[i].first);
        if(temp != NULL)
        {
            machine = deleteNode(machine,temp->key);
        }
        machine = insert(machine,jobs[i].second);
    }
    cout<<getNumNodes(machine)<<endl;
    return 0;
}
