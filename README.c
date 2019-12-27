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
    struct node* temp,*parent;          // temp is used to create the node and conect with the tree
    temp=(struct node*)malloc(sizeof(struct node));    //Here allocating the memory for temp
    temp->age=d;                  //assigning the value temp as d
    temp->left=NULL;            // here temp holds null in left 
    temp->right=NULL;           //here temp hlds null in right
    if(root==NULL)              
    {
        root=temp;
    }
    else                        
    {
        struct node* current;       //current is used to travel from root to last node because the new node 
                                                                    //need to insert at correct position
        current=root;
        while(current)          
        {
            parent=current;
            if(temp->age>current->age)      
            {
                current=current->right;         //if the new value greater than old then it will move to right
            }
            else
            {
                current=current->left;          //if the new value smaller than old value then it will move left
            }
        }                               //it will end when current gets null that is it reaches the last node 
        if(temp->age<parent->age)
        {
            parent->left=temp;          //ifthe new value greater then the parent then it will add right to the parent
        }
        else
        {
            parent->right=temp;         // if the new value smaller then the parent then it will add left to the parent
        }
    }
    return root;            
}
int minimum(struct node* root,int min1)
{
    if(root->left!=NULL&&root->right!=NULL)   // if the left and right of the node has null values then there is no nodes connected
    {
        struct node* l=root->left;         // L holds the left children of the root 
        struct node* r=root->right;       //  R holds the right children of the root
        min=(r->age)-(l->age);            //here subracting the age of left child and the 
        if(min>min1)
        {
            min=min1;                   //here the min of the two pair is greater then the other then change the min as lower difference
        }   
        if(l->left!=NULL||l->right!=NULL)
        {
            minimum(l,min);           // a function calling itselt to find the age diff of the subchilds
        }
        if(r->left!=NULL||r->right!=NULL)
        {
            minimum(r,min);         // a function calling itself to find the age diff of the sub childs
        }
    }
    return min;                     //after checking all the nodes returning the minimum diff to main function
}
void main()
{
    int d,n;
    scanf("%d",&d);                 //Getting the number of members 
    for(int i=0;i<d;i++)            //Here geting the number of age for each person
    {
        scanf("%d",&n);
        root=insert(n);             //Here calling the insert function to form the tree 
    }
    int m=minimum(root,100);        //here we calling minimum function to find the minimum age 
    if(m>0)
    {
        printf("Minimum age difference: %d",m);   //a parent has two childs then printing the difference 
    }
    else
    {
        printf("There is no two child for same parent in the family");   // no pair of childs for single parent inthe family 
    }
}
