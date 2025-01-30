#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;
int main(int argc, char* argv[])
{
  ULListStr mylist;

  mylist.push_back("Hello");
  cout << "Added 'Hello' to the list";

  if(mylist.size() == 1 && mylist.back() == "Hello") {
    cout << "Pass";
  }
  else {
    cout << "Fail";
  }

  mylist.pop_back();
  cout << "Removed element from list";

  if(mylist.empty()) {
    cout << "Pass";
  }
  else {
    cout << "Fail";
  }
  return 0;
}
