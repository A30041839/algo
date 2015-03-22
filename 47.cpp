#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    if (num.empty()) {
      return {{}};
    }
    sort(num.begin(), num.end());
    vector<vector<int> > res;
    res.push_back(num);
    while (nextPermutation(num)) {
      res.push_back(num);
    }
    return res;
  }

  bool nextPermutation(vector<int> &num) {
    int pos1 = -1, pos2 = 0;
    for (int i = (int)num.size() - 1; i > 0; --i) {
      if (num[i - 1] < num[i]) {
        pos1 = i - 1;
        break;
      }
    }
    if (pos1 == -1) {
      sort(num.begin(), num.end());
      return false;
    }
    for (int i = (int)num.size() - 1; i > 0; --i) {
      if (num[i] > num[pos1]) {
        pos2 = i;
        break;
      }
    }
    swap(num[pos1], num[pos2]);
    reverse(num.begin() + pos1 + 1, num.end());
    return true;
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
