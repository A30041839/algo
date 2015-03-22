#include "leetcode.h"

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    nextPermutation1(num);
  }

  void nextPermutation1(vector<int> &num) {
    if (num.empty()) {
      return;
    }
    int pos1 = -1, pos2 = 0;
    for (int i = (int)num.size() - 1; i > 0; --i) {
      if (num[i - 1] < num[i]) {
        pos1 = i - 1;
        break;
      }
    }
    if (pos1 == -1) {
      sort(num.begin(), num.end());
      return;
    }
    for (int i = (int)num.size() - 1; i > 0; --i) {
      if (num[i] > num[pos1]) {
        pos2 = i;
        break;
      }
    }
    swap(num[pos1], num[pos2]);
    reverse(num.begin() + pos1 + 1, num.end());
  }
};

int main(){
  Solution s;
  //vector<int> v = {5, 4, 1, 3, 2};
  //vector<int> v = {5, 4, 3, 2, 1};
  vector<int> v = {1,5,1};
  s.nextPermutation(v);
  for (int i = 0; i < v.size(); ++i){
    cout << v[i] << ",";
  }
  cout << endl;
  return 0;
}
