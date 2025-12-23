// Q6 – safehilo: safearay with user-defined low/high bounds via inheritance
#include <iostream>
#include <cstdlib>
using namespace std;

class safearay {
protected:
    enum { MAX = 100 };
    int arr[MAX];
public:
    safearay() {
        for (int i = 0; i < MAX; ++i) arr[i] = 0;
    }
    int& operator[](int i) {
        if (i < 0 || i >= MAX) {
            cout << "Index out of range\n"; exit(1);
        }
        return arr[i];
    }
    const int& operator[](int i) const {
        if (i < 0 || i >= MAX) {
            cout << "Index out of range\n"; exit(1);
        }
        return arr[i];
    }
};

class safehilo : public safearay {
private:
    int low, high;
public:
    safehilo(int l, int h) : low(l), high(h) {
        if (h < l || (h - l + 1) > MAX) {
            cout << "Invalid bounds\n"; exit(1);
        }
    }
    int& operator[](int i) {
        if (i < low || i > high) {
            cout << "Index out of range\n"; exit(1);
        }
        return arr[i - low];
    }
    const int& operator[](int i) const {
        if (i < low || i > high) {
            cout << "Index out of range\n"; exit(1);
        }
        return arr[i - low];
    }
};

int main() {
    safehilo sh(100, 175);
    for (int i = 100; i <= 175; ++i) sh[i] = i - 100;
    cout << "sh[100] = " << sh[100] << ", sh[175] = " << sh[175] << endl;
    return 0;
}

