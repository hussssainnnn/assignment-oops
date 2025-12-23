// Q1 – publication, book, tape (single inheritance)
#include <iostream>
#include <string>
using namespace std;

class publication {
protected:
    string title;
    float  price;
public:
    void getdata() {
        cout << "Enter title: ";
        getline(cin >> ws, title);
        cout << "Enter price: ";
        cin >> price;
    }
    void putdata() const {
        cout << "Title: " << title << ", Price: " << price;
    }
};

class book : public publication {
private:
    int page_count;
public:
    void getdata() {
        publication::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }
    void putdata() const {
        publication::putdata();
        cout << ", Pages: " << page_count << endl;
    }
};

class tape : public publication {
private:
    float play_time; // minutes
public:
    void getdata() {
        publication::getdata();
        cout << "Enter playing time (minutes): ";
        cin >> play_time;
    }
    void putdata() const {
        publication::putdata();
        cout << ", Playing time: " << play_time << " minutes" << endl;
    }
};

int main() {
    book b1;
    tape t1;

    cout << "--- Enter book data ---\n";
    b1.getdata();
    cout << "--- Enter tape data ---\n";
    t1.getdata();

    cout << "\n--- Book ---\n";
    b1.putdata();
    cout << "--- Tape ---\n";
    t1.putdata();
    return 0;
}

