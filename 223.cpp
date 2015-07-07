#include "leetcode.h"

using namespace std;

class Solution {
private:
  int lineCoverage(int x1, int x2, int x3, int x4) {
    int diff1 = x2 - x3 > 0 ? x2 - x3 : 0;
    int diff2 = x2 - x4 > 0 ? x2 - x4 : 0;
    int diff3 = x1 - x3 > 0 ? x1 - x3 : 0;
    return diff1 - diff2 - diff3 > 0 ? diff1 - diff2 - diff3 : 0;
  }

public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    return computeArea1(A, B, C, D, E, F, G, H);
  }

  int computeArea1(int A, int B, int C, int D, int E, int F, int G, int H) {
    //compute x-axis converage
    int coverx = lineCoverage(A, C, E, G);
    //compute y-axis converage
    int covery = lineCoverage(B, D, F, H);
    return (C - A) * (D - B) + (G - E) * (H - F) - coverx * covery;
  }
};

int main() {
  Solution s;
  cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
  return 0;
}
