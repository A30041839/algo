#include "leetcode.h"

using namespace std;

class Solution {
private:
  static const vector<string> map;

  vector<string> letterCombinations_recursive1(string digits){
    if (digits.empty()){
      return {{}};
    }
    vector<string> res;
    auto v = letterCombinations_recursive1(digits.substr(1));
    for (auto& c : map[digits[0] - '0']){
      for (auto& s : v){
        res.push_back(string(1, c) + s);
      }
    }
    return res;
  }

  void letterCombinations_recursive2(string digits, vector<string>& res, string str, 
    int i){
    if (i == digits.length()){
      res.push_back(str);
      return;
    }
    string mapped_letters = map[digits[i] - '0'];
    for (char c : mapped_letters){
      str.push_back(c);
      letterCombinations_recursive2(digits, res, str, i + 1);
      str.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    return letterCombinations_recursive1(digits);
  }
};

const vector<string> Solution::map = {"", "", "abc", "def", "ghi", "jkl", "mno",
  "pqrs", "tuv", "wxyz"};

int main(){
  Solution s;
  vector<string> res = s.letterCombinations("23");
  for (string str : res){
    cout << str << ",";
  }
  cout << endl;
  return 0;
}
