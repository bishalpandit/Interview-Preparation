#include <bits/stdc++.h>
#include "BTnode.h"
using namespace std;

void treePrint(BTnode<int>* root) {

    if(root == NULL) 
        return;
    cout<<endl<<root->data<<": ";

    if(root->left != NULL)
        cout<<"L"<<root->left->data<<", ";
    if(root->right != NULL)
        cout<<"R"<<root->right->data;
    treePrint(root->left);
    treePrint(root->right);
}

void treePrintQ(BTnode<int>* root) {

    queue<BTnode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {

        BTnode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<endl<<front->data<<" : ";

        if(front->left)
            pendingNodes.push(front->left);
            
        if(front->right)
            pendingNodes.push(front->right);
    }
}

BTnode<int>* treeInput() {

    cout<<"Enter the root data: ";
    int rootData;
    cin>>rootData;
    BTnode<int>* root = new BTnode<int>(rootData);
    queue<BTnode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) { 

        BTnode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter the left child of "<<front->data<<": ";
        int leftChild;
        cin>>leftChild;
        if(leftChild != -1) {

            BTnode<int>* left = new BTnode<int>(leftChild);
            front->left = left;
            pendingNodes.push(left);
        } 

        cout<<"Enter the right child of "<<front->data<<": ";
        int rightChild;
        cin>>rightChild;
         if(rightChild != -1) {

            BTnode<int>* right = new BTnode<int>(rightChild);
            front->right = right;
            pendingNodes.push(right);
        } 
    }

    return root;
}

int treeNodes(BTnode<int>* root) {

    if(root == NULL)
        return 0;

    int ans = 1;

    // if(root->left)
    //     ans += treeNodes(root->left);
    // if(root->right)
    //     ans += treeNodes(root->right);

    if(root->left || root->right) {

        ans += treeNodes(root->left);
        ans += treeNodes(root->right);
    }
    
    
    return ans;
}

int HeightBT(BTnode<int>* root) {

    if(root == NULL)
        return 0;

    int maxi = 1;

    if(root->left || root->right) {
        int leftChild = 1, rightChild = 1;
        leftChild += HeightBT(root->left);
        rightChild += HeightBT(root->right);
        maxi = max(leftChild, rightChild);
    }

    return maxi;

}


void preOrder(BTnode<int>* root) {

    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BTnode<int>* root) {

    if(root == NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(BTnode<int>* root) {

    if(root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

BTnode<int>* searchBST(BTnode<int>* root, int key) {

    if(root == NULL)
        return NULL;
    
    if(root->data == key)
        return root;
    else if(root->data>key)
      return  searchBST(root->left, key);
    else 
      return  searchBST(root->right, key);

}

// if root->data >= min and root->data <= max
// if root->data > min left call and if root->data <max 

void printInRange(BTnode<int>* root, int min, int max) {

    if(!root)
        return;

    if(root->data >=min && root->data <= max)
        cout<<root->data<<" ";
    if(root->data > min)
        printInRange(root->left, min, max);
    if(root->data < max)
        printInRange(root->right, min, max);
}



int main() {


    BTnode<int> *root = treeInput();
    printInRange(root,3,8);

    // cout<<"\nNo of nodes -> "<<treeNodes(root);
    // cout<<"\nHeight of tree -> "<<HeightBT(root);
    // cout<<endl;
    // preOrder(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // postOrder(root);
}