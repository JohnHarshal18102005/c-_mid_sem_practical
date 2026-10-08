#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }


    void enqueue(int person) {
        if (rear == 4) {
            cout << "Queue is full. No more people can wait." << endl;
            return;
        }

        rear++;
        arr[rear] = person;
        cout << "Person " << person << " joined the queue." << endl;
    }


    void dequeue() {
        if (front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Person " << arr[front] << " entered the ride." << endl;
        front++;
    }


    void display() {
        if (front > rear) {
            cout << "No people are waiting." << endl;
            return;
        }

        cout << "Waiting queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);


    q.enqueue(6);

    q.display();


    q.dequeue();

    q.display();

    return 0;
}
