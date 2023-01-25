#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to store library book information
struct Book
{
    string title;
    string ISSN;
    string publisher;
    float cost;
};

// Function to enter new book record
void enterRecord(Book &book)
{
    cout << "Enter book title: ";
    cin >> book.title;
    cout << "Enter book ISSN: ";
    cin >> book.ISSN;
    cout << "Enter book publisher: ";
    cin >> book.publisher;
    cout << "Enter book cost: ";
    cin >> book.cost;
}

// Function to retrieve book details
void retrieveRecord(Book book)
{
    cout << "Book title: " << book.title << endl;
    cout << "Book ISSN: " << book.ISSN << endl;
    cout << "Book publisher: " << book.publisher << endl;
    cout << "Book cost: " << book.cost << endl;
}

// Function to issue book to student
void issueBook(string studentName, Book &book)
{
    cout << "Book " << book.title << " is issued to " << studentName << endl;
    book.ISSN = "";
    book.title = "";
    book.publisher = "";
    book.cost = 0;
}

int main()
{
    // Variable to store user choice
    int choice;
    // Variable to store student name
    string studentName;
    // Object of type Book
    Book book;

    while (true)
    {
        cout << "1. Enter new book record" << endl;
        cout << "2. Retrieve book details" << endl;
        cout << "3. Issue book to student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enterRecord(book);
            break;
        case 2:
            retrieveRecord(book);
            break;
        case 3:
            cout << "Enter student name: ";
            cin >> studentName;
            // check if the student had returned the last book
            if (book.ISSN != "")
            {
                issueBook(studentName, book);
            }
            else
            {
                cout << "Student did not return the last book." << endl;
            }
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
