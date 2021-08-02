#include <bits/stdc++.h>
#include "Treenode.h"
using namespace std;

// Recursive Method

void Treeprint(Treenode<int>* root) {

    cout<<root->data<<" : ";

    for(int i=0;i<root->children.size();i++) {

        cout<<root->children[i]->data<<", ";

    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++)
        Treeprint(root->children[i]);

}

// Level Wise Printing - Queue Method

void TreeprintQ(Treenode<int>* root) {

    queue<Treenode<int>*> q;
    q.push(root);
    while(!q.empty()) {

        Treenode<int>* front = q.front();
        q.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->children.size();i++) {
            cout<<front->children[i]->data<<", ";
            q.push(front->children[i]);
        }
        cout<<endl;

    }

}

// Recursive Method

Treenode<int>* Treeinput() {

    int rootData;
    cout<<"Enter the data: ";
    cin>>rootData;
    Treenode<int>* root = new Treenode<int>(rootData);
    int noofchild;
    cout<<"Enter the no of children of "<<rootData;
    cin>>noofchild;
    for(int i=0;i<noofchild;i++) {

        Treenode<int>* child = Treeinput();
        root->children.push_back(child);
    }

    return root;
}

// Level Wise Input - Queue Method

Treenode<int>* TreeinputQ() {

    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;
    Treenode<int>* root = new Treenode<int>(rootData);
    queue<Treenode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {

        Treenode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"Enter no. of children for "<<front->data<<" : ";
        cin>>n;
        for(int i=0;i<n;i++) {

            int nodeData;
            cin>>nodeData;
            Treenode<int>* child = new Treenode<int>(nodeData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;

}

int noOfNodes(Treenode<int>* root) {

    int ans = 1;

    for(int i=0;i<root->children.size();i++) {

        ans += noOfNodes(root->children[i]);
    }
    return ans;
}

int heightofTree(Treenode<int>* root) {

    int maxi = 1;

    for(int i=0;i<root->children.size();i++) {
        int ans = 1;
        ans += heightofTree(root->children[i]);
        maxi = max(ans,maxi);
    }

    return maxi;
}

void levelNodes(Treenode<int>* root, int k) {

    if(k==0) {

        cout<<root->data<<" ";
        return;
    }

    for(int i=0;i<root->children.size();i++) {
        levelNodes(root->children[i],k-1);
    }

}


int main() {

    Treenode<int>* root = TreeinputQ();
    TreeprintQ(root);
    cout<<noOfNodes(root)<<endl;
    cout<<heightofTree(root);
    levelNodes(root,2);
}