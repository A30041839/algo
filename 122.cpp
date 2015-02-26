#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (!prices.size()){
      return 0;
    }
    return maxProfit1(prices);
  }

  int maxProfit1(vector<int> &prices){
    //greedy algorithm:
    //when prices keep going up, hold the stocks,
    //when prices go down, sell the current stock
    int maxp = 0;
    int curin = prices[0];
    prices.push_back(INT_MIN);
    for (int i = 0; i < prices.size() - 1; ++i){
      if (prices[i] > prices[i + 1]){
        maxp += prices[i] - curin;
        curin = prices[i + 1];
      }
    }
    return maxp;
  }
};

int main(){
  Solution s;
  vector<int> prices = {1, 2, 4};
  cout << s.maxProfit(prices) << endl;
  return 0;
}
