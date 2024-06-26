## Table of Contents
- [Stack](#Stack)
- [Queue](#queue)

## Stack

A stack is a Last-In-First-Out (LIFO) data structure where elements are inserted and removed from the same end, called the top.

### Implementation Details

- **stack.cpp**: Source file containing the implementation of stack methods.

### Implementation Explanation

The provided C++ code implements a stack using an array. The `push` function inserts an element onto the top of the stack, the `pop` function removes and returns the top element from the stack, and the `peek` function returns the top element without removing it.

### Usage

To use the stack implementation, you can call the `push`, `pop`, and `peek` functions as demonstrated below:

```cpp
#include <iostream>
using namespace std;

string input = "5+6*2+1"; // Infix expression to convert to postfix
string output;            // Postfix expression

char myStack[20]; // Stack to store operators
int top = -1;     // Variable to keep track of the top of the stack

// Function to check if stack is empty
bool isUnderflow() {
  if (top == -1) {
    return true;
  }
  return false;
}

// Function to push an operator onto the stack
void push(char val) { myStack[++top] = val; }

// Function to pop an operator from the stack
char pop() {
  if (isUnderflow()) {
    return '\0';
  }
  return myStack[top--];
}

// Function to peek at the top of the stack
char peek() { return myStack[top]; }

// Function to check if a character is an operator
bool isOperator(char val) {
  switch (val) {
  case '(':
    return true;
    break;
  case ')':
    return true;
    break;
  case '+':
    return true;
    break;
  case '-':
    return true;
  case '*':
    return true;
  case '/':
    return true;
    break;
  case '^':
    return true;
    break;
  }

  return false;
}

// Function to determine precedence of operators
int checkPrecedence(char val) {
  switch (val) {
  case '(':
    return 1;
    break;
  case ')':
    return 1;
    break;
  case '+':
    return 4;
    break;
  case '-':
    return 4;
  case '*':
    return 3;
  case '/':
    return 3;
    break;
  case '^':
    return 2;
    break;
  }

  return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix() {
  for (int i = 0; i < input.length(); i++) {
    if (isOperator(input[i])) {
      if (isUnderflow()) {
        push(input[i]);
      } else {

        if (input[i] == ')') {
          while (peek() != '(' && !isUnderflow()) {
            output += pop();
          }
          pop(); // Pop '('
        } else {
          if (checkPrecedence(input[i]) < checkPrecedence(peek())) {
            push(input[i]);
          } else {
            if (input[i] == '(' || peek() == '(') {
              push(input[i]);
            } else {
              while (checkPrecedence(input[i]) >= checkPrecedence(peek()) &&
                     !isUnderflow()) {
                output += pop();
              }
              push(input[i]);
            }
          }
        }
      }
    } else {
      output += input[i];
    }
  }
}

int main() {
  infixToPostfix(); // Convert infix expression to postfix

  // Pop remaining operators from stack and add to output
  while (!isUnderflow()) {
    output += pop();
  }

  cout << output << endl; // Output postfix expression

  return 0;
}
```

## Queue

A queue is a First-In-First-Out (FIFO) data structure where elements are inserted at the rear and removed from the front.

### Implementation Details

- **queue.cpp**: Source file containing the implementation of queue methods.

### Implementation Explanation

The provided C++ code implements a queue using an array. The `enqueue` function inserts an element at the rear of the queue, and the `dequeue` function removes an element from the front of the queue. The `peek` function retrieves the element at the front of the queue without removing it. 

### Usage

To use the queue implementation, you can call the `enqueue`, `dequeue`, and `peek` functions as demonstrated below:

```cpp
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
```
