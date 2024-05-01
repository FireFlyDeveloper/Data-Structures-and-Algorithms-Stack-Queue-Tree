#include <iostream>
using namespace std;

string myArray[10]; // Array to store questions
int top = -1;       // Variable to keep track of the top of the queue

// Function to add a question to the queue
void enqueue(string x) { 
  if (top == 9) {
    cout << "Queue is full" << endl; // Display message if queue is full
  } else if (top == -1) {
    myArray[++top] = x; // If queue is empty, add question at the beginning
  } else {
    // Shift elements to make space for new question
    for (int i = top; i >= 0; i--) {
      myArray[i + 1] = myArray[i];
    }
    myArray[0] = x; // Add new question at the beginning
    top++; // Update top index
  }
}

// Function to remove a question from the queue
void dequeue() {
  if (top == -1) {
    cout << "Queue is empty" << endl; // Display message if queue is empty
  } else {
    int count = top;
    cout << "Dequeued element: " << myArray[count] << endl; // Display dequeued question
    myArray[count] = ""; // Remove question by emptying the array element
    top--; // Update top index
  }
}

// Function to peek at the latest question in the queue
void peek() {
  if (top == -1) {
    cout << "Queue is empty" << endl; // Display message if queue is empty
  } else {
    cout << "Peeked element: " << myArray[top] << endl; // Display latest question
  }
}

int main() { 
  // Add questions to the queue
  enqueue("what is your name");
  enqueue("what is your age");
  enqueue("what is your gender");
  enqueue("what is your address");
  enqueue("what is your phone number");
  enqueue("what is your email");
  enqueue("what is your favorite color");
  enqueue("what is your favorite food");
  enqueue("what is your favorite movie");
  enqueue("what is your favorite book");
  enqueue("what is your favorite song");

  peek(); // Peek at the latest question
  
  return 0; 
}
