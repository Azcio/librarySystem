#include <iostream>
#include <fstream> //Allows header files to be used/reads other files
#include <vector>
using namespace std;
#include "Person.h"
#include "librarian.h"

//char to prompt librarian to start the program or not
char start;

//String: the user will enter the file that will be used in the program
string EnterFile;

//librian chooses the activity/function they want to call
int choice;

string targetBookId;

int main() {

//Prompt the user to start the program
     cout << "Welcome, will you like to use the library system [y/n]: \n";
cin >> start;

        
if (start == 'y') {
    cout << "Welcome Librarian \n";
cout << "Please enter the file that contains the book data: \n";
cin >> EnterFile;

//Open the inputted file
ifstream inputFile(EnterFile);

//check to see if the file can be opened
if (inputFile.is_open())                                
{
    cout << "The file " << EnterFile << " can be read \n";
} else {
    cout << " The File " << EnterFile << " cannot be read \n";
}

do
{
    cout << "What would you like to do: \n";
//options of things to do
cout << "1. Add a member \n";
cout << "2. See the Number of members \n";
cout << "3. Issue book to member \n";
cout << "4. Display all books in system \n";
cout << "5. Close the program \n";

cin >> choice;

//call the function that the librian chooses

switch (choice)
{
case 1:
    AddMember(existingMembers);
    break;

case 2:
DisplayMembers(existingMembers);
    break;

case 3:
cout << "Please enter the book ID you are looking for \n";
cin >> targetBookId;
DisplayChosenBooks(EnterFile, targetBookId, existingMembers);
break;

case 4: 
    DisplayAllBooks(EnterFile);
    break;

case 5:
return 0;
}
} while (choice != 5);


} else if (start == 'n') { //if the user enters n when being prompt to start the system/code then the code will end
    cout << "You chose to not use the system \n";
    return 0; //end the program if user enters n
} while (start != 'y' && start != 'n') //if the user enters a value that isn't y or n then they will be asked to continue entering a input until it's n or y
{
    cout << "You entered a invalid value. Please enter Y or N \n";
    cin >> start;
}

    }
