#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if (head == NULL){
    return;
  }
  Node* temp = head->next;
  if(head->val <= pivot){
    head->next = smaller;
    smaller = head;
    head = temp;
    llpivot(head, smaller, larger, pivot);
  }
  else{
    head->next = larger;
    larger = head;
    head = temp;
    llpivot(head, smaller, larger, pivot);
  }
}
