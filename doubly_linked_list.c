#include <stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
    struct node *prev;
};

struct node *CREATENODE(int k)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->key=k;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void LISTINSERTFRONT(struct node **L,struct node *x)
{
   x->next=*L;

   if(*L!=NULL)
   (*L)->prev=x;

   *L=x;
   x->prev=NULL;
}

struct node *LISTINSERTTAIL(struct node **L,struct node *x)
{
   if(x==NULL)return *L;

   if(*L==NULL) {
        *L=x;
        x->prev=NULL;
        x->next =NULL;
        return *L;
    }

    struct node *temp=*L;

    while(temp->next!=NULL){
       temp=temp->next;
    }

    x->prev=temp;
    temp->next=x;
    x->next=NULL;

    return *L;
}

void LISTINSERTAFTER(struct node **L, struct node *x, struct node *y)
{
   if(y==NULL)return;

   x->next=y->next;
   x->prev=y;

   if(y->next!=NULL){
       y->next->prev=x;
   }

   y->next=x;
}

void LISTINSERTBEFORE(struct node **L, struct node *x, struct node *y)
{
    if (y==NULL||x==NULL) return;

    x->next=y;
    x->prev=y->prev;

    if(y->prev!=NULL){
        y->prev->next=x;
    }
    else{
        *L=x;
    }

    y->prev=x;
}

void LISTDELETE(struct node**L,struct node* x)
{
    if(x==NULL) return;

    if(x->prev!=NULL){
        x->prev->next=x->next;
    }
    else {
        *L=x->next;
    }

    if(x->next!=NULL){
        x->next->prev=x->prev;
    }

    printf("%d\n",x->key);
    free(x);
}

void LISTDELETEINITIAL(struct node**L)
{
    if(*L==NULL){
        printf("-1\n");
        return;
    }

    LISTDELETE(L,*L);
}

void LISTDELETELAST(struct node**L)
{
    if (*L==NULL) {
        printf("-1\n");
        return;
    }

    struct node*curr=*L;

    while(curr->next!=NULL)
        curr=curr->next;

    LISTDELETE(L,curr);
}

struct node* LISTSEARCH(struct node* L, int k)
{
    struct node* pt =L;

    while (pt!= NULL) {
        if (pt->key==k)
            return pt;

        pt=pt->next;
    }

    return NULL;
}

int main()
{
    struct node*L = NULL;
    char ch;
    int k, k2;

    while(scanf(" %c",&ch))
    {
        switch(ch)
        {
            case 'f':
            {
                scanf("%d",&k);
                LISTINSERTFRONT(&L,CREATENODE(k));
                break;
            }

            case 't':
            {
                scanf("%d",&k);
                LISTINSERTTAIL(&L,CREATENODE(k));
                break;
            }

            case 'a':
            {
                scanf("%d%d",&k,&k2);

                struct node* target=LISTSEARCH(L,k2);

                if(target)
                    LISTINSERTAFTER(&L, CREATENODE(k),target);

                break;
            }

            case 'b':
            {
                scanf("%d%d",&k,&k2);

                struct node* target1=LISTSEARCH(L,k2);

                if(target1)
                    LISTINSERTBEFORE(&L,CREATENODE(k), target1);

                break;
            }

            case 'd':
            {
                scanf("%d",&k);

                struct node* deltnode =LISTSEARCH(L, k);

                if(deltnode)
                    LISTDELETE(&L,deltnode);
                else
                    printf("-1\n");

                break;
            }

            case 'i':
            {
                LISTDELETEINITIAL(&L);
                break;
            }

            case 'l':
            {
                LISTDELETELAST(&L);
                break;
            }

            case 's':
            {
                scanf("%d",&k);

                if (LISTSEARCH(L,k))
                    printf("2\n");
                else
                    printf("1\n");

                break;
            }

            case 'e':
            {
                return -1;
            }

            default:
            {
                break;
            }
        }
    }

    return 0;
}
