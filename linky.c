#include <stdio.h>
#include <stdlib.h>
  typedef struct node {
    int val;
    struct node * next;
  } node_t;


   void print_list(node_t* head){
  node_t * temp = head;
  while(temp!=NULL){
    printf("%d\n" , temp->val);
    temp =temp->next;
  }
}


  node_t * insert_front(node_t *head, int x){
    if(head == NULL){
      head->val = x;
      head->next= NULL;
      return head;
    }
    else{
    node_t * temp = malloc(sizeof(node_t));
    temp->val = x;
    temp->next = head;
    return temp;
  }
  }


node_t * free_list(node_t * head){
  node_t * current = head;
  node_t * temp;
  while(current != NULL){
    temp = current->next;
    free(current);
    current = temp;
  }
  return current;
}

  int main(){
    node_t * head = malloc(sizeof(node_t));
//so apparently you have to define the first node fisrt or it justprints out memory addresses endlessly fuck this shit

head->val = 111111;
head->next = NULL;
head = insert_front(head,1);
  head = insert_front(head,2);
  head = insert_front(head,3);

  head = insert_front(head,4);
  head = insert_front(head,5);


    print_list(head);
    head = free_list(head);
printf("printing after freeing list: \n" );
print_list(head);

  }
