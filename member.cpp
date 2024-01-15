#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

#include "Person.h"

string Bookid;
string BookName;
string pageCount;
string AuthorFirstName;
string AuthorLastName;
string BookType;

void DisplayAllBooks(string EnterFile){
    ifstream bookFile(EnterFile);
    
while (bookFile.good())
{
    getline(bookFile, Bookid, ',' );
    getline(bookFile, BookName, ',');
    getline(bookFile, pageCount, ',');
    getline(bookFile, AuthorFirstName, ',');
    getline(bookFile, AuthorLastName, ',');
    getline(bookFile, BookType, '\n'); //looks for next line in csv file
   
// Display book details
    cout << "Book ID " << Bookid << "\n";            
    cout << "Book name " << BookName << "\n";
    cout << "Page count " << pageCount << "\n";
    cout << "Author: " << AuthorFirstName << " " << AuthorLastName << "\n";
    cout << "Book type " << BookType << "\n";
    cout << "------------------------------------------------------------------------ \n";
}
bookFile.close();
}

void DisplayChosenBooks(string EnterFile, const string& targetBookId, vector<Person>& existmembers) {
ifstream bookFile(EnterFile);

     while (getline(bookFile, Bookid, ',')) {
        getline(bookFile, BookName, ',');
        getline(bookFile, pageCount, ',');
        getline(bookFile, AuthorFirstName, ',');
        getline(bookFile, AuthorLastName, ',');
        getline(bookFile, BookType, '\n'); //looks for the next line in the CSV file

        // Check if the current book ID matches the target ID
        if (Bookid == targetBookId) {
            // Display book details
            cout << "Book ID " << Bookid << "\n";
            cout << "Book name " << BookName << "\n";
            cout << "Page count " << pageCount << "\n";
            cout << "Author: " << AuthorFirstName << " " << AuthorLastName << "\n";
            cout << "Book type " << BookType << "\n";
            cout << "------------------------------------------------------------------------ \n";


//prompt user to enter Member ID that the book is being issued
int MemberID;

cout << "Enter the Member ID that the book is being issued to: \n";
cin >> MemberID;

while (MemberID <= 0)
{
    cout << "You entered a invalid ID. Re-enter a Member ID \n";
    cin >> MemberID;
    } 

               // Check if the member ID exists in the system
            auto it = find_if(existmembers.begin(), existmembers.end(), [MemberID](const Person& member) {
                return member.MemberID == MemberID;
            });

            if (it != existmembers.end()) {
                // Add the book to the member's BorrowedBooks vector
                it->BorrowedBooks.push_back(stoi(Bookid));
                cout << "Book issued successfully to Member ID " << MemberID << "\n";
            } else {
                cout << "Member ID " << MemberID << " not found. Book cannot be issued.\n";
            }

            // Stop searching after finding the book
            break;
        }
}
bookFile.close();

    }