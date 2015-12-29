#include <iostream>
#include <fstream>
#define NUM_ELEMENTS 15

using namespace std;
ofstream outputFile ("output.dat");

struct NodeType
{
    int info = -1;
    NodeType* left = NULL;
    NodeType* right = NULL;
};

void addNode(int value, NodeType* &x)
{
    //case for the first node
    if(x == NULL)
    {
        x = new NodeType;
        x->info = value;
        return;
    }
    //if the value is less, go left
    else if(value < x->info)
    {
        addNode(value, x->left);
    }
    //if the value is greater, go right
    else
    {
        addNode(value, x->right);
    }
}

void printInOrder(NodeType* x)
{
    if (x->left != NULL)
        printInOrder(x->left);
    outputFile << x->info << ", ";
    if (x->right != NULL)
        printInOrder(x->right);
}

void printPreOrder(NodeType* x)
{
    outputFile << x->info << ", ";
    if (x->left != NULL)
        printPreOrder(x->left);
    if (x->right != NULL)
        printPreOrder(x->right);
}

void printPostOrder(NodeType* x)
{

    if (x->left != NULL)
        printPostOrder(x->left);
    if (x->right != NULL)
        printPostOrder(x->right);
    outputFile << x->info << ", ";
}

int main()
{
    int values[NUM_ELEMENTS];
    NodeType* tree = NULL;
    ifstream inputFile ("input.dat");

    //populate the values array from the input file
    if (inputFile.is_open())
      {
        for(int i = 0; i < NUM_ELEMENTS; i++)
        {
            inputFile >> values[i];
        }
        inputFile.close();
      }


    //cycle through every element in the values array
    for(int i = 0; i < NUM_ELEMENTS; i++)
    {
        addNode(values[i], tree);
    }

    outputFile << "inorder: ";
    printInOrder(tree);
    outputFile << endl;
    outputFile << "preorder: ";
    printPreOrder(tree);
    outputFile << endl;
    outputFile << "postorder: ";
    printPostOrder(tree);
    outputFile.close();
}
