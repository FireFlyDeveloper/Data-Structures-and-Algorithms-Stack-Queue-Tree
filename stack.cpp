#include <iostream>
using namespace std;

string input = "5+6*2+1";
string output;

char myStack[20];
int top = -1;

bool isUnderflow() {
  if (top == -1) {
    return true;
  }
  return false;
}

void push(char val) { myStack[++top] = val; }

char pop() {
  if (isUnderflow()) {
    return '\0';
  }
  return myStack[top--];
}

char peek() { return myStack[top]; }

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
          pop();
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
  infixToPostfix();
  while (!isUnderflow()) {
    output += pop();
  }

  cout << output << endl;

  return 0;
}
