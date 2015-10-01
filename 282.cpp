#include "leetcode.h"

using namespace std;

class Solution {
private:
  stack<int> operand;
  stack<char> op;
  vector<char> ops = {'+', '-', '*'};

  int eval() {
    if (op.empty()) {
      return operand.top();
    }
    int rhs = operand.top();
    operand.pop();
    int lhs = operand.top();
    operand.pop();
    char c = op.top();
    op.pop();
    if (c == '+') {
      return lhs + rhs;
    }else if (c == '-') {
      return lhs - rhs;
    }else {
      return lhs * rhs;
    }
  }

public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    string exp;
    dfs(num, target, res, exp);
    return res;
  }

  void dfs(string num, int target, vector<string>& res, string exp) {
    if (num.empty()) {
      if (!op.empty()) {
        if (eval() == target) {
          res.push_back(exp);
          operand.pop();
        }
      }
      return;
    }
    for (int i = 1; i <= num.size(); ++i) {
      operand.push(atoi(num.substr(0, i).c_str()));
      if (i != num.size()) {
        for (auto c : ops) {
          if (c != '*') {
            if (!op.empty()) {
              operand.push(eval());
            }
          }else if (op.top() == '*') {
            operand.push(eval());
          }
          op.push(c);
          dfs(num.substr(i), target, res, exp + num.substr(0, i) + c);
        }
      }else {
        dfs(num.substr(i), target, res, exp + num.substr(0, i));
      }
    }
  }
};

int main() {
  Solution s;
  for (auto res : s.addOperators("12", 3)) {
    cout << res << endl;
  }
  return 0;
}
