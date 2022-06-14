#include <stdio.h>
#include "TrieTree.h"
#include <stdlib.h>

int main (void)
{
    TstNode* t = insert_tst(NULL, "cacete", 10);
    t = insert_tst(t, "caramba", 30);
    t = insert_tst(t, "zuzuba", 40);
    t = insert_tst(t, "zona", 20);
    t = insert_tst(t, "zon", 100);
    printDictionary_tst(t);
    t = removeOne_tst(t,"caramba");
    t = removeOne_tst(t,"cacete");
    printf("=============\n");
    printDictionary_tst(t);
    return 0;
}
