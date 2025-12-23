// Q7 – counter with prefix and postfix ++ and -- via inheritance
#include <iostream>
using namespace std;

class Counter {
protected:
    unsigned int count;
public:
    Counter() : count(0) {}
    Counter(unsigned int c) : count(c) {}
    unsigned int get_count() const { return count; }

    Counter operator++() { return Counter(++count); }
    Counter operator--() { return Counter(--count); }
};

class CountPost : public Counter {
public:
    CountPost() : Counter() {}
    CountPost(unsigned int c) : Counter(c) {}

    CountPost operator++(int) {
        CountPost temp(*this);
        ++count;
        return temp;
    }
    CountPost operator--(int) {
        CountPost temp(*this);
        --count;
        return temp;
    }
};

int main() {
    CountPost c1(5);
    cout << "Initial: " << c1.get_count() << endl;

    cout << "Prefix ++: " << (++c1).get_count() << endl;
    cout << "Postfix ++ returned: " << (c1++).get_count()
         << ", after: " << c1.get_count() << endl;

    cout << "Prefix --: " << (--c1).get_count() << endl;
    cout << "Postfix -- returned: " << (c1--).get_count()
         << ", after: " << c1.get_count() << endl;
    return 0;
}

