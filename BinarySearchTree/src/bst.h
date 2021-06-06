#include <iostream>

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
};

class BST
{
    private:
        Node* root;

        Node* makeEmpty(Node*);

        Node* insert(int, Node*);

        Node* findMin(Node*, int&);

        Node* findMax(Node*, int&);

        Node* remove(int, Node*); // xxx

    
        Node* find(Node*, int, bool&);

        void inOrder(Node*);

        void preOrder(Node*);
        
        void postOrder(Node*);

        int count(Node*);

    public:
       BST();

       ~BST();

       void insert(int);

       void remove(int);

       void reset();

       void display(int order = 0);

       bool search(int);

       int count();

       int findMin();

       int findMax();
};

enum Order
{
    InOrder = 1,
    PreOrder = 2,
    PostOrder = 3
};
