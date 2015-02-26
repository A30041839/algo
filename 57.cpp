#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int begin = -1, end = -1, pos = 0;
    for (int i = 0; i < intervals.size(); ++i){
      if (intervals[i].start < newInterval.start){
        pos = i + 1;
      }
      if (!(intervals[i].start > newInterval.end or intervals[i].end < newInterval.start)){
        begin = begin == -1 ? i : begin;
        end = i;
      }
    }
    if (begin == -1){
      intervals.insert(intervals.begin() + pos, newInterval);
    }else{
      int s = min(intervals[begin].start, newInterval.start);
      int e = max(intervals[end].end, newInterval.end);
      intervals.erase(intervals.begin() + begin, intervals.begin() + end + 1);
      intervals.insert(intervals.begin() + begin, Interval(s, e));
    }
    return intervals;
  }
};

int main(){
  Solution s;
  vector<Interval> v;
  v.push_back(Interval(1,2));
  v.push_back(Interval(3,5));
  v.push_back(Interval(6,7));
  v.push_back(Interval(8,10));
  v.push_back(Interval(12,16));
  vector<Interval> res = s.insert(v, Interval(-1,0));
  for (auto& interval : res){
    printf("[%d,%d] ", interval.start, interval.end);
  }
  cout << endl;
  return 0;
}
