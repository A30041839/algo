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
    int maxp = 0;
    for (int i = 1; i < prices.size(); ++i){
      maxp = max(maxp, prices[i] - curmin);
      curmin = min(curmin, prices[i]);
    }
    return maxp;
  }
};

int main(){
  Solution s;
  vector<int> prices = {1, 11, 10, 20};
  cout << s.maxProfit(prices) << endl;
  return 0;
}
