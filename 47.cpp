#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    sort(num.begin(), num.end());
    return permuteUnique1();
  }

  vector<vector<int> > permuteUnique1(int i, int j){
    vector<vector<int> > res;
    if (i == j){
      return res;
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> num = {1, 1, 2};
  vector<vector<int> > res = s.permuteUnique(num);
  for (auto& v : res){
    for (auto& i : v){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
