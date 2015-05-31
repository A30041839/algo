#include "leetcode.h"

using namespace std;

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty()){
      return {};
    }
    return merge1(intervals);
  }

  vector<Interval> merge1(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
      [] (const Interval& a, const Interval& b) {return a.start < b.start;});
    vector<Interval> res;
    int n = intervals.size();
    for (int i = 1; i < n; ++i){
      if (intervals[i].start <= intervals[i - 1].end){
        intervals[i].start = intervals[i - 1].start;
        intervals[i].end = max(intervals[i].end, intervals[i - 1].end);
      }else{
        res.push_back(intervals[i - 1]);
      }
    }
    res.push_back(intervals.back());
    return res;
  }
};

int main(){
  Solution s;
  vector<Interval> itv;
  itv.push_back(Interval(1, 3));
  itv.push_back(Interval(2, 6));
  itv.push_back(Interval(8, 10));
  itv.push_back(Interval(15, 18));
  vector<Interval> merged = s.merge(itv);
  for (auto& it : merged){
    cout << it.start << "," << it.end << endl;
  }
  return 0;
}
