#include "leetcode.h"

using namespace std;

class Solution {
private:
  int calc(int lhs, int rhs, string op) {
    if (op == "+") {
      return lhs + rhs;
    }else if (op == "-") {
      return lhs - rhs;
    }else if (op == "*") {
      return lhs * rhs;
    }else {
      return lhs / rhs;
    }
  }

public:
  int evalRPN(vector<string> &tokens) {
    stack<int> operand;
    int n = tokens.size();
    for (int i = 0; i < n; ++i) {
      string tok = tokens[i];
      if (tok == "+" or tok == "-" or tok == "*" or tok == "/") {
        int rhs = operand.top();
        operand.pop();
        int lhs = operand.top();
        operand.pop();
        operand.push(calc(lhs, rhs, tok));
      }else {
        operand.push(atoi(tok.c_str()));
      }
    }
    return operand.top();
  }
};

int main(){
  Solution s;
  vector<string> exp1 = {"2","1", "+", "3", "*"};
  vector<string> exp2 = {"4", "13", "5", "/", "+"};
  cout << s.evalRPN(exp1) << endl;
  cout << s.evalRPN(exp2) << endl;
  return 0;
}
