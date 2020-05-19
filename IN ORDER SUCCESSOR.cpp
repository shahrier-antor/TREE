
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
bstnode* search(bstnode*root,int data)
{
    if(root== NULL)return NULL;
    if(root-> data==data)return root;
    else if(root->data>= data)return search(root->left,data);
    else return search (root->right, data);
}
bstnode* gsuccessor(bstnode*root,int data)
{
 bstnode* current=search(root,data);
 if(current==NULL)return NULL;
 if(current->right!=NULL)
 {
     return FindMin(current->right);

 }
 else
 {
     bstnode*successor=NULL;
     bstnode*ancestor=root;
     while(ancestor!=current)
     {
         if(current->data<ancestor->data)
         {
            successor= ancestor;
             ancestor=ancestor->left;
         }
         else
         {
             ancestor=ancestor->right;
         }
     }
     return successor;

 }
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
    bstnode* successor=gsuccessor(root,d);
    if(successor==NULL)cout<< "NAI"<<endl;
    else

        cout<<successor->data<<endl;
}
