#include "leetcode.h"

using namespace std;

class MinStack {
public:
  void push(int x) {
    stk.push(x);
    if (min_stk.empty() or x <= min_stk.top()) {
      min_stk.push(x);
    }
  }

  void pop() {
    if (!stk.empty()){
      int n = stk.top();
      stk.pop();
      if (n == min_stk.top()){
        min_stk.pop();
      }
    }
  }

  int top() {
    assert(!stk.empty());
    return stk.top();
  }

  int getMin() {
    assert(!min_stk.empty());
    return min_stk.top();
  }

private:
  stack<int> stk;
  stack<int> min_stk;
};

int main(){
  MinStack ms;
  ms.push(1);
  ms.push(-1);
  ms.push(2);
  ms.push(2);
  ms.pop();
  cout << ms.getMin() << endl;
  return 0;
}
