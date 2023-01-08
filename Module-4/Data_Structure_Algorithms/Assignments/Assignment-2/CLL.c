#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void display(struct node* head){
  struct node* current = head;
  if(current == NULL){
    printf("Node is NULL");
  }
  else{
    do{
      printf("%d ",current->data);
      current = current->next;
    }
    while(current != head);
    printf("\n");
  }
}

void newnode(struct node** head, int data){
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  new->next = NULL;
  if(*head == NULL){
    *head = new;
    new->next = *head;
  }
  else{
    struct node* temp = *head;
    while(temp->next != *head){
      temp = temp->next;
    }
    temp->next = new;
    new->next = *head;
  }
}

void insert_first(struct node** head, int data){
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  if(*head == NULL){
    *head = new;
    new->next = *head;
  }
  else{
    struct node* temp = *head;
    new->next = temp;
    while(temp->next != *head){
      temp = temp->next;
    }
    temp->next = new;
    *head = new;
  }
}

void insert_last(struct node** head, int data){
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  if(*head == NULL){
    *head = new;
    new->next = *head;
  }
  else{
    struct node* temp = *head;
    new->next = temp;
    while(temp->next != *head){
      temp = temp->next;
    }
    temp->next = new;
    new->next = *head;
  }
}

void insert_loc(struct node** head, int data, int loc){
  struct node* new = (struct node*)malloc(sizeof(struct node));
  new->data = data;
  struct node* temp = *head;
  for(int i=1;i<loc-1;i++){
    if(temp->next == *head){
      printf("Loc. out of bound || Data: ");
      return;
    }
    else{
      temp = temp->next;
    }
  }
  new->next = temp->next;
  temp->next = new;
}

void deletion_first(struct node** head){
  struct node* temp = *head;
  if(*head == NULL){
    printf("Node is NULL");
  }
  else{
    while(temp->next != *head){
      temp = temp->next;
    }
    temp->next = (*head)->next;
    free(*head);
    *head = temp->next;
  }
}

void deletion_last(struct node** head){
  struct node* temp = *head;
  struct node* prev = NULL;
  if(*head == NULL){
    printf("Node is NULL");
  }
  else{
    while(temp->next != *head){
      prev = temp;
      temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
  }
}
void deletion_loc(struct node** head, int loc){
  struct node* temp = *head;
  struct node* prev = NULL;
  if(*head == NULL){
    printf("Node is NULL");
  }
  else{
    for(int i=0; i<loc-1; i++){
      if(temp->next == *head){
        printf("Loc. out of bound ||  Data: ");
        return;
      }
      else{
        prev = temp;
        temp = temp->next;
      }
    }
    prev->next = temp->next;
    free(temp);
  }
}


int main(){
  struct node* head = NULL;
  
  newnode(&head, 10);
  newnode(&head, 40);
  display(head);

  printf("Insert at First: ");
  insert_first(&head, 50);
  insert_first(&head, 30);
  display(head);

  printf("Insert at last: ");
  insert_last(&head, 60);
  insert_last(&head, 70);
  display(head);

  printf("Insert at Loc: ");
  insert_loc(&head, 90, 2);
  insert_loc(&head, 40, 3);
  display(head);

  printf("Deletion at first: ");
  deletion_first(&head);
  deletion_first(&head);
  display(head);

  printf("Deletion at Last: "); 
  deletion_last(&head);
  deletion_last(&head);
  display(head);

  printf("Deletion at loc: ");
  deletion_loc(&head, 4);
  deletion_loc(&head, 2);
  display(head);

  return 0;
}
