#include "leetcode.h"

using namespace std;

struct station{
  int index;
  float gas;
  float cost;
  station(int _index, int _gas, int _cost): index(_index),
         gas(_gas), cost(_cost) {}
  bool operator<(const station& other) const{
    return gas / cost > other.gas / other.cost;
  }
};

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    vector<station> stations;
    int n = gas.size();
    for (int i = 0; i < n; ++i){
      stations.push_back(station(i, gas[i], cost[i]));
    }
    sort(stations.begin(), stations.end());
    for (int i = 0; i < n; ++i){
      int vol = 0;
      int j = stations[i].index;
      for (; j < stations[i].index + n; ++j){
        vol += gas[j % n] - cost[j % n];
        if (vol < 0){
          break;
        }
      }
      if (j == stations[i].index + n){
        return stations[i].index;
      }
    }
    return -1;
  }
};

int main(){
  Solution s;
  vector<int> gas = {6,1,4,3,5};
  vector<int> cost = {3,8,2,4,2};
  cout << s.canCompleteCircuit(gas, cost) << endl;
  return 0;
}
