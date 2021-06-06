#include <iostream>
#include "bst.h"

Node* BST::makeEmpty(Node* t)
{
    if (t != nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
    return t;
}

Node* BST::insert(int x, Node* t)
{
    if (t == nullptr)
    {
        t = new Node;
        t->data = x;
        t->left = t->right = nullptr;
    }
    else if (x < t->data)
    {
        t->left = insert(x, t->left);
    }
    else
    {
        t->right = insert(x, t->right);
    }
    return t;
}

Node* BST::findMin(Node* t, int& min)
{
    if (t == nullptr)
    {
        return nullptr;
    }
    else if (t->left == nullptr)
    {
        min = t->data;
        return t;
    }
    else
    {
        return findMin(t->left, min);
    }
}

Node* BST::findMax(Node* t, int& max)
{
    if (t == nullptr)
    {
        return nullptr;
    }
    else if (t->right == nullptr)
    {
        max = t->data;
        return t;
    }
    else
    {
        return findMax(t->right, max);
    }
}

Node* BST::remove(int x, Node* t)
{
    if (t != nullptr)
    {
        if (x < t->data)
        {
            t->left = remove(x, t->left);
        }
        else if (x > t->data)
        {
            t->right = remove(x, t->right);
        }
        else if (t->left && t->right)
        {
            // to do
        }
        else
        {
            // either left or right only
            Node* currNode = t;
            if (t->left == nullptr)
            {
                t = t->right;
            }
            else if (t->right == nullptr)
            {
                t = t->left;
            }
            delete currNode;
        }
    }
    return t;
}

Node* BST::find(Node* t, int x, bool& isPresent)
{
    if (t != nullptr)
    {
        if (x < t->data)
        {
            return find(t->left, x, isPresent);
        }
        else if (x > t->data)
        {
            return find(t->right, x, isPresent);
        }
        else
        {
            isPresent = true;
            return t;
        }
    }
    return t;
}

void BST::inOrder(Node* t)
{
    if (t != nullptr)
    {
        inOrder(t->left);
        std::cout << t->data << " ";
        inOrder(t->right);
    }
}

void BST::preOrder(Node* t)
{
    if (t != nullptr)
    {
        std::cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

void BST::postOrder(Node* t)
{
    if (t != nullptr)
    {
        postOrder(t->left);
        postOrder(t->right);
        std::cout << t->data << " ";
    }
}

int BST::count(Node* t)
{
    if (t == nullptr)
    {
        return 0;
    }
    else
    {
        int leftCount = count(t->left);
        int rightCount = count(t->right);
        return leftCount + 1 + rightCount;
    }
}

// public methods

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    root = makeEmpty(root);
}

void BST::insert(int x)
{
    root = insert(x, root);
}

void BST::remove(int x)
{
    root = remove(x, root);
}

void BST::reset()
{
    root = makeEmpty(root);
}

void BST::display(int order)
{
    switch (order)
    {
    case InOrder:
        inOrder(root);
        break;
    case PreOrder:
        preOrder(root);
        break;
    case PostOrder:
        postOrder(root);
        break;
    default:
        inOrder(root);
        break;
    }
    std::cout << std::endl;
}

bool BST::search(int x)
{
    bool result = false;
    root = find(root, x, result);

    return result;
}

int BST::count()
{
    return count(root);
}

int BST::findMin()
{
    int min = -1;
    findMin(root, min);

    return min;
}

int BST::findMax()
{
    int max = -1;
    findMax(root, max);
    return max;
}
