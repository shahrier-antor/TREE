#include<bits/stdc++.h>
using namespace std;
struct bstnode
{
    int data;
    bstnode*left;
    bstnode*right;


};
bstnode*getnew(int data)
{
    bstnode* newnode=new bstnode();
    newnode->data=data;
    newnode-> left=NULL;
    newnode-> right=NULL;
    return newnode;
}
bstnode * insert(bstnode*root,int data)
{
    if(root== NULL)
    {
        root=getnew(data);
    }
    else if(data< root-> data)
    {
        root->left= insert(root->left,data);
    }
    else
    {
        root-> right=insert(root-> right,data);
    }
    return root;

}
bool search(bstnode*root,int data)
{
    if(root== NULL)return false;
    if(root-> data==data)return true;
    else if(root->data>= data)return search(root->left,data);
    else return search (root->right, data);
}
int main()
{
    bstnode* root=NULL;
    int n;
    cin>> n;
    while(n--)
    {
        int x;
        cin>> x;
        root=insert(root,x);
    }
    int num;
    cin>> num;
    if(search(root,num))
        cout<< "found"<< endl;
    else  cout<< "not found"<< endl;
}
