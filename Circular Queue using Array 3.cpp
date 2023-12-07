//Implement Circular Queue using Array. Perform following operations on it.
// a) Insertion (Enqueue) b) Deletion (Dequeue) c) Display 
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, maxSize;
    int* arr;

public:
    CircularQueue(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (front == 0 && rear == maxSize - 1) || (front == rear + 1);
    }

    // Function to insert an element into the queue (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = value;
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to remove an element from the queue (Dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << arr[front] << " dequeued from the queue." << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue: ";
        int i = front;

        do {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);

        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the circular queue: ";
    cin >> size;

    CircularQueue queue(size);

    // Menu-driven loop to perform operations
    int choice;
    do {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;

            case 2:
                queue.dequeue();
                break;

            case 3:
                queue.display();
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
