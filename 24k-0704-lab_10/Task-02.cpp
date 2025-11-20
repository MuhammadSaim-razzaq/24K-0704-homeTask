#include<iostream>
using namespace std;

class MaxHeap {

    int* arr;
    int size;        // current no of elements
    int total_size;  // max capacity----

public:

    MaxHeap(int n) {
        arr = new int[n];   
        size = 0;
        total_size = n;
    }

    void insert(int val) {

        if (size == total_size) {
            cout << "Heap overflow\n";
            return;
        }

        arr[size] = val;     
        int idx = size;
        size++;

        
        while (idx > 0 && arr[(idx - 1) / 2] < arr[idx]) {
            swap(arr[idx], arr[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    // Heapify down after deletion
    void heapifyDown(int idx) {

        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != idx) {
            swap(arr[idx], arr[largest]);
            heapifyDown(largest);
        }
    }

    // Remove parent--------------
    void Delete() {

        if (size == 0) {
            cout << "Heap empty\n";
            return;
        }

        arr[0] = arr[size - 1]; // replace parent with last one-----------
        size--;

        if (size > 0)
            heapifyDown(0);
    }

    // Display heap array
    void printHeap() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    MaxHeap H1(10);

    // Existing patients-----
    H1.insert(8);
    H1.insert(5);
    H1.insert(7);
    H1.insert(3);

    cout << "Initial Heap:\n";
    H1.printHeap();

    cout << "\nInserting severity 10...\n";
    H1.insert(10);
    H1.printHeap();

    cout << "\nRemoving highest severity...\n";
    H1.Delete();   
    H1.printHeap();

    return 0;
}
