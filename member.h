#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>

#ifndef MEMBER_CLASS_H
#define MEMBER_CLASS_H

class member
{
public:
int MemberID;
  string name;
  string Address;
  string email;
  vector<int> BorrowedBooks;

  //function to update borrowed books
    void BorrowBook(int bookID) {
        BorrowedBooks.push_back(bookID);
}
};

#endif