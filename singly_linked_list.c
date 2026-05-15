```c
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *CREATENODE(int k)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->key = k;
    newnode->next = NULL;
    return newnode;
}

void LISTINSERTFRONT(struct node **L, struct node *x)
{
    x->next = *L;
    *L = x;
}

void LISTINSERTTAIL(struct node **L, struct node *x)
{
    struct node **pt = L;
    while (*pt != NULL) {
        pt = &((*pt)->next);
    }
    *pt = x;
}

void LISTINSERTAFTER(struct node *y, struct node *x)
{
    if (y == NULL) return;
    x->next = y->next;
    y->next = x;
}

void LISTINSERTBEFORE(struct node **L, struct node *x, struct node *y)
{
    if (y == NULL) return;

    struct node **pt = L;

    while (*pt != NULL && *pt != y) {
        pt = &((*pt)->next);
    }

    if (*pt == y) {
        x->next = y;
        *pt = x;
    }
}

void LISTDELETEFIRST(struct node **L)
{
    if (*L == NULL) {
        printf("1\n");
        return;
    }

    struct node *temp = *L;
    printf("%d\n", temp->key);
    *L = (*L)->next;
    free(temp);
}

void LISTDELETELAST(struct node **L)
{
    if (*L == NULL) {
        printf("1\n");
        return;
    }

    if ((*L)->next == NULL) {
        printf("%d\n", (*L)->key);
        free(*L);
        *L = NULL;
        return;
    }

    struct node *temp = *L;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("%d\n", temp->next->key);
    free(temp->next);
    temp->next = NULL;
}

void LISTDELETE(struct node **L, struct node *x)
{
    if (*L == NULL || x == NULL) {
        printf("1\n");
        return;
    }

    struct node **pt = L;

    while (*pt != NULL && *pt != x) {
        pt = &((*pt)->next);
    }

    if (*pt == x) {
        printf("%d\n", x->key);
        *pt = x->next;
        free(x);
    }
}

struct node *LISTSEARCH(struct node *L, int k)
{
    struct node *temp = L;

    while (temp != NULL) {
        if (temp->key == k) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int main()
{
    struct node *L = NULL;
    char ch;
    int k, k2;

    if (scanf(" %c", &ch) == EOF) return 0;

    while (1) {
        switch (ch) {

            case 'a':
                scanf("%d", &k);
                LISTINSERTFRONT(&L, CREATENODE(k));
                break;

            case 'b':
                scanf("%d", &k);
                LISTINSERTTAIL(&L, CREATENODE(k));
                break;

            case 'c':
                scanf("%d %d", &k, &k2);
                LISTINSERTAFTER(LISTSEARCH(L, k2), CREATENODE(k));
                break;

            case 'd':
                scanf("%d %d", &k, &k2);
                LISTINSERTBEFORE(&L, CREATENODE(k), LISTSEARCH(L, k2));
                break;

            case 'e':
                scanf("%d", &k);
                LISTDELETE(&L, LISTSEARCH(L, k));
                break;

            case 'f':
                LISTDELETEFIRST(&L);
                break;

            case 'g':
                LISTDELETELAST(&L);
                break;

            case 'h':
                scanf("%d", &k);
                if (LISTSEARCH(L, k))
                    printf("2\n");
                else
                    printf("1\n");
                break;

            case 'i':
                return 0;
        }

        if (scanf(" %c", &ch) == EOF)
            break;
    }

    return 0;
}
```
