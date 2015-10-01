#include "leetcode.h"

using namespace std;

class Solution {
private:
  struct station {
    int id;
    int gas;
    int cost;
    station(int _id, int _gas, int _cost) : id(_id), gas(_gas), cost(_cost) {}
    bool operator<(const station& other) const{
      return gas - cost > other.gas - other.cost;
    }
  };

public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    return canCompleteCircuit2(gas, cost);
  }

  int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
    vector<station> v;
    int n = gas.size();
    for (int i = 0; i < n; ++i) {
      v.push_back(station(i, gas[i], cost[i]));
    }
    sort(v.begin(), v.end());
    //choose starting station with (gas - cost) highest first
    for (int i = 0; i < n; ++i) {
      int r = 0, j;
      for (j = v[i].id; j < v[i].id + n; ++j) {
        r += gas[j % n] - cost[j % n];
        if (r < 0) {
          break;
        }
      }
      if (j == v[i].id + n) {
        return v[i].id;
      }
    }
    return -1;
  }

  int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int leftgas = 0, sum = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
      leftgas += gas[i] - cost[i];
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        start = i + 1;
      }
    }
    return leftgas < 0 ? -1 : start;
  }
};

int main(){
  Solution s;
  vector<int> gas = {6,1,4,3,5};
  vector<int> cost = {3,8,2,4,2};
  cout << s.canCompleteCircuit(gas, cost) << endl;
  return 0;
}
