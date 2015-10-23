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
  int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
      return lhs.start < rhs.start;});
    auto cmp = [](const Interval& lhs, const Interval& rhs) {return lhs.end > rhs.end;};
    priority_queue<Interval, vector<Interval>, decltype(cmp)> pq(cmp);
    pq.push(intervals[0]);
    int res = 1;
    int n = intervals.size();
    for (int i = 1; i < n; ++i) {
      if (intervals[i].start < intervals[i - 1].end) {
        while (!pq.empty() and pq.top().end <= intervals[i].start) {
          pq.pop();
        }
        pq.push(intervals[i]);
        res = max(res, (int)pq.size());
      }else {
        pq.pop();
        pq.push(intervals[i]);
      }
    }
    return res;
  }
};
