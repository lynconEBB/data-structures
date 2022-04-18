#include <stdio.h>
#include "BinaryTree/BinaryTree.h"

int main (void)
{
    Tree t = insert(NULL, 11);
    t = insert(t, 5);
    t = insert(t, 2);
    t = insert(t, 8);
    t = insert(t, 9);
    t = insert(t, 19);
    t = insert(t, 13);
    t = insert(t, 22);
    t = insert(t, 20);
    t = insert(t, 27);
    t = insert(t, 25);
    rec_inFixPrint(t);
    printf("\n");
    t = rec_removeNode(t, 8);
    rec_inFixPrint(t);
    t = rec_removeNode(t,27);
    return 0;
}