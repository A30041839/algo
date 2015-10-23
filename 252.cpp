#include "leetcode.h"

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    if (intervals.size() < 2) {
      return true;
    }
    auto cmp = [](const Interval& lhs, const Interval& rhs) {return lhs.start < rhs.start;};
    sort(intervals.begin(), intervals.end(), cmp);
    int n = intervals.size();
    for (int i = 1; i < n; ++i) {
      if (intervals[i].start < intervals[i - 1].end) {
        return false;
      }
    }
    return true;
  }
};
