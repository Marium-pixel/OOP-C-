#include <iostream>
#include <string>

using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Checked Out: " << (isCheckedOut ? "Yes" : "No") << endl;
    }

    string getTitle() const {
        return title;
    }

    string getPublicationDate() const {
        return publicationDate;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }

    string getAuthor() const {
        return author;
    }
};

class DVD : public Media {
private:
    string director;
    int duration; // Duration in minutes
    string rating;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(string t, string pubDate, string id, string pub, int issue)
        : Media(t, pubDate, id, pub), issueNumber(issue) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class Library {
private:
    Media* mediaCollection[100];
    int mediaCount;

public:
    Library() : mediaCount(0) {}

    void addMedia(Media* media) {
        if (mediaCount < 100) {
            mediaCollection[mediaCount] = media;
            mediaCount++;
        } else {
            cout << "Library is full." << endl;
        }
    }

    void searchByTitle(const string& title) const {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getTitle() == title) {
                mediaCollection[i]->displayInfo();
            }
        }
    }

    void searchByAuthor(const string& author) const {
        for (int i = 0; i < mediaCount; i++) {
            Book* book = dynamic_cast<Book*>(mediaCollection[i]);
            if (book && book->getAuthor() == author) {
                book->displayInfo();
            }
        }
    }

    void searchByPublicationDate(const string& pubDate) const {
        for (int i = 0; i < mediaCount; i++) {
            if (mediaCollection[i]->getPublicationDate() == pubDate) {
                mediaCollection[i]->displayInfo();
            }
        }
    }
};

int main() {
    Library library;

    Book book1("The Great Gatsby", "1925", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD dvd1("Inception", "2010", "D001", "Warner Bros.", "Christopher Nolan", 148, "PG-13");
    CD cd1("Thriller", "1982", "C001", "Epic", "Michael Jackson", 9, "Pop");
    Magazine mag1("National Geographic", "2023", "M001", "National Geographic Society", 2023);

    library.addMedia(&book1);
    library.addMedia(&dvd1);
    library.addMedia(&cd1);
    library.addMedia(&mag1);

    library.searchByTitle("Inception");
    library.searchByAuthor("F. Scott Fitzgerald");
    library.searchByPublicationDate("2023");

    return 0;
}
