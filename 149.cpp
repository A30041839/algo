#include "leetcode.h"

using namespace std;

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    if (points.empty()) {
      return 0;
    }else {
      return maxPoints3(points);
    }
  }

  int maxPoints1(vector<Point> &points) {
    map<pair<float, float>, set<int>> mp;
    int res = 1, n = points.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (points[i].x == points[j].x) {
          mp[{INT_MAX, points[i].x}].insert(i);
          mp[{INT_MAX, points[i].x}].insert(j);
        }else {
          float slope = (float)(points[i].y - points[j].y) / (float)(points[i].x - points[j].x);
          float yintercept = points[i].y - slope * points[i].x;
          mp[{slope, yintercept}].insert(i);
          mp[{slope, yintercept}].insert(j);
        }
      }
    }
    for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
      if (iter->second.size() > res) {
        res = iter->second.size();
      }
    }
    return res;
  }

  //if a-b and a-c has the same slope, then a,b,c are on the same line
  int maxPoints2(vector<Point> &points) {
    int n = points.size(), res = 1;
    for (int i = 0; i < n; ++i) {
      unordered_map<float, int> cnt;
      cnt[INT_MIN] = 0; //for processing duplicate
      int duplicate = 1;
      for (int j = i + 1; j < n; ++j) {
        if (points[i].x == points[j].x and points[i].y == points[j].y) {
          duplicate++;
        }else {
          float slope = points[i].x == points[j].x ?
            INT_MAX : (float)(points[i].y - points[j].y) / (points[i].x - points[j].x);
          cnt[slope]++;
        }
      }
      for (auto iter = cnt.begin(); iter != cnt.end(); ++iter) {
        res = max(res, iter->second + duplicate);
      }
    }
    return res;
  }

  //use fraction to represent slope
  int maxPoints3(vector<Point> &points) {
    int n = points.size(), res = 0;
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; ++i) {
      cnt.clear();
      int duplicate = 1, sameLine = 0;
      for (int j = i + 1; j < n; ++j) {
        if (isSame(points[i], points[j])) {
          duplicate++;
        }else {
          sameLine = max(sameLine, ++cnt[getSlope(points[i], points[j])]);
        }
      }
      res = max(res, sameLine + duplicate);
    }
    return res;
  }

private:
  int gcd(int a, int b) {
    while (b != 0) {
      int tmp = a;
      a = b;
      b = tmp % b;
    }
    return a;
  }

  pair<int, int> getSlope(Point& a, Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int k = gcd(dx, dy);
    if (k) {
      dx /= k;
      dy /= k;
    }
    return {dx, dy};
  }

  bool isSame(Point& a, Point& b) {
    return a.x == b.x and a.y == b.y;
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
