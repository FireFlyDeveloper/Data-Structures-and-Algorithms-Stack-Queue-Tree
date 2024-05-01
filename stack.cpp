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
