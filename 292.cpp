#include "leetcode.h"

using namespace std;

class Solution {
public:
  bool canWinNim(int n) {
    if (n <= 3) {
      return true;
    }
    return n % 4 ? true : false;
  }
};

int main() {
  Solution s;
  if (s.canWinNim(134000)) {
    cout << "yes" << endl;
  }
}
