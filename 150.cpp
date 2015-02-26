#include "leetcode.h"

using namespace std;

int _plus(int& a, int& b){
  return a + b;
}

int _minus(int& a, int& b){
  return a - b;
}

int _multiply(int& a, int& b){
  return a * b;
}

int _divide(int& a, int& b){
  return a / b;
}

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> operands;
    typedef int (*fp) (int&, int&);
    unordered_map<string, fp> fmap;
    fmap.insert({"+", _plus});
    fmap.insert({"-", _minus});
    fmap.insert({"*", _multiply});
    fmap.insert({"/", _divide});

    for (int i = 0; i < tokens.size(); ++i){
      string token = tokens[i];
      if (fmap.count(token) > 0){
        int a = operands.top();
        operands.pop();
        int b = operands.top();
        operands.pop();
        operands.push(fmap[token](b, a));
      }else{
        operands.push(atoi(token.c_str()));
      }
    }
    return operands.top();
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
