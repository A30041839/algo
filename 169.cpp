#include "leetcode.h"

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &num) {
    return majorityElement1(num);
  }

  //Moore voting algorithm. One pass with O(n) complexity
  //Maintain the current candidate and a counter
  //if the counter is 0, update the current candidate to A[i]
  //and counter to 1
  //if the counter is not 0, increase the counter if A[i] is 
  //the current candidate, decrease the counter otherwise
  int majorityElement1(vector<int> &num) {
    int cur, cnt = 0;
    for (int i = 0; i < num.size(); ++i) {
      if (cnt == 0) {
        cnt = 1;
        cur = num[i];
      }else {
        cnt = num[i] == cur ? cnt + 1 : cnt - 1;
      }
    }
    return cur;
  }
  
  int majorityElement2(vector<int> &num) {
    sort(num.begin(), num.end());
    return num[num.size() / 2];
  }
  
  int majorityElement3(vector<int> &num) {
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
  
  int majorityElement4(vector<int> &num) {
  }
};

int main(){
  vector<int> num = {1, 2, 2, 2};
  Solution s;
  cout << s.majorityElement(num) << endl;
  return 0;
}
