#include<iostream>
using namespace std;

class MinHeap {

    int* arr;
    int size;
    int total_size;

public:

    MinHeap(int n) {
        arr = new int[n];  
        size = 0;
        total_size = n;
    }

    void insert(int val) {

        if (size == total_size) {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = val;
        int idx = size;
        size++;

        while (idx > 0 && arr[(idx-1)/2] > arr[idx]) {
            swap(arr[idx], arr[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }

    // min heap----
    void heapifyDown(int idx) {
        int smallest = idx;
        int left = 2*idx + 1;
        int right = 2*idx + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != idx) {
            swap(arr[idx], arr[smallest]);
            heapifyDown(smallest);
        }
    }

    // Remove smallest price
    void Delete() {
        if (size == 0) {
            cout << "Heap empty\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    void printHeap() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};


int main() {

    MinHeap H(10);

  //crete heap---
    H.insert(100);
    H.insert(50);
    H.insert(75);
    H.insert(60);

    cout << "Initial Min-Heap:\n";
    H.printHeap();

    //Insert 55----
    cout << "\nInsert new order price 55:\n";
    H.insert(55);
    H.printHeap();

    //remove the lowest price one
    cout << "\nExecute lowest price order:\n";
    H.Delete();
    H.printHeap();

    return 0;
}
