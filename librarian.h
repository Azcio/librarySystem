#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>
#include "Person.h"

#ifndef LIBRARIAN_CLASS_H
#define LIBRARIAN_CLASS_H

class librarian
{
public:
  int StaffID;
  string name;
  string Address;
  string email;
  string salary;

};

vector<Person> existingMembers;

void AddMember(vector<Person>& existingMembers);
void DisplayMembers(vector<Person>& existingMembers);
void DisplayChosenBooks(string EnterFile, const string& targetBookId, vector<Person>& existmembers);
void DisplayAllBooks(string EnterFile);

#endif