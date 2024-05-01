#include <iostream>
using namespace std;

string myArray[10];
int top = -1;

void enqueue(string x) { 
  if (top == 9) {
    cout << "Queue is full" << endl;
  } else if (top == -1) {
    myArray[++top] = x;
  } else {
    for (int i = top; i >= 0; i--) {
      myArray[i + 1] = myArray[i];
    }
    myArray[0] = x;
    top++;
  }
}

void dequeue() {
  if (top == -1) {
    cout << "Queue is empty" << endl;
  } else {
    int count = top;
    cout << "Dequeued element: " << myArray[count] << endl;
    myArray[count] = "";
    top--;
  }
}

void peek() {
  if (top == -1) {
    cout << "Queue is empty" << endl;
  } else {
    cout << "Peeked element: " << myArray[top] << endl;
  }
}

int main() { 
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
  peek();
  
  return 0; 
}
