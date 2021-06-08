#include <iostream>
using std::cout;
using std::endl;

class Node
{
    private:
        int data;
        Node* ptr;

    public:
        Node(int x = 0): data{x}, ptr{nullptr} {}

        int getData() { return data; }
        void setData(int x) { data = x; }

        Node* getNextNode() { return ptr; }
        void setNextNode(Node* x) { ptr = x; }
};

class Linked
{
    private:
        Node* head;

    public:
        Linked() : head{nullptr} {}
        Node* getHead() { return head; }

        void listElements()
        {
            Node* ptr = head;
            while (ptr != nullptr)
            {
                cout << ptr->getData() << "->";
                ptr = ptr->getNextNode();
            }
            cout << "nullptr" << endl;
        }
        
        void addElementStart(int x)
        {
            // Create a new node element
            Node* newNode = new Node(x);

            if (head != nullptr)
            {
                newNode->setNextNode(head);
            }
            head = newNode;
        }

        void addElementLast(int x)
        {
            Node *newNode = new Node(x);

            if (head != nullptr)
            {
                Node *ptr = head;
                while (ptr->getNextNode() != nullptr)
                {
                    ptr = ptr->getNextNode();
                }
                ptr->setNextNode(newNode);
            }
            else
            {
                head = newNode;
            }
        }

        void deleteFromStart()
        {
            if (head != nullptr)
            {
                Node *toDelete = head;
                head = head->getNextNode();
                delete toDelete;
            }
        }

        void deleteFromLast()
        {
            if (head != nullptr)
            {
                Node *ptr = head;
                Node *pPtr = nullptr;

                while (ptr->getNextNode() != nullptr)
                {
                    pPtr = ptr;
                    ptr = ptr->getNextNode();
                }
                delete ptr;
                if (pPtr != nullptr)
                    pPtr->setNextNode(nullptr);
            }
        }

        void reverse()
        {
            if (head != nullptr)
            {
                Node *prevNode = nullptr;
                Node *currNode = head;
                Node *nextNode = currNode->getNextNode();

                while (currNode != nullptr)
                {
                    currNode->setNextNode(prevNode);

                    prevNode = currNode;
                    currNode = nextNode;
                    nextNode = nextNode != nullptr ? nextNode->getNextNode() : nullptr;
                }
                head = prevNode;
            }
        }
};

int main()
{
    Linked myLinkedList;

    // Use addElementStart
    myLinkedList.addElementStart(5);
    myLinkedList.addElementStart(6);
    myLinkedList.addElementStart(7);
    myLinkedList.addElementStart(8);

    // Use addElementLast
    myLinkedList.addElementLast(4);
    myLinkedList.addElementLast(3);
    myLinkedList.addElementLast(2);
    myLinkedList.addElementLast(1);

    myLinkedList.listElements();

    // Use deleteFromStart
    myLinkedList.deleteFromStart();
    myLinkedList.listElements();

    // Use deleteFromLast
    myLinkedList.deleteFromLast();
    myLinkedList.listElements();

    myLinkedList.reverse();
    myLinkedList.listElements();

    return 0;
}