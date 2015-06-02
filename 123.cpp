#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()){
      return 0;
    }
    return maxProfit2(prices);
  }

  int maxProfit1(vector<int>& prices){
    int n = prices.size(), res = 0;
    vector<int> maxFromLeft(n, 0);
    vector<int> maxFromRight(n, 0);
    int curmin = prices[0], maxp = 0;
    for (int i = 0; i < n; ++i) {
      maxp = max(maxp, prices[i] - curmin);
      curmin = min(curmin, prices[i]);
      maxFromLeft[i] = maxp;
    }
    int curmax = prices[n - 1];
    maxp = 0;
    for (int i = n - 1; i >= 0; --i) {
      maxp = max(maxp, curmax - prices[i]);
      curmax = max(curmax, prices[i]);
      maxFromRight[i] = maxp;
    }
    for (int i = 0; i < n - 1; ++i) {
      res = max(res, maxFromLeft[i] + maxFromRight[i + 1]);
    }
    res = max(res, maxFromRight[0]);
    return res;
  }

  int maxProfit2(vector<int>& prices){
    int n = prices.size(), res = 0;
    int cur = INT_MAX, maxp = 0;
    vector<int> left(n, 0);
    for (int i = 0; i < n; ++i) {
      cur = min(cur, prices[i]);
      maxp = max(maxp, prices[i] - cur);
      left[i] = maxp;
    }
    cur = INT_MIN, maxp = 0;
    for (int i = n - 1; i >= 1; --i) {
      cur = max(cur, prices[i]);
      maxp = max(maxp, cur - prices[i]);
      res = max(res, left[i - 1] + maxp);
    }
    res = max(res, left[n - 1]);
    return res;
  }
};

int main(){
  Solution s;
  vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
  cout << s.maxProfit(prices) << endl;
  return 0;
}
