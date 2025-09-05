#include <iostream>
using namespace std;

class Box {
private:
    int* volume;

public:
    Box() {
        volume = new int(0);
    }

    Box(int v) {
        volume = new int(v);
    }

    Box(const Box& other) {
        volume = new int(*other.volume);
    }

    ~Box() {
        delete volume;
    }

    void setVolume(int v) {
        *volume = v;
    }

    void show() const {
        cout << "Volume: " << *volume << endl;
    }
};

int main() {
    Box b1;
    cout << "b1 (default): "; b1.show();

    Box b2(50);
    cout << "b2 (param): "; b2.show();

    Box b3 = b2;
    cout << "b3 (copy of b2): "; b3.show();

    b3.setVolume(100);
    cout << "b3 after change: "; b3.show();
    cout << "b2 remains: "; b2.show();

    return 0;
}
