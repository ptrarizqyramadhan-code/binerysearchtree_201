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
