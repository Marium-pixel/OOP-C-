#ifndef BOOK_H
#define BOOK_H

#include<string>
using namespace std;

class Book{
    private:
    string title;
    string author;
    string isbn;
    public:
    Book( const string& bktitle, const string& auth, const string& isbnum);

    string getTitle() const;
    string getauthor() const;
    string getisbn() const;




};

#endif
