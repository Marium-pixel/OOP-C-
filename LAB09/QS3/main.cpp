#include <iostream>
#include  "Book.h"

using namespace std;

 int main(){
    Book book1("Harry Potter","JK Rowling", "939393939393");

    cout<<"Book Title:"<<book1.getTitle()<<endl;
    cout<<"Author: "<<book1.getauthor()<<endl;
    cout<<"ISBN:"<<book1.getisbn()<<endl;

    return 0;
 }
//to run:  g++ -o library main.cpp Book.cpp, ./library.exe
