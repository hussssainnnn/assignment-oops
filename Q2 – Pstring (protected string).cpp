// Q2 – Pstring: protected string against overflow (SZ = 80)
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
    void show() const { cout << str; }
};

class Pstring : public String {
public:
    Pstring() : String() {}
    Pstring(const char* s) {
        size_t len = strlen(s);
        if (len >= SZ) {
            strncpy(str, s, SZ-1);
            str[SZ-1] = '\0';
        } else {
            strcpy(str, s);
        }
    }
};

int main() {
    const char* shortStr = "Short string";
    const char* longStr =
        "This string will surely exceed the width of the screen, which is what SZ represents.";

    Pstring s1(shortStr);
    Pstring s2(longStr);

    cout << "Short: "; s1.show(); cout << endl;
    cout << "Long (truncated to 79 chars):\n";
    s2.show(); cout << endl;
    return 0;
}

