#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() == 0){
      return 0;
    }
    return maxProfit1(prices);
  }

  int maxProfit1(vector<int>& prices){
    int curmin = prices[0];
    int res = 0, n = prices.size();
    for (int i = 1; i < n; ++i){
      res = max(res, prices[i] - curmin);
      curmin = min(curmin, prices[i]);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> prices = {1, 11, 10, 20};
  cout << s.maxProfit(prices) << endl;
  return 0;
}
