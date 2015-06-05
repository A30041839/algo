#include "leetcode.h"

using namespace std;

class TwoSum {
public:
  void add(int number) {
    mp[number]++;
  }

  bool find(int value) {
    for (auto& pair : mp) {
      int key = pair.first;
      int cnt = pair.second;
      if ((value != 2 * key) and (mp.find(value - key) != mp.end())) {
        return true;
      }
      if ((value == 2 * key) and cnt >= 2) {
        return true;
      }
    }
    return false;
  }

private:
  unordered_map<int, int> mp;
};

int main(){
  TwoSum twosum;
  twosum.add(1);
  twosum.add(3);
  twosum.add(5);
  if (twosum.find(7)) {
    cout << "yes : 7" << endl;
  }
  return 0;
}
