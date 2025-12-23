// Q8 – Pstring2 with left, mid, right substring functions
#include <iostream>
#include <cstring>
using namespace std;

class String {
protected:
    enum { SZ = 80 };
    char str[SZ];
public:
    String() { str[0] = '\0'; }
    String(const char* s) { strncpy(str, s, SZ-1); str[SZ-1] = '\0'; }
    const char* get() const { return str; }
    void show() const { cout << str; }
};

class Pstring : public String {
public:
    Pstring() : String() {}
    Pstring(const char* s) {
        size_t len = strlen(s);
        if (len >= SZ) { strncpy(str, s, SZ-1); str[SZ-1] = '\0'; }
        else strcpy(str, s);
    }
};

class Pstring2 : public Pstring {
public:
    Pstring2() : Pstring() {}
    Pstring2(const char* s) : Pstring(s) {}

    Pstring2 left(const Pstring2& s1, int n) {
        Pstring2 temp;
        int len = strlen(s1.get());
        if (n > len) n = len;
        strncpy(temp.str, s1.get(), n);
        temp.str[n] = '\0';
        return temp;
    }

    Pstring2 mid(const Pstring2& s1, int start, int n) {
        Pstring2 temp;
        int len = strlen(s1.get());
        if (start < 0) start = 0;
        if (start >= len) { temp.str[0] = '\0'; return temp; }
        if (start + n > len) n = len - start;
        strncpy(temp.str, s1.get() + start, n);
        temp.str[n] = '\0';
        return temp;
    }

    Pstring2 right(const Pstring2& s1, int n) {
        Pstring2 temp;
        int len = strlen(s1.get());
        if (n > len) n = len;
        strncpy(temp.str, s1.get() + (len - n), n);
        temp.str[n] = '\0';
        return temp;
    }
};

int main() {
    Pstring2 s1("Inheritance and Pstring2 substring demo");
    Pstring2 s2, s3, s4;

    s2 = s2.left(s1, 10);
    s3 = s3.mid(s1, 12, 8);
    s4 = s4.right(s1, 4);

    cout << "Original: "; s1.show(); cout << endl;
    cout << "Left 10 : "; s2.show(); cout << endl;
    cout << "Mid(12,8): "; s3.show(); cout << endl;
    cout << "Right 4 : "; s4.show(); cout << endl;
    return 0;
}

