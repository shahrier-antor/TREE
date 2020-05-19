
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
bool isbuilt(bstnode*root,int mi,int ma)
{

    if(root==NULL)return true;
    if(root-> data>mi&& root->data<
        ma&& isbuilt(root->left,mi,root-> data)&& isbuilt(root->right,root-> data,ma))

    {return true;}

    else
    {return false;}
}
bool isbst(bstnode*root)
{
    return isbuilt(root,INT_MIN,INT_MAX);
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
    if(isbst(root))cout<< " okay"<< endl;
    else cout<< "not okay"<< endl;
}
