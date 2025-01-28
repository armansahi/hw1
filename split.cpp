/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == nullptr) {
    return; // list is empty stop recursion
  }
  Node* next = in->next; // save reference to next node
  if (in->value % 2 == 0) { // check for even value
    if (evens == nullptr) { // if even list is empty
      evens= in; // initialize with current node
    }
    else {
      Node* temp = evens; 
      while (temp->next != nullptr) {
        temp = temp->next; 
      }
      temp->next = in; // traverse to last node, attatch in at end
    }
    in->next = nullptr;
  }
  else {
    if (odds == nullptr) {
      odds = in; // if odd list empty, initialize with curr node
    }
    else {
      Node* temp = odds;
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = in; // traverse to last node, push in at end
    }
    in->next = nullptr; // before recursion pop curr node from original list
  }
  in = nullptr; // nullify in so doesnt point to original list
  split(next,odds,evens); // recursion
}

/* If you needed a helper function, write it here */
