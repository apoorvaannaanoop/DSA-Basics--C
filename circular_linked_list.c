#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int roll;
    char name[31];
    float marks;
    struct Node* next;
};
struct Node *CREATENODE(int r,char n[],float y) {
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->roll=r;
    strcpy(newNode->name,n);
    newNode->marks=y;
    newNode->next=NULL;
    return newNode;
}

struct Node* INSERTEND(struct Node*L,int r,char n[],float y) {
    struct Node* newNode=CREATENODE(r,n,y);
    if(L==NULL){
        newNode->next=newNode; 
        return newNode;
    }
    struct Node* temp=L;
    while (temp->next!=L) {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=L;
    return L;
}
struct Node* DELETENODE(struct Node* L,int r) {
    if (L==NULL) {
        printf("-1\n");
        return NULL;
    }
    struct Node *curr=L,*prev=NULL;
    do {
        if(curr->roll==r) break;
        prev=curr;
        curr=curr->next;
    } while(curr!=L);
    if(curr->roll!=r) {
        printf("-1\n");
        return L;
    }
    printf("%d %s %.1f\n",curr->roll,curr->name,curr->marks);
    if (curr->next==L&&prev==NULL) {
        free(curr);
        return NULL;
    }
    if(curr==L){
        struct Node* tail=L;
        while(tail->next!=L)tail=tail->next; 
        L=L->next;
        tail->next=L; 
        free(curr);
    } 
    else {
        prev->next=curr->next;
        free(curr);
    }
    return L;
}
void DISPLAY(struct Node* L) {
    if (L==NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp=L;
    do {
        printf("%d %s %.1f\n", temp->roll, temp->name, temp->marks);
        temp=temp->next;
    } while(temp!=L);
}
void SEARCH(struct Node* L,int r) {
    if (L==NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp=L;
    do {
        if (temp->roll==r) {
            printf("%d %s %.1f\n",temp->roll,temp->name,temp->marks);
            return;
        }
        temp=temp->next;
    } while(temp!=L);
    printf("-1\n");
}
int main() {
    struct Node* L=NULL;
    char choice;
    int r;
    char n[31];
    float y;

   while (scanf(" %c",&choice) == 1){
        switch (choice) {
            case 'i':
                scanf("%d%s%f",&r,n,&y);
                L=INSERTEND(L,r,n,y);
                break;
            case 'd':
                scanf("%d",&r);
                L=DELETENODE(L,r);
                break;
            case 'D':
                DISPLAY(L);
                break;
            case 's':
                scanf("%d",&r);
                SEARCH(L,r);
                break;
            case 'e':return -1;
            default:break;
        }
    }
    return 0;
}
