#include "leetcode.h"

using namespace std;

class ZigzagIterator {
private:
  int pos = 0;
  vector<vector<int>::iterator> iters;
  vector<vector<int>::iterator> ends;

  void move() {
    int cnt = 0;
    do {
      pos = (pos + 1) % 2;
      cnt++;
    } while (cnt < 2 and iters[pos] == ends[pos]);
  }

public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    iters.push_back(v1.begin());
    iters.push_back(v2.begin());
    ends.push_back(v1.end());
    ends.push_back(v2.end());
    if (v1.empty()) {
      move();
    }
  }

  int next() {
    int ret = *iters[pos]++;
    move();
    return ret;
  }

  bool hasNext() {
    return iters[pos] != ends[pos];
  }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
  vector<int> v1 = {};
  vector<int> v2 = {6,7};
  ZigzagIterator zit(v1, v2);
  while (zit.hasNext()) {
    cout << zit.next() << ",";
  }
  cout << endl;
}
