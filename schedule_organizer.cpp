#include <iostream>
using namespace std;

// Define a structure for storing schedule information
struct Schedule {
  string subject;           // Name of the subject
  int time;   // Time of the subject
};

Schedule myArray[10];  // Array to store schedule
int rear = -1;          // Variable to keep track of the rear end of the queue

// Function to add a schedule to the queue
void enqueue(Schedule x) {
    if (rear == 9) {
        cout << "Queue is full" << endl; // Display message if queue is full
    } else {
        if (rear == -1 || myArray[rear].time > x.time) {
            // If queue is empty or new schedule has longer time,
            // add it directly at the end
            rear++;
            myArray[rear] = x;
        } else {
            // If new schedule has shorter time, find its position
            // based on time and insert it accordingly
            int i = rear;
            while (i >= 0 && myArray[i].time < x.time) {
                myArray[i + 1] = myArray[i];
                i--;
            }
            myArray[i + 1] = x;
            rear++;
        }
    }
}

// Function to remove a schedule from the queue
void dequeue() {
  if (rear == -1) {
    cout << "Queue is empty" << endl; // Display message if queue is empty
  } else {
    cout << "Dequeued element: " << myArray[rear].subject << endl; // Display dequeued schedule
    rear--; // Update rear index
  }
}

// Function to peek at the schedule with the longest time
void peek() {
  if (rear == -1) {
    cout << "Queue is empty" << endl; // Display message if queue is empty
  } else {
    cout << "Peeked element: " << myArray[rear].subject << ", " << myArray[rear].time << endl; // Display peeked schedule
  }
}

int main() {
  Schedule x;

  x = {"Math", 13};
  enqueue(x);

  x = {"Filipino", 8};
  enqueue(x);

  x = {"P.E", 10};
  enqueue(x);

  x = {"RPH", 7};
  enqueue(x);

  x = {"Computer Programming", 12};
  enqueue(x);

  peek(); // Peek at the Schedule with the longest time

  return 0;
}
