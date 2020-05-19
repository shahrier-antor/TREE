
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
bstnode* FindMin(bstnode*root)
{
    while(root->left!=NULL)root=root->left;
    return root;
}
bstnode* del(bstnode* root,int data)
{
    if (root== NULL)return root;
    if(data< root->data)del(root->left,data);
    else if(data> root->data)del(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root-> left== NULL)
        {
            bstnode* temp=root;
            root=root->right;
            delete temp;

        }
         else if(root-> right== NULL)
        {
            bstnode* temp=root;
            root=root->left;
            delete temp;

        }
        else
        {
             bstnode* temp=FindMin(root->right);
             root->data=temp->data;
             root->right=del(root->right,temp->data);

        }
    }
    return root;
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
    int d;
    cin>> d;
    del(root,d);

}
