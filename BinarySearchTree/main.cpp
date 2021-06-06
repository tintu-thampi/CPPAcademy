#include <iostream>
#include "bst.h"

using std::cout;
using std::endl;

int main()
{
    BST b;
    cout << "bst" << endl;
    b.insert(7);
    b.insert(2);
    b.insert(3);
    b.insert(1);
    b.insert(5);
    b.insert(6);
    b.insert(4);

    b.display();

    b.display(2);

    b.display(3);
    return 0;
}
