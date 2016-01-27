class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    return minMeetingRooms1(intervals);
  }

  int minMeetingRooms1(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    int n = intervals.size();
    vector<pair<int, bool>> v;
    for (auto& i : intervals) {
      v.push_back({i.start, true});
      v.push_back({i.end, false});
    }
    sort(v.begin(), v.end(), [](const pair<int, bool>& lhs, const pair<int, bool>& rhs) {
      return lhs.first < rhs.first;});
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i].second) {
        cnt++;
        if (i < v.size() - 1 and !v[i + 1].second and v[i + 1].first == v[i].first) {
          continue;
        }
      }else {
        cnt--;
      }
      res = max(res, cnt);
    }
    return res;
  }

  int minMeetingRooms2(vector<Interval>& intervals) {
    if (intervals.empty()) {
      return 0;
    }
    int n = intervals.size();
    auto cmp = [](Interval& lhs, Interval& rhs) {return lhs.end > rhs.end;};
    priority_queue<Interval, vector<Interval>, decltype(cmp)> pq(cmp);
    sort(begin(intervals), end(intervals), [](Interval& lhs, Interval& rhs) {return lhs.start < rhs.start;});
    int res = 0;
    for (int i = 0; i < n; ++i) {
      pq.push(intervals[i]);
      while (!pq.empty() and pq.top().end <= intervals[i].start) {
        pq.pop();
      }
      res = max(res, (int)pq.size());
    }
    return res;
  }
};
