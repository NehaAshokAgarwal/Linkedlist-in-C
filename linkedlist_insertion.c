#include <stdio.h>
#include <stdlib.h>

// building a linkedList-
struct Node{
    int data;
    struct Node *next;

};

struct Node* insertATFirst(struct Node *head, int data){
  /*  // constructed a new node with the given data.
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    // then i am saying is that the the new node is pointing to the
    // head.
    ptr->next = head;
    // new node's data is the data given.
    ptr->data = data;
    // retuning the new head.
    return ptr;
};
    */
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr = head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = data;
    head->next = ptr;
};

void insertAtIndex(struct Node *head, int data, int index){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

struct Node* insertAtEnd(struct Node *head, int data){

    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
     struct Node *p = head;
     ptr->data = data;
     while(p->next != NULL){
        p = p->next;
     }

     p->next = ptr;
     ptr->next = NULL;
     return head;
};

struct Node* insertAfter(struct Node *head, struct Node* p, int data){

    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = p->next;
     p->next = ptr;
    return head;
};

struct Node* deletingAtFirst(struct Node * head){
    // My code
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

struct Node* deletingInBetween(struct Node* head, int index){
    struct Node* p = head;
    int i = 0;

    while(i != (index-1)){
        p = p->next;
        i++;
    }

    struct Node* q = p->next;
    p->next = q->next;
    free(q);
    return head;
};

struct Node* deleteingLastNode(struct Node* head){
    struct Node* p = head;
    struct Node*q = head->next;
    while(q->next != NULL){
            q = q->next;
            p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

struct Node* deletingAfetr(struct Node* head, int value){
    struct Node* ptr = head;
    struct Node* q = head->next;
    while(q->data!=NULL && q->next!=NULL){
        ptr = ptr->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
    }
    free(q);
    return head;
};

void linkedtraversal(struct Node *ptr){
    while(ptr!= NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node*second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));


    head->data = 89;
    head->next = second;

    second->data = 87;
    second->next = third;

    third->data = 70;
    third->next = fourth;

    fourth->data = 78;
    fourth->next = NULL;

    head = deletingInBetween(head, 2);
    linkedtraversal(head);
    return 0;
}
