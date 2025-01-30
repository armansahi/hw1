#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if (tail_ == nullptr || tail_->last == ARRSIZE) { // tail node does not exist or full
    Item* newNode = new Item();
    if (head_ == nullptr) {
      head_ = newNode; // if list empty set new node as head
    }
    else {
      tail_->next = newNode; // new node to end of list
      newNode->prev = tail_; // new node previous to tail
    }
    tail_ = newNode; // update tail pointer to new node
  }
  // add val, update pointers
  tail_->val[tail_->last++] = val;
  size_++; // increment size of list
}


void ULListStr::pop_back() {
  if (empty()) {
    return; // do nothing if empty
  }
  tail_->last--; // decrement index of last, removing last element
  size_--; // decrement size of list

  if(tail_->first == tail_->last) { // check if node empty after removing
    Item* temp = tail_; // temp stores node to be deleted
    tail_ = tail_->prev; // move tail back to previous
    if (tail_) {
      tail_->next = nullptr; // null next pointer of new tail
    }
    else {
      head_ = nullptr; // if no tail no head
    }
    delete temp; // delete non empty node
  }
}


void ULListStr::push_front(const std::string& val) {
  if(head_ == nullptr || head_->first == 0) { // check if head node empty or full
    Item* newNode = new Item();
    newNode->first = ARRSIZE; // indices for following operations
    newNode->last = ARRSIZE;
    if(head_ == nullptr) {
      tail_ = newNode; // empty list set new node to tail
    }
    else {
      head_->prev = newNode; // insert new node before curr head
      newNode->next = head_; // new node next to curr head
    }
    head_ = newNode; // head pointer to new node
  }
  
  head_->val[--head_->first] = val; // insert val at pos before curr and decrement first
  size_++; // add size 
}



void ULListStr::pop_front() {
  if(empty()) {
    return; // do nothing if empty 
  }
  head_->first++; // Increment first index, removing front element
  size_--; // decrement size

  if(head_->first == head_->last) { // check if now removed
    Item* temp = head_; // temp store node to be deleted
    head_ = head_->next; // move head to next node
    if (head_) {
      head_->prev = nullptr; // nullify prev pointer of new head
    }
    else {
      tail_ = nullptr; // list empty
    }
    delete temp; // delete non empty node
  }
}

std::string const & ULListStr::back() const {
  if (empty()) {
    throw std::out_of_range("List is empty"); // handle base case
  } 
  return tail_->val[tail_->last - 1]; // return last element
}

std::string const & ULListStr::front() const {
  if (empty()) {
    throw std::out_of_range("List is empty"); // handle base case
  }
  return head_->val[head_->first]; // return first element of head node
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) { // out of bounds
    return nullptr;
  }
  Item* curr = head_; // start with head 
  size_t count = 0; // check elements counted

  while(curr != nullptr) { // iterate over each node
    size_t elements = curr->last - curr->first; // calculate # of elements in curr node
    if(loc < count + elements) { // check if requested loc in curr node
      return &curr->val[curr->first + (loc - count)]; //return pointer to element
    }
    count += elements; // increment count
    curr = curr->next; // move to next node
  }
  return nullptr; // if not found, should not reach this point
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
