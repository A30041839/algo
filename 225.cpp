#include "leetcode.h"

using namespace std;

class Stack1 {
private:
  queue<int> q;

public:
  // Push element x onto stack.
  void push(int x) {
    int sz = q.size();
    q.push(x);
    while (sz--) {
      q.push(q.front());
      q.pop();
    }
  }

  // Removes the element on top of the stack.
  void pop() {
    q.pop();
  }

  // Get the top element.
  int top() {
    return q.front();
  }

  // Return whether the stack is empty.
  bool empty() {
    return q.empty();
  }
};

class Stack {
public:
  // Push element x onto stack.
  void push(int x) {
  }

  // Removes the element on top of the stack.
  void pop() {
  }

  // Get the top element.
  int top() {
  }

  // Return whether the stack is empty.
  bool empty() {
  }
};
int main() {
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
}
