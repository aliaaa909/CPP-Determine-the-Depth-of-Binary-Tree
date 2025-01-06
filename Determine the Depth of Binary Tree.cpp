
#include <iostream>
using namespace std;

// node
struct Node{
    int label;
    Node *left, *right, *parent;
};

//global pointer variable
Node *root, *newNode;

void CreateNewTree(int label)
{
    if(root != NULL)
    {
        cout << "Tree is created" << endl;
    } else {
        root = new Node;
        root->label = label;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n " << label << " succesfully created as root" << endl;
    }
}

//this is a function thatll return the node as the type data, so we using Node and the pointer *
Node *InsertLeft(int label, Node *node)
{
    if(root == NULL)
    {
        cout << "Theres no tree" << endl;
    }else{
        //check if theres a left child
        if(node->left != NULL){
            cout << "Left child was added " << endl;
            //if theres a left child
            return NULL;
        //if theres no left child
        } else {
        newNode = new Node;
        newNode->label = label;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = node;
        node->left = newNode;
        cout << " " << label << " successfully added to left child of " << newNode->parent->label << endl;
    } return newNode;
}
}

Node *InsertRight(int label, Node *node)
{
    if(root == NULL)
    {
        cout << "Theres no tree" << endl;
    }else{
        //check if theres a right child
        if(node->right != NULL){
            cout << "right child was added " << endl;
            //if theres a right child
            return NULL;
        //if theres no right child
        } else {
        newNode = new Node;
        newNode->label = label;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = node;
        //pointer tight dr orang tua, add to this node
        node->right = newNode;
        cout << " " << label << " successfully added to right child of " << newNode->parent->label << endl;
    } return newNode;
}
}


int sizeTree(Node *node = root) //djhdjewhfjh of this function is to make root as a defaulyt
{
     if( !root ){//its the same way as we write root == NULL
        cout << "\nTree does not exist." << endl;
    }else{

        if(!node){
            return 0;
        }else{
            return 1 + sizeTree(node->left)+ sizeTree(node->right);
        }
    }
}

int TreeHeight(Node *node = root)
{
     if( !root ){//its the same way as we write root == NULL
        cout << "\nTree does not exist." << endl;
    }else{

        if(!node){
            return 0;
        }else{
            int leftHeight = TreeHeight(node->left);
            int rightHeight = TreeHeight(node->right);

            if(leftHeight >= rightHeight){
                return leftHeight + 1;
            } else {
                return rightHeight + 1;
            }
        }
    }
}

void characteristics()
{
    cout << "\nSize of Tree         : " << sizeTree();
    cout << "\nHeight of Tree       : " << TreeHeight() - 1;
}
int main()
{
    CreateNewTree(3);

    Node *node3 , *node9, *node7, *node15, *node20;

    node9 = InsertLeft(9, root);
    node20 = InsertRight(20, root);

    node15 = InsertLeft(15, node20);
    node7 = InsertRight(7,node20);

    characteristics();

}
