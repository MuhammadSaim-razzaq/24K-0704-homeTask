#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;

public:
    Exam(int m) {
        marks = new int(m);
    }

    ~Exam() {
        delete marks;
    }

    void setMarks(int m) {
        *marks = m;
    }

    void show() const {
        cout << "Marks: " << *marks << endl;
    }
};

int main() {
    Exam e1(80);
    cout << "e1 original: "; e1.show();

    Exam e2 = e1;  
    cout << "e2 copied from e1: "; e2.show();

    e2.setMarks(95);
    cout << "e2 after change: "; e2.show();
    cout << "e1 after e2 changed: "; e1.show();  

    return 0;
}
