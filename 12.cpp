#include "leetcode.h"

using namespace std;

/*每两个阶段之间有一次减法表示*/
class Solution {
public:
  string intToRoman(int num) {
    string res;
    string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int value[] = {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
    for (int i = 0; num != 0; ++i){
      while (num >= value[i]){
        num -= value[i];
        res.append(symbol[i]);
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> num = {4};
  for (auto& x : num){
    cout << s.intToRoman(x) << endl;
  }
  return 0;
}
