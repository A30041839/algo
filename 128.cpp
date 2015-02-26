#include "leetcode.h"

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    return longestConsecutive1(num);
  }

  int longestConsecutive1(vector<int> &num) {
    unordered_map<int, int> mp;
    for (int x : num){
      mp[x] = 0;
    }
    int max_len = 0;
    for (int x : num){
      if (mp[x] == 0){
        int gt_cnt = 0, lt_cnt = 0;
        int x1 = x;
        while (mp.count(x1 + 1) > 0){
          mp[x1 + 1] = 1;
          gt_cnt++;
          x1++;
        }
        x1 = x;
        while (mp.count(x1 - 1) > 0){
          mp[x1 - 1] = 1;
          lt_cnt++;
          x1--;
        }
        max_len = max(max_len, gt_cnt + lt_cnt + 1);
        mp[x] = 1;
      }
    }
    return max_len;
  }
};

int main(){
  Solution s;
  vector<int> num = {100, 4, 200, 1, 3, 2, 101, 99, 104, 102, 103, 101};
  cout << s.longestConsecutive(num) << endl;
  return 0;
}
