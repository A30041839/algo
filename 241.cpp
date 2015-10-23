#include "leetcode.h"

using namespace std;

class Solution {
  int eval(int lhs, int rhs, char op) {
    if (op == '+') {
      return lhs + rhs;
    }else if (op == '-') {
      return lhs - rhs;
    }else {
      return lhs * rhs;
    }
  }

public:
  vector<int> diffWaysToCompute(string input) {
    return compute(input);
  }

  vector<int> compute(string input) {
    int num = 0, n = input.size();
    vector<int> res;
    for (int pos = 0; pos < n; ++pos) {
      if (isdigit(input[pos])) {
        num = num * 10 + input[pos] - '0';
      }else {
        auto left = compute(input.substr(0, pos));
        auto right = compute(input.substr(pos + 1));
        for (int& lhs : left) {
          for (int& rhs : right) {
            res.push_back(eval(lhs, rhs, input[pos]));
          }
        }
      }
    }
    return res.empty() ? vector<int>(1, num) : res;
  }
};

int main() {
  Solution s;
  string exp = "2+3";
  string exp1 = "2*3-4*5";
  auto res = s.diffWaysToCompute(exp1);
  print_vec<int>(res);
}
