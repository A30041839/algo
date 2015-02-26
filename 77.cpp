#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<vector<int> > combine(int n, int k) {
    vector<int> v(n, 0);
    vector<vector<int> > res;
    vector<int> comb;
    if (n == 0 or k == 0){
      return res;
    }
    combine1(v, k, res, comb);
    return res;
  }

  void combine1(vector<int>& v, int k, vector<vector<int> >& res, vector<int>& comb){
    if (k == 0){
      res.push_back(comb);
      return;
    }
    for (int i = 0; i < v.size(); ++i){
      if (v[i] == 0){
        if (comb.empty() or i + 1 > comb.back()){
          comb.push_back(i + 1);
          v[i] = 1;
          combine1(v, k - 1, res, comb);
          comb.pop_back();
          v[i] = 0;
        }
      }
    }
  }
};

int main(){
  Solution s;
  vector<vector<int> > res = s.combine(4, 1);
  for (auto& v : res){
    for (auto& i : v){
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
