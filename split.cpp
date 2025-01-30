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
  Node* curr = in; // save reference to next node, detatch curr node
  in = in->next;
  curr->next = nullptr;

  if (curr->value % 2 == 0) {
    if (evens == nullptr) {
      evens = curr; // initialize evens if empty
    }
    else {
      curr->next = evens; // link new node with curr front of evens
      evens = curr; // update front of evens list
    }
  }
  else {
    if (odds == nullptr) {
      odds = curr; // initialize odds if empty
    }
    else {
      curr->next = odds; // link new node with curr front of odd
      odds = curr; // update front of odds list
    }
  }
  split(in, odds, evens); // recursive call
}

/* If you needed a helper function, write it here */
