#include "Book.h"

using namespace std;


Book::Book(const string& bktitle, const string& auth, const string& isbnum)
: title(bktitle), author(auth), isbn(isbnum) {}

string Book::getTitle() const {
    return title;
}

string Book::getauthor() const {
    return author;
}

string Book::getisbn() const{
    return isbn;
}
