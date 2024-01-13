#include <iostream>
#include <fstream>
using namespace std;

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

void DisplayChosenBooks(string EnterFile, const string& targetBookId) {
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

            // Stop searching after finding the book
            break;
        }
}
bookFile.close();

//prompt user to enter Member ID that the book is being issued
int MemberID;

cout << "Enter the Member ID that the book is being issued to: \n";
cin >> MemberID;

while (MemberID <= 0)
{
    cout << "You entered a invalid ID. Re-enter a Member ID \n";
    cin >> MemberID;
}

}