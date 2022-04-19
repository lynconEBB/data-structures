#include <stdio.h>
#include "BinaryTree/BinaryTree.h"

int main (void)
{
    Tree t = insert(NULL, 11);
    t = insert(t, 14);
    t = insert(t, 22);
    t = insert(t, 15);
    t = insert(t, 5);
    t = insert(t, 2);
    t = insert(t, 8);
    printf("%d\n", countLeafs(t));

    return 0;
}