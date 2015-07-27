#include "leetcode.h"

using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    if (ratings.empty()) {
      return 0;
    }
    int res = 0, n = ratings.size();
    vector<int> v(n, 1);
    for (int i = 1; i < n; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        v[i] = v[i - 1] + 1;
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        if (v[i] <= v[i + 1]) {
          v[i] = v[i + 1] + 1;
        }
      }
    }
    for (int& a : v) {
      res += a;
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> ratings = {4,2,3,4,1};
  cout << s.candy(ratings) << endl;
  return 0;
}
