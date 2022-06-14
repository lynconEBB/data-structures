#include <malloc.h>
#include "BinaryTree.h"

int isEmpty(Stack *s) {
    return (s == NULL);
}

Stack *push(Stack *s, int data) {
    Stack *head = malloc(sizeof(Stack));
    head->next = s;
    return head;
}

Stack *pop(Stack *s) {
    if (!isEmpty(s)) {
        Stack *toBeDeleted = s;
        s = s->next;
        free(toBeDeleted);
    }
    return s;
}

int empty(Tree t) {
    return (t == NULL);
}

Tree insert(Tree t, int info) {
    Tree root = t;
    Tree prev = NULL;

    Tree nt = malloc(sizeof(Tree));
    nt->info = info;
    nt->left = NULL;
    nt->right = NULL;

    if (empty(t))
        return nt;

    while (!empty(t)) {
        prev = t;
        if (t->info > info)
            t = t->left;
        else
            t = t->right;
    }

    if (prev->info > info)
        prev->left = nt;
    else
        prev->right = nt;

    return root;
}

Tree rec_insert(Tree t, int info) {
    if (empty(t)) {
        Tree nt = malloc(sizeof(Tree));
        nt->info = info;
        nt->left = NULL;
        nt->right = NULL;
        return nt;
    }

    if (info > t->info)
        t->right = rec_insert(t->right, info);
    else
        t->left = rec_insert(t->left, info);

    return t;
}

Tree removeNode(Tree t, int info) {
    Tree root = t;
    Tree prev = NULL;

    while (!empty(t) && t->info != info) {
        prev = t;
        if (info > t->info)
            t = t->right;
        else if (info < t->info)
            t = t->left;
    }

    if (empty(t))
        return root;

    Tree nt = NULL;
    if (empty(t->left) || empty(t->right)) {

        if (empty(t->left))
            nt = t->right;
        else
            nt = t->left;

        if (empty(prev))
            return nt;

        if (prev->left == t)
            prev->left = nt;
        else
            prev->right = nt;

        free(t);
    } else {
        Tree temp = NULL;
        Tree t2 = t->left;
        while (!empty(t2->right)) {
            temp = t2;
            t2 = t2->right;
        }

        if (empty(temp))
            t->left = NULL;
        else
            temp->right = NULL;

        t->info = t2->info;
        free(t2);
    }

    return root;
}

Tree rec_removeNode(Tree t, int info) {
    if (empty(t))
        return NULL;

    if (info < t->info)
        t->left = rec_removeNode(t->left, info);
    else if (info > t->info)
        t->right = rec_removeNode(t->right, info);
    else {
        Tree toBeRemoved = t;
        if (empty(t->left)) {
            t = t->right;
            free(toBeRemoved);
        } else if (empty(t->right)) {
            t = t->left;
            free(toBeRemoved);
        } else {
            t->info = rec_max(t->left)->info;
            t->left = rec_removeNode(t->left, t->info);
        }
    }
    return t;
}

Tree min(Tree t) {
    Tree prev = NULL;
    while (!empty(t)) {
        prev = t;
        t = t->left;
    }
    return prev;
}

Tree max(Tree t) {
    Tree prev = NULL;
    while (!empty(t)) {
        prev = t;
        t = t->right;
    }
    return prev;
}

Tree rec_min(Tree t) {
    if (!empty(t) && !empty(t->left))
        return rec_min(t->left);
    return t;
}

Tree rec_max(Tree t) {
    if (!empty(t) && !empty(t->right))
        return rec_min(t->right);
    return t;
}

void rec_inFixPrint(Tree t) {
    if (!empty(t)) {
        rec_inFixPrint(t->left);
        printf("%d ", t->info);
        rec_inFixPrint(t->right);
    }
}

void rec_preFixPrint(Tree t) {
    if (!empty(t)) {
        printf("%d ", t->info);
        rec_preFixPrint(t->left);
        rec_preFixPrint(t->right);
    }
}

void rec_posFixPrint(Tree t) {
    if (!empty(t)) {
        rec_posFixPrint(t->left);
        rec_posFixPrint(t->right);
        printf("%d ", t->info);
    }
}

int height(Tree t) {
    if (empty(t))
        return -1;

    int lHeight = height(t->left);
    int rHeight = height(t->right);

    if (lHeight > rHeight)
        return lHeight + 1;
    else
        return rHeight + 1;
}

int sum(Tree t) {
    if (empty(t))
        return 0;

    return t->info + sum(t->left) + sum(t->right);
}

int isFull(Tree t, int* leafLevel, int currentLevel){
    if(empty(t))
        return 1;

    if(empty(t->left) && empty(t->right)) {
        if (*leafLevel == 0) {
            *leafLevel = currentLevel;
            return 1;
        }
        return *leafLevel == currentLevel;
    }

    return (isFull(t->left, leafLevel, currentLevel+1) && isFull(t->right,leafLevel, currentLevel + 1));
}

int isBinary(Tree t) {
    if(empty(t))
        return 1;

    if (empty(t->left) && empty(t->right))
        return 1;

    if (empty(t->left) || empty(t->right))
        return 0;

    return (isBinary(t->left) && isBinary(t->right));
}

void printByLevel(Tree t) {

}