#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    if (n <= 0) {
      return false;
    }
    for (int i = 0; i <= 9; ++i) {
      square.push_back(i * i);
    }
    unordered_set<int> s;
    while (n != 1) {
      n = getSquare(n);
      if (s.find(n) != s.end()) {
        return false;
      }
      s.insert(n);
    }
    return true;
  }

private:
  vector<int> square;

  int getSquare(int n) {
    if (n <= 0) {
      return 0;
    }
    int sum = 0;
    while (n) {
      sum += square[n % 10];
      n /= 10;
    }
    return sum;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 22};
  for (int x : nums) {
    if (s.isHappy(x)) {
      cout << x << " is a happy number" << endl;
    }
  }
  return 0;
}
