/*A library system allows users to borrow and return books. The system should:
1. Add new books to the collection.
2. Borrow books (check availability).
3. Return books.
4. Display all available books.
Requirements:
 Implement a Book class with attributes: ID, title, author, availability.
 Implement a Library class with:
1. Method to add a book (with unique ID).
2. Method to borrow a book (updates availability).
3. Method to return a book (marks it available).
4. Method to display all available books.
 Store book records dynamically using pointers and DMA.
 Use constructor overloading to initialize books with or without availability status.*/


#include <iostream>
using namespace std;

class Book {
public:
    int ID;
    string title;
    string author;
    bool isAvailable;
    Book* next; // Pointer to next book in the list

    // Constructor with default availability
    Book(int id, string t, string a, bool available = true) {
        ID = id;
        title = t;
        author = a;
        isAvailable = available;
        next = nullptr;
    }
};

class Library {
private:
    Book* head; // Pointer to the first book

public:
    Library() { head = nullptr; }

    ~Library() {
        Book* current = head;
        while (current) {
            Book* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Add a new book
    void addBook(int id, string title, string author) {
        Book* newBook = new Book(id, title, author);
        newBook->next = head;
        head = newBook;
    }

    // Borrow a book
    void borrowBook(int id) {
        Book* current = head;
        while (current) {
            if (current->ID == id && current->isAvailable) {
                current->isAvailable = false;
                cout << "You have borrowed: " << current->title << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Book not available or does not exist.\n";
    }

    // Return a book
    void returnBook(int id) {
        Book* current = head;
        while (current) {
            if (current->ID == id && !current->isAvailable) {
                current->isAvailable = true;
                cout << "You have returned: " << current->title << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Invalid return attempt.\n";
    }

    // Display available books
    void displayAvailableBooks() {
        cout << "\nAvailable Books:\n";
        Book* current = head;
        while (current) {
            if (current->isAvailable) {
                cout << "ID: " << current->ID << ", Title: " << current->title << ", Author: " << current->author << "\n";
            }
            current = current->next;
        }
    }
};

int main() {
    Library library;
    int bookID;
    string title, author;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add a new book\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Display available books\n";
        cout << "5. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
            case 1:
                cout << "Enter book ID: ";
                cin >> bookID;
                cin.ignore(); // Ignore newline character from previous input
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(bookID, title, author);
                cout << "Book added successfully!\n";
                break;
            case 2:
                cout << "Enter book ID to borrow: ";
                cin >> bookID;
                library.borrowBook(bookID);
                break;
            case 3:
                cout << "Enter book ID to return: ";
                cin >> bookID;
                library.returnBook(bookID);
                break;
            case 4:
                library.displayAvailableBooks();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
