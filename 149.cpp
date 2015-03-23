#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    unordered_map<float, unordered_map<float, unordered_set<int> > > mp1;
    unordered_map<int, unordered_set<int> > mp2;
    if (points.empty()) {
      return 0;
    }
    int res = 1;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        if (points[i].x == points[j].x) {
          mp2[points[i].x].insert(i);
          mp2[points[i].x].insert(j);
          res = max(res, (int)mp2[points[i].x].size());
        }else {
          float k = (float)(points[i].y - points[j].y) / (float)(points[i].x - points[j].x);
          float b = points[i].y - k * points[i].x;
          mp1[k][b].insert(i);
          mp1[k][b].insert(j);
          res = max(res, (int)mp1[k][b].size());
        }
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  Point p1(3, 10);
  Point p2(0, 2);
  Point p3(0, 2);
  Point p4(3, 10);
  vector<Point> points = {p1, p2, p3, p4};
  cout << s.maxPoints(points) << endl;
  return 0;
}
