
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
int fminElement(bstnode*root)
{
    if(root==NULL)return -1;
   /* while(root->left!=NULL)
    {
        root-root->left;

    }
    else
    return root->data;*/
    // reucursive appraoch
    else if(root-> left==NULL)return root->data;
    else return fminElement(root->left);
    // for max we jhust need to chechk the root-> right

}
int fHeight(bstnode* root)
{
    if(root==NULL)return -1;//cause we will make a plus 1 , so for leaf node we need to balance it
        return max(fHeight(root-> left),fHeight(root->right))+1;
}
void bfs(bstnode* root)
{
    if(root==NULL)return;
    queue< bstnode*>q;
    q.push(root);
    while(!q.empty())
    {
        bstnode*current=q.front();
        cout<< current-> data<< " ";
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        q.pop();

    }
}
 void  preorder(bstnode*root)
    {
       // cout<< "preorder:-"<< endl;
        if (root== NULL)return;

        cout<< root->data<< " ";
        preorder(root->left);
        preorder(root->right);
       // cout<< endl;
    }

    void  inorder(bstnode*root)
    {
       // cout<< "Inorder:-"<< endl;
        if (root== NULL)return;
        inorder(root->left);
        cout<< root->data<< " ";

        inorder(root->right);
       // cout<< endl;
    }
     void  postorder(bstnode*root)
    {
       // cout<< "POSTorder:-"<< endl;
        if (root== NULL)return;
        postorder(root->left);

        postorder(root->right);
       cout<< root->data<< " ";
        //cout<< endl;
    }
void dfs(bstnode* root)
{
   preorder(root);
   cout<< endl<< endl;
   inorder(root);
      cout<< endl<< endl;

   postorder(root);
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
    cout<< fminElement(root)<< endl;
    cout<< fHeight(root);
    bfs(root);
    cout<< endl<< endl;
    dfs(root);
}
