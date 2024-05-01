#include <iostream>
using namespace std;

// Define a structure for storing chocolate information
struct Chocolate {
  string name;           // Name of the chocolate
  int expirationDate;   // Expiration date of the chocolate in days
};

Chocolate myArray[10];  // Array to store chocolates
int rear = -1;          // Variable to keep track of the rear end of the queue

// Function to add a chocolate to the queue
void enqueue(Chocolate x) {
    if (rear == 9) {
        cout << "Queue is full" << endl; // Display message if queue is full
    } else {
        if (rear == -1 || myArray[rear].expirationDate > x.expirationDate) {
            // If queue is empty or new chocolate has longer expiration,
            // add it directly at the end
            rear++;
            myArray[rear] = x;
        } else {
            // If new chocolate has shorter expiration, find its position
            // based on expiration date and insert it accordingly
            int i = rear;
            while (i >= 0 && myArray[i].expirationDate < x.expirationDate) {
                myArray[i + 1] = myArray[i];
                i--;
            }
            myArray[i + 1] = x;
            rear++;
        }
    }
}

// Function to remove a chocolate from the queue
void dequeue() {
  if (rear == -1) {
    cout << "Queue is empty" << endl; // Display message if queue is empty
  } else {
    cout << "Dequeued element: " << myArray[rear].name << endl; // Display dequeued chocolate
    rear--; // Update rear index
  }
}

// Function to peek at the chocolate with the longest expiration date
void peek() {
  if (rear == -1) {
    cout << "Queue is empty" << endl; // Display message if queue is empty
  } else {
    cout << "Peeked element: " << myArray[rear].name << ", " << myArray[rear].expirationDate << endl; // Display peeked chocolate
  }
}

int main() {
  string name;
  int date;
  // Loop to input chocolate details and enqueue them
  for (int i = 0; i < 10; i++) {
    cout << "Enter name of chocolate: ";
    cin >> name;
    cout << "Enter expiration date of chocolate (Days): ";
    cin >> date;
    Chocolate x = {name, date};
    enqueue(x);
  }

  peek(); // Peek at the chocolate with the longest expiration date

  return 0;
}
