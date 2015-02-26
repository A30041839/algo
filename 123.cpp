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

  int maxProfit1(vector<int>& prices){
    priority_queue<int, vector<int>, less<int> > max_q;
    prices.push_back(-1);
    int curin = prices[0];
    for (int i = 0; i < prices.size() - 1; ++i){
      if (prices[i] > prices[i + 1]){
        int profit = prices[i] - curin;
        if (profit > 0){
          max_q.push(profit);
        }
        curin = prices[i + 1];
      }
    }
    int k = 2;
    int res = 0;
    while (k > 0 and !max_q.empty()){
      res += max_q.top();
      max_q.pop();
      k--;
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
  cout << s.maxProfit(prices) << endl;
  return 0;
}
