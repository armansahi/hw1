/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
using namespace std;

void printLinked(Node* head) {
  while(head->next != nullptr) {
    cout << head->value << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

int main(int argc, char* argv[])
{
  Node* head = new Node(2, new Node(3, new Node(4, new Node(3, new Node, new Node(6, new Node(7, new Node(2, new Node(nullptr))))))));

  Node* odds = nullptr;
  Node* evens = nullptr;

  cout << "Original list: ";
  printLinked(head);

  cout << "Odds: ";
  printLinked(odds);

  cout << "Evens: ";
  printLinked(evens);
}
