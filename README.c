#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
struct node
{
    int age;
    struct node* left;
    struct node* right;
};
struct node* root=NULL;
static int min=0;
struct node* insert(int d)
{
    struct node* temp,*parent;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->age=d;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* current;
        current=root;
        while(current)
        {
            parent=current;
            if(temp->age>current->age)
            {
                current=current->right;
            }
            else
            {
                current=current->left;
            }
        }
        if(temp->age<parent->age)
        {
            parent->left=temp;
        }
        else
        {
            parent->right=temp;
        }
    }
    return root;
}
int minimum(struct node* root,int min1)
{
    if(root->left!=NULL&&root->right!=NULL)
    {
        struct node* l=root->left;
        struct node* r=root->right;
        min=(l->age)-(r->age);
        if(min<0)
        {
            min=(-1*min);
        }
        if(min>min1)
        {
            min=min1;
        }
        if(l->left!=NULL||l->right!=NULL)
        {
            minimum(l,min);
        }
        if(r->left!=NULL||r->right!=NULL)
        {
            minimum(r,min);
        }
    }
    return min;
}
void main()
{
    int d,n;
    scanf("%d",&d);
    for(int i=0;i<d;i++)
    {
        scanf("%d",&n);
        root=insert(n);
    }
    int m=minimum(root,100);
    printf("minimum age difference: %d",m);
}
