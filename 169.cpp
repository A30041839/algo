#include "leetcode.h"

using namespace std;

class Solution1 {
public:
  int majorityElement(vector<int> &num) {
    sort(num.begin(), num.end());
    return num[num.size() / 2];
  }
};

class Solution2 {
public:
  int majorityElement(vector<int> &num) {
    unordered_map<int, int> map;
    for (int x : num){
      map[x]++;
    }
    for (auto kvp : map){
      if (kvp.second > num.size() / 2){
        return kvp.first;
      }
    }
  }
};

class Solution {
public:
  int majorityElement(vector<int> &num) {
    int cnt = 1;
    int n = num[0];
    for (int i = 1; i < num.size(); ++i){
      if (cnt == 0){
        cnt = 1;
        n = num[i];
      }else{
        cnt = num[i] == n ? cnt + 1: cnt - 1;
      }
    }
    return n;
  }
};

int main(){
  vector<int> num = {1, 2, 2, 2};
  Solution s;
  cout << s.majorityElement(num) << endl;
  return 0;
}
