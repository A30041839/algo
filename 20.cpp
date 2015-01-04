#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool isValid(string s) {
    bool res = true;
    stack<char> stk;
    for (int i = 0; i < s.length(); ++i){
      switch (s[i]){
      case '(':
      case '{':
      case '[':
        stk.push(s[i]);
        break;
      case ')':
        if (!stk.empty() and stk.top() == '('){
          stk.pop();
        }else{
          res = false;
        }
        break;
      case '}':
        if (!stk.empty() and stk.top() == '{'){
          stk.pop();
        }else{
          res = false;
        }
        break;
      case ']':
        if (!stk.empty() and stk.top() == '['){
          stk.pop();
        }else{
          res = false;
        }
        break;
      default:
        break;
      }
      if (!res){
        break;
      }
    }
    if (!stk.empty()){
      res = false;
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<string> vec = {"(", ")", "()", "(]", "((])", "[{}(())]", "())"};
  for (string str : vec){
    if (s.isValid(str)){
      cout << str << " is valid" << endl;
    }else{
      cout << str << " is not valid" << endl;
    }
  }
  return 0;
}
