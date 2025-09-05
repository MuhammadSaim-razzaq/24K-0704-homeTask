#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authors;
    int authorCount;

public:
    ResearchPaper(int count = 0, const string arr[] = nullptr) {
        authorCount = count;
        if (authorCount > 0 && arr != nullptr) {
            authors = new string[authorCount];
            for (int i = 0; i < authorCount; i++) {
                authors[i] = arr[i];
            }
        } else {
            authors = nullptr;
        }
    }

    ResearchPaper(const ResearchPaper& other) {
        authorCount = other.authorCount;
        if (authorCount > 0) {
            authors = new string[authorCount];
            for (int i = 0; i < authorCount; i++) {
                authors[i] = other.authors[i];
            }
        } else {
            authors = nullptr;
        }
    }

    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this != &other) {
            delete[] authors;
            authorCount = other.authorCount;
            if (authorCount > 0) {
                authors = new string[authorCount];
                for (int i = 0; i < authorCount; i++) {
                    authors[i] = other.authors[i];
                }
            } else {
                authors = nullptr;
            }
        }
        return *this;
    }

    ~ResearchPaper() {
        delete[] authors;
    }

    void show() const {
        for (int i = 0; i < authorCount; i++) {
            cout << authors[i] << (i < authorCount - 1 ? ", " : "");
        }
        cout << endl;
    }
};

int main() {
    string a1[] = {"kamran", "shakir"};
    ResearchPaper p1(2, a1);
    cout << "p1: "; p1.show();

    ResearchPaper p2 = p1;
    cout << "p2 (copy of p1): "; p2.show();

    string a2[] = {"ali"};
    ResearchPaper p3(1, a2);
    cout << "p3 before assignment: "; p3.show();

    p3 = p1;
    cout << "p3 after assignment: "; p3.show();

    return 0;
}
