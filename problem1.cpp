#include <iostream>
using namespace std;

struct Chocolate {
  string name;
  int expirationDate;
};

Chocolate myArray[10];
int rear = -1;

void enqueue(Chocolate x) {
    if (rear == 9) {
        cout << "Queue is full" << endl;
    } else {
        if (rear == -1 || myArray[rear].expirationDate > x.expirationDate) {
            rear++;
            myArray[rear] = x;
        } else {
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

void dequeue() {
  if (rear == -1) {
    cout << "Queue is empty" << endl;
  } else {
    cout << "Dequeued element: " << myArray[rear].name << endl;
    rear--;
  }
}

void peek() {
  if (rear == -1) {
    cout << "Queue is empty" << endl;
  } else {
    cout << "Peeked element: " << myArray[rear].name << ", " << myArray[rear].expirationDate << endl;
  }
}

int main() {
  string name;
  int date;
  for (int i = 0; i < 10; i++) {
    cout << "Enter name of chocolate: ";
    cin >> name;
    cout << "Enter expiration date of chocolate (Days): ";
    cin >> date;
    Chocolate x = {name, date};
    enqueue(x);
  }

  peek();

  return 0;
}
