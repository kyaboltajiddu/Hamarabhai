#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node*root;
    root=(struct node*)malloc(sizeof(struct node));
    root->data=key;
    root->left=root->right=NULL;

    return root;
}

struct node * Insert(struct node *root, int value)
{
    if(root==NULL)
    return newNode(value);

    if(root->data > value)
    root->left=Insert(root->left,value);
    if(root->data < value)
    root->right=Insert(root->right,value);

    return root;
}

void Inorder(struct node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

void Preorder(struct node *root)
{
    if(root==NULL)
    return ;

        cout<<root->data<<" ";

        Inorder(root->left);

        Inorder(root->right);

}

void Postorder(struct node *root)
{
    if(root==NULL)
    return;
    {
        Inorder(root->left);

        Inorder(root->right);

        cout<<root->data<<" ";
    }
}

int main()
{
struct node *root=NULL;

root=Insert(root,15);
root=Insert(root,10);
root=Insert(root,20);
root=Insert(root,13);
root=Insert(root,17);

Inorder(root);
cout<<endl<<"Preorder : ";
Preorder(root);
cout<<endl;
Postorder(root);


return 0;
}
