#include <bits/stdc++.h>
Node *reverse(Node *&head) {
  Node *prev = NULL;
  Node *curr = head;
  while (curr != NULL) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
void add(Node *&head, Node *&tail, int data) {
  Node *n1 = new Node(data);
  if (head == NULL) {
    head = n1;
    tail = n1;
  } else {
    tail->next = n1;
    tail = n1;
  }
}
Node *addTwoLL(Node *head1, Node *head2) {
  Node *ptr1 = head1;
  Node *ptr2 = head2;
  Node *head = NULL;
  Node *tail = NULL;
  int carry = 0;
  while (ptr1 != NULL || ptr2 != NULL || carry != 0) {
    int first = 0, second = 0;
    if (ptr1 != NULL) {
      first = ptr1->data;
    }
    if (ptr2 != NULL) {
      second = ptr2->data;
    }
    int sum = carry + second + first;
    int digit = sum % 10;
    carry = sum / 10;
    add(head, tail, digit);
    if (ptr1 != NULL) {
      ptr1 = ptr1->next;
    }
    if (ptr2 != NULL) {
      ptr2 = ptr2->next;
    }
  }

  head = reverse(head);
  return head;
}
Node *addFirstAndSecondHalf(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  int count = 0;
  Node *ptr = head;
  while (ptr != NULL) {
    count++;
    ptr = ptr->next;
  }
  Node *head1 = NULL;
  Node *head2 = NULL;
  Node *tail1 = NULL;
  Node *tail2 = NULL;

  int mid = count / 2;
  ptr = head;
  if (count & 1) {
    for (int i = 0; i <= mid; i++) {
      add(head1, tail1, ptr->data);
      ptr = ptr->next;
    }
  } else {
    for (int i = 0; i < mid; i++) {
      add(head1, tail1, ptr->data);
      ptr = ptr->next;
    }
  }
  while (ptr != NULL) {
    add(head2, tail2, ptr->data);
    ptr = ptr->next;
  }
  head1 = reverse(head1);
  head2 = reverse(head2);
  Node *anshead = addTwoLL(head1, head2);
  while(anshead->data==0&&anshead->next!=NULL){
    anshead=anshead->next;
  }
  return anshead;
}