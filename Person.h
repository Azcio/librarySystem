#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>

#ifndef PERSON_CLASS_H
#define PERSON_CLASS_H

class Person
{
public:
  string name;
  string Address;
  string email;
  int MemberID;
  vector<int> BorrowedBooks;

  //function to update borrowed books
    void BorrowBook(int bookID) {
        BorrowedBooks.push_back(bookID);
}
};

extern unordered_set<int> addedMembers;

#endif
