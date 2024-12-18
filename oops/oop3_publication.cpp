#include <iostream>
#include <string>
using namespace std;

// Base class
class Publication {
protected:
    string title;
    float price;

public:
    // Default Constructor
    Publication() : title(""), price(0.0) {}

    // Method to input publication details
    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;

        // Check for invalid price
        if (price < 0) {
            throw runtime_error("Invalid price!");
        }
    }

    // Method to display publication details
    void display() const {
        cout << "Title: " << title << "\nPrice: $" << price << endl;
    }
};

// Derived class: Book
class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        try {
            Publication::getData();
            cout << "Enter page count: ";
            cin >> pageCount;

            // Check for invalid page count
            if (pageCount < 0) {
                throw runtime_error("Invalid page count!");
            }
        } catch (...) {
            // Reset data members to zero values
            title = "";
            price = 0.0;
            pageCount = 0;
            cout << "Exception caught! Data reset to zero values.\n";
        }
    }

    void display() const {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

// Derived class: Tape
class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void getData() {
        try {
            Publication::getData();
            cout << "Enter playing time (minutes): ";
            cin >> playingTime;

            // Check for invalid playing time
            if (playingTime < 0) {
                throw runtime_error("Invalid playing time!");
            }
        } catch (...) {
            // Reset data members to zero values
            title = "";
            price = 0.0;
            playingTime = 0.0;
            cout << "Exception caught! Data reset to zero values.\n";
        }
    }

    void display() const {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    cout << "Enter details for Book:\n";
    book.getData();

    cout << "\nEnter details for Tape:\n";
    tape.getData();

    cout << "\nBook Details:\n";
    book.display();

    cout << "\nTape Details:\n";
    tape.display();

    return 0;
}
