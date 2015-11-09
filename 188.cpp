#include "leetcode.h"
using namespace std;

class Solution {
  //two dp: local[i][j] denotes the maximum profit with at most j transactions till day i(day i must be selled)
  //global[i][j] denotes the maximum profit with at most j transactions till day i
public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if (n < 2 or k <= 0) return 0;
    int res = 0, cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
      int diff = prices[i + 1] - prices[i];
      res += diff > 0 ? diff : 0;
      cnt += diff > 0 ? 1 : 0;
    }
    if (k >= cnt) return res;
    vector<int> local(n, 0);
    vector<int> global(n, 0);
    for (int j = 1; j <= k; ++j) {
      int tmp = 0;
      for (int i = 1; i < n; ++i) {
        local[i] = max(tmp, local[i - 1] + prices[i] - prices[i - 1]);
        tmp = global[i];
        global[i] = max(global[i - 1], local[i]);
      }
    }
    return global[n - 1];
  }
};

int main() {
  Solution s;
  vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
  cout << s.maxProfit(2, prices) << endl;
}
