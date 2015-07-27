#include "leetcode.h"

using namespace std;

class Queue {
private:
  stack<int> stk1;
  stack<int> stk2;

  void move() {
    if (stk2.empty()) {
      while (!stk1.empty()) {
        stk2.push(stk1.top());
        stk1.pop();
      }
    }
  }

public:
  // Push element x to the back of queue.
  void push(int x) {
    stk1.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    move();
    stk2.pop();
  }

  // Get the front element.
  int peek(void) {
    move();
    return stk2.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return stk1.empty() and stk2.empty();
  }
};

int main() {
  Queue q;
  for (int i = 0; i < 10; ++i) {
    q.push(i);
  }
  while (!q.empty()) {
    cout << q.peek() << endl;
    q.pop();
  }
  return 0;
}
