//Implement Heap sort to sort given set of values using max or min heap
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    // Check if left child exists and is greater than the root
    if (left_child < n && arr[left_child] > arr[largest]) {
        largest = left_child;
    }

    // Check if right child exists and is greater than the root
    if (right_child < n && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    // Swap the root if needed
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();

    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[i], arr[0]);  // Swap the root (max element) with the last element
        heapify(arr, i, 0);     // Heapify the reduced heap
    }
}

int main() {
    // Input from user
    cout << "Enter the number of elements: ";
    int num_elements;
    cin >> num_elements;

    vector<int> arr(num_elements);

    cout << "Enter " << num_elements << " elements separated by spaces: ";
    for (int i = 0; i < num_elements; i++) {
        cin >> arr[i];
    }

    heap_sort(arr);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < num_elements; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
