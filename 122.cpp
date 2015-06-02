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

  int maxProfit1(vector<int> &prices){
    //greedy algorithm:
    //when prices keep going up, hold the stocks,
    //when prices go down, sell the current stock
    prices.push_back(-1);
    int res = 0, n = prices.size();
    int cur = prices[0];
    for (int i = 0; i < n - 1; ++i){
      if (prices[i] > prices[i + 1]){
        res += prices[i] - cur;
        cur = prices[i + 1];
      }
    }
    return res;
  }

  int maxProfit2(vector<int> &prices){
    int res = 0, n = prices.size();
    for (int i = 1; i < n; ++i) {
      res += max(0, prices[i] - prices[i - 1]);
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> prices = {1, 2, 4};
  cout << s.maxProfit(prices) << endl;
  return 0;
}
