// Q9 – publication2 with date, book and tape derived
#include <iostream>
#include <string>
using namespace std;

class date {
private:
    int d, m, y;
public:
    date(int dd=1,int mm=1,int yy=2000):d(dd),m(mm),y(yy){}
    void getdate() {
        cout << "Enter day month year: ";
        cin >> d >> m >> y;
    }
    void putdate() const {
        cout << d << '/' << m << '/' << y;
    }
};

class publication {
protected:
    string title;
    float price;
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

class publication2 : public publication {
protected:
    date pubdate;
public:
    void getdata() {
        publication::getdata();
        cout << "Enter publication date:\n";
        pubdate.getdate();
    }
    void putdata() const {
        publication::putdata();
        cout << ", Date: ";
        pubdate.putdate();
    }
};

class book : public publication2 {
private:
    int page_count;
public:
    void getdata() {
        publication2::getdata();
        cout << "Enter page count: ";
        cin >> page_count;
    }
    void putdata() const {
        publication2::putdata();
        cout << ", Pages: " << page_count << endl;
    }
};

class tape : public publication2 {
private:
    float play_time;
public:
    void getdata() {
        publication2::getdata();
        cout << "Enter playing time (minutes): ";
        cin >> play_time;
    }
    void putdata() const {
        publication2::putdata();
        cout << ", Playing time: " << play_time << " minutes" << endl;
    }
};

int main() {
    book b1;
    tape t1;
    cout << "--- Enter book data ---\n"; b1.getdata();
    cout << "--- Enter tape data ---\n"; t1.getdata();

    cout << "\n--- Book ---\n"; b1.putdata();
    cout << "--- Tape ---\n"; t1.putdata();
    return 0;
}

