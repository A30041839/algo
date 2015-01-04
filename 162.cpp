#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int findPeakElement(const vector<int> &num) {
    int low = -1;
    int high = num.size();
    if (num.size() == 1){
      return 0;
    }
    while (low < high){
      int mid = (low + high) / 2;
      if (mid == 0 and num[mid + 1] < num[mid]){
        return mid;
      }
      if (mid == num.size() - 1 and num[mid - 1] < num[mid]){
        return mid;
      }
      if (num[mid - 1] < num[mid] and num[mid] > num[mid + 1]){
        return mid;
      }
      int t1 = low == -1 ? num[mid] : max(num[low], num[mid]);
      int t2 = high == num.size() ? num[mid] : max(num[mid], num[high]);
      if ((low < num.size() - 1 and num[low + 1] > t1) or (mid > 0 and num[mid - 1] > t1)){
        high = mid;
      }else if ((mid < num.size() - 1 and num[mid + 1] > t2) or (high > 0 and num[high - 1] > t2)){
        low = mid;
      }
    }
  }
};

int main(){
  vector<int> v = {3, 2, 1};
  Solution s;
  cout << s.findPeakElement(v) << endl;
  return 0;
}
