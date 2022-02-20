#include<bits/stdc++.h>
using namespace std;

#include "BST.h"

int main()
{
    Node * root = NULL;
    int nodes;
    cout << "Enter the  number of nodes : " ;
    cin >> nodes;

    for (int i=0; i<nodes; i++) {
        int val;
        cin >> val;
        root = addNode(val, root);
    }

    traverseLevel(root);

    return 0;
}