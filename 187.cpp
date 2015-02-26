#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    return findRepeatedDnaSequences1(s);
  }

  vector<string> findRepeatedDnaSequences1(string s) {
    if (s.length() <= 10){
      return {};
    }
    vector<string> res;

    return res;
  }
};

int main(){
  Solution s;
  string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> res = s.findRepeatedDnaSequences(str);
  for (string& a : res){
    cout << a << ",";
  }
  cout << endl;
  return 0;
}
