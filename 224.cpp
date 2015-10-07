#include "leetcode.h"

using namespace std;

class Solution {
  static unordered_map<char, int> mp;
  static vector<vector<char>> precedence;

  char getPrecedence(char op1, char op2) {
    return precedence[mp[op1]][mp[op2]];
  }

private:
  stack<char> ops;
  stack<int> operands;
  void eval() {
    int b = operands.top();
    operands.pop();
    int a = operands.top();
    operands.pop();
    char op = ops.top();
    ops.pop();
    if (op == '+') {
      operands.push(a + b);
    }else {
      operands.push(a - b);
    }
  }

public:
  int calculate(string s) {
    if (s.empty()) {
      return 0;
    }
    s.push_back('#');
    ops.push('#');
    int n = s.size();
    int tmp = 0;
    bool f = false;
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (isdigit(c)) {
        tmp = tmp * 10 + c - '0';
        f = true;
      }else if (c != ' ') {
        if (f) {
          operands.push(tmp);
          tmp = 0;
          f = false;
        }
        char pred = getPrecedence(c, ops.top());
        switch (pred) {
        case '>' :
          ops.push(c);
          break;
        case '<':
          eval();
          i--;
          break;
        case '=':
          ops.pop();
          break;
        default:
          break;
        }
      }
    }
    return operands.top();
  }
};

unordered_map<char, int> Solution::mp = {{'+', 0}, {'-', 1}, {'(', 2}, {')', 3}, {'#', 4}};
vector<vector<char>> Solution::precedence = {{'<', '<', '>', '<', '>'}, {'<', '<', '>', '<', '>'}, {'>', '>', '>', '>', '>'},
{'<', '<', '=', '<', '>'}, {'<', '<', '<', '<', '='}};
