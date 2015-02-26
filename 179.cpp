#include "leetcode.h"

using namespace std;

class Solution {
public:
  string largestNumber(vector<int> &num) {
    vector<string> num1;
    for (int i : num){
      char str[100];
      sprintf(str, "%d", i);
      num1.push_back(string(str));
    }
    sort(num1.begin(), num1.end(), cmp);
    string res;
    int i = 0;
    while (i < num1.size() - 1){
      if (num1[i] != "0"){
        break;
      }
      i++;
    }
    for (; i < num1.size(); ++i){
      res.append(num1[i]);
    }
    return res;
  }

  static bool cmp(string a, string b){
    int i = 0;
    while (i < a.length() and i < b.length()){
      if (a[i] != b[i]){
        return a[i] > b[i];
      }
      i++;
    }
    string &s_long = i ==  a.length() ? b : a;
    string &s_short = i == a.length() ? a : b;
    int len_short = s_short.length();
    while (i < s_long.length()){
      if (s_long[i] > s_long[i - len_short]){
        return s_long == a;
      }else if (s_long[i] < s_long[i - len_short]){
        return s_long == b;
      }else if (i == s_long.length() - 1){
        if (s_long[i] > s_long[i - 1]){
          return s_long == a;
        }else if (s_long[i] < s_long[i - 1]){
          return s_long == b;
        }
      }
      i++;
    }
    return false;
  }
};

int main(){
  Solution s;
  vector<int> num = {0,0};
  cout << s.largestNumber(num) << endl;
  return 0;
}
