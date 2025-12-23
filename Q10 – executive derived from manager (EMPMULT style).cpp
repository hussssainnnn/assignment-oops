// Q10 – executive derived from manager
#include <iostream>
#include <string>
using namespace std;

class employee {
protected:
    string name;
    unsigned long number;
public:
    void getdata() {
        cout << "Enter name: ";
        getline(cin >> ws, name);
        cout << "Enter number: ";
        cin >> number;
    }
    void putdata() const {
        cout << "Name: " << name << ", Number: " << number;
    }
};

class manager : public employee {
protected:
    string title;
    double dues;
public:
    void getdata() {
        employee::getdata();
        cout << "Enter title: ";
        getline(cin >> ws, title);
        cout << "Enter golf club dues: ";
        cin >> dues;
    }
    void putdata() const {
        employee::putdata();
        cout << ", Title: " << title << ", Dues: " << dues;
    }
};

class executive : public manager {
private:
    double bonus;
    long   stock_shares;
public:
    void getdata() {
        manager::getdata();
        cout << "Enter yearly bonus: ";
        cin >> bonus;
        cout << "Enter number of stock-option shares: ";
        cin >> stock_shares;
    }
    void putdata() const {
        manager::putdata();
        cout << ", Bonus: " << bonus
             << ", Shares: " << stock_shares << endl;
    }
};

int main() {
    executive e1;
    cout << "--- Enter executive data ---\n";
    e1.getdata();
    cout << "\n--- Executive ---\n";
    e1.putdata();
    return 0;
}

