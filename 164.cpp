#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maximumGap(vector<int> &num) {
    if (num.size() < 2){
      return 0;
    }
    for (int k = 0; k < 31; ++k){
      vector<vector<int> > helper(2, vector<int>());
      for (int i = 0; i < num.size(); ++i){
        if ((num[i] >> k & 1) == 0){
          helper[0].push_back(num[i]);
        }else{
          helper[1].push_back(num[i]);
        }
      }
      copy(helper[0].begin(), helper[0].end(), num.begin());
      copy(helper[1].begin(), helper[1].end(), num.begin() + helper[0].size());
    }
    int max_diff = 0;
    for (int i = 1; i < num.size(); ++i){
      max_diff = max(max_diff, num[i] - num[i - 1]);
    }
    return max_diff;
  }
};

int main(){
  Solution s;
  vector<int> num = {3,1,6,2};
  cout << s.maximumGap(num) << endl;
  return 0;
}
