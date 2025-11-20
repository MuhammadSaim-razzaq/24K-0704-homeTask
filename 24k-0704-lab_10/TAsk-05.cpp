#include<iostream>
using namespace std;

class MaxHeap {

    int* arr;
    int size;
    int total_size;

public:

    MaxHeap(int n) {
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

        while (idx > 0 && arr[(idx-1)/2] < arr[idx]) {
            swap(arr[idx], arr[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }

    void heapifyDown(int idx) {
        int largest = idx;
        int left = 2*idx + 1;
        int right = 2*idx + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != idx) {
            swap(arr[idx], arr[largest]);
            heapifyDown(largest);
        }
    }

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
        cout << "Queue (heap): ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    MaxHeap H(10);

    H.insert(1500);
    H.insert(1200);
    H.insert(1800);
    H.insert(1600);

    cout << "Initial Queue:\n";
    H.printHeap();

    cout << "\nInserting rating 1700...\n";
    H.insert(1700);
    H.printHeap();

    cout << "\nMatching (removing highest rating)...\n";
    H.Delete();
    H.printHeap();

    return 0;
}
