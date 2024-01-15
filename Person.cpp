#include <iostream>
using namespace std;
#include <unordered_set>
#include <vector>
#include "PersonClass.h"

//Set of already added Members/New members will be stored here
unordered_set<int> addedMembers;

void AddMember(vector<Person>& existingMembers) {

//making a new member variable when function called
Person NewMember;

//Ask Librian for New Members ID/Issue an ID
cout << "Issue a Member ID: \n";
cin >> NewMember.MemberID; //Input the MemberID of this person that will be in NewMember

//check if the inputted MemberID is already being used
while (addedMembers.count(NewMember.MemberID) > 0)
{
    cout << "This Member ID has already been used. Please use a new member ID: \n";
    cin >> NewMember.MemberID;
}
addedMembers.insert(NewMember.MemberID);

cin.ignore(); //Code will ignore the newline

cout << "Enter this member's name: \n";
getline(cin, NewMember.name); //Inputted name is saved for person in NewMember

cout << "Enter this Member's address: \n";
getline(cin, NewMember.Address); 

cout << "Enter this Member's email address: \n";
cin >> NewMember.email;

NewMember.BorrowedBooks = {};

//Display the Person's/new member details
cout << "Member Details: \n";  
cout << "Member ID: " << NewMember.MemberID << endl;
cout << "Member Name: " << NewMember.name <<endl; 
cout << "Member Address: " << NewMember.Address << "\n";
cout << "Member Email: " << NewMember.email << "\n";
cout << "Borrowed Books: ";
for (int i = 0; i < NewMember.BorrowedBooks.size(); ++i){
    cout << NewMember.BorrowedBooks[i] << "\n ";
}
   if (NewMember.BorrowedBooks.empty())
    {
        cout << "This member has no borrowed books \n";
    }

 // Add the new member to the existing members vector
    existingMembers.push_back(NewMember);

}

void DisplayMembers(vector<Person>& existingMembers) {
    cout << "All members in the system: \n";
    for ( auto& member : existingMembers )
    {
        cout << "Member ID: " << member.MemberID << "\n"; 
        cout << "Member Name: " << member.name << "\n";
        cout << "Member Address: " << member.Address << "\n";
        cout << "Member Email: " << member.email << "\n";
        cout << "Borrowed Book ID's: ";
        
        if (member.BorrowedBooks.empty()) {
            cout << "This member has no borrowed books \n";
        } else {
            for (const auto& book : member.BorrowedBooks) {
                cout << book << "\n";
            }
        }

 cout << "\n";

    }
    
}