#include <iostream>
#include <string>
using namespace std;

class node 
{
public:
    string info;
    node *leftchild;
    node *rightchild;

    // Constructor for the node class
    node(string i, node *l, node *r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree
{
public:
    node *ROOT;

    BinaryTree()
    {
        ROOT = NULL; // Initialize ROOT to nullptr
    }

    // Insert a node in the binary search tree
    void insert(string element)
    {
        node *newnode = new node(element, NULL, NULL);
    
        newnode->info = element;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;

        if (ROOT == NULL) 
        {
            ROOT = newnode;
            return;
        }

        node *currentnode = ROOT;
        node *parent = NULL;

        while (currentnode != NULL)
        {
            parent = currentnode;
            if (element < currentnode->info)
            {
                currentnode = currentnode->leftchild;
            }
            else
            {
                currentnode = currentnode->rightchild;
            }
        }

        if (element < parent->info) 
        {
            parent->leftchild = newnode;
        } 
        else 
        {
            parent->rightchild = newnode;
        }
    }

// This function searches the current node for the specified node
// as well as the current node of its parent
void search (string element, node *&parent, node *&currentnode)
{
    currentnode = ROOT;
    parent = NULL;

    while ((currentnode != NULL) && (currentnode->info != element))
    {
        parent = currentnode;
        if (element < currentnode->info)
            currentnode = currentnode->leftchild;
        else
            currentnode = currentnode->rightchild;
    }
}

void inorder(node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->leftchild);
        cout << ptr->info << " ";
        inorder(ptr->rightchild);
    }
}

void preorder(node *ptr)
{
    if (ROOT == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }
    if (ptr != NULL)
    {
        cout << ptr->info << " ";
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }
}
