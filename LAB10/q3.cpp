#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BookCombiner {
private:
    string chapter1File;
    string chapter2File;
    string bookFile;

public:
    BookCombiner(const string& ch1, const string& ch2, const string& book)
        : chapter1File(ch1), chapter2File(ch2), bookFile(book) {}

    void createChaptersIfMissing() {
        ifstream ch1(chapter1File);
        if (!ch1) {
            ofstream create1(chapter1File);
            create1 << "This is Chapter 1.\nIt introduces the story.\n";
            create1.close();
            cout << "Created " << chapter1File << " with sample content.\n";
        } else {
            ch1.close();
        }

        ifstream ch2(chapter2File);
        if (!ch2) {
            ofstream create2(chapter2File);
            create2 << "This is Chapter 2.\nThe story continues.\n";
            create2.close();
            cout << "Created " << chapter2File << " with sample content.\n";
        } else {
            ch2.close();
        }
    }

    void combineChapters() {
        ifstream chapter1(chapter1File);
        ifstream chapter2(chapter2File);
        ofstream book(bookFile, ios::app);

        if (!chapter1 || !chapter2 || !book) {
            cerr << "Error opening one or more files." << endl;
            return;
        }

        string line;
        book << "--- " << chapter1File << " ---\n";
        while (getline(chapter1, line)) {
            book << line << endl;
        }
        book << endl;

        book << "--- " << chapter2File << " ---\n";
        while (getline(chapter2, line)) {
            book << line << endl;
        }
        book << "\n\n";

        chapter1.close();
        chapter2.close();
        book.close();
    }

    void displayBook() const {
        ifstream book(bookFile);
        if (!book) {
            cerr << "Error opening book file for reading." << endl;
            return;
        }

        cout << "\n--- Book Contents ---\n";
        string line;
        while (getline(book, line)) {
            cout << line << endl;
        }

        book.close();
    }
};

int main() {
    BookCombiner combiner("chapter1.txt", "chapter2.txt", "book.txt");

    combiner.createChaptersIfMissing();
    combiner.combineChapters();
    combiner.displayBook();

    return 0;
}
