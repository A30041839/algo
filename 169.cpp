#include "leetcode.h"

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &num) {
    return majorityElement5(num, 0, num.size() - 1);
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

  //O(n) Bit manipulation:
  //We would need 32 iterations, each calculating the number of 1's
  //for the ith bit of all n numbers. Since a majority must exist, therefore,
  //either count of 1's > count of 0's or vice versa (but can never be equal).
  //The majority number’s ith bit must be the one bit that has the greater count.
  int majorityElement4(vector<int> &num) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      int mask = 1 << i;
      int cnt_0 = 0, cnt_1 = 0;
      for (int j = 0; j < num.size(); ++j) {
        if ((num[j] & mask) != 0) {
          cnt_1++;
        }else {
          cnt_0++;
        }
      }
      if (cnt_1 > cnt_0) {
        res |= mask;
      }
    }
    return res;
  }

  //Divide and conquer: Divide the array into two halves, then find the majority
  //element A in the first half and the majority element B in the second half.
  //The global majority element must either be A or B. If A == B,then it automatically
  //becomes the global majority element. If not, then both A and B are the candidates
  //for the majority element, and it is suffice to check the count of occurrences for
  //at most two candidates. The runtime complexity, T(n) = T(n/2) + 2n = O(n logn).
  int majorityElement5(vector<int> &num, int low, int high) {
    if (low == high) {
      return num[low];
    }
    int mid = (low + high) / 2;
    int left_majority = majorityElement5(num, low, mid);
    int right_majority = majorityElement5(num, mid + 1, high);
    if (left_majority == right_majority) {
      return left_majority;
    }
    int cnt_left = 0, cnt_right = 0;
    for (int i = low; i <= high; ++i) {
      if (num[i] == left_majority) {
        cnt_left++;
      }else if (num[i] == right_majority) {
        cnt_right++;
      }
    }
    return cnt_left > cnt_right ? left_majority : right_majority;
  }
};

int main(){
  vector<int> num = {1, 2, 2, 2};
  Solution s;
  cout << s.majorityElement(num) << endl;
  return 0;
}
