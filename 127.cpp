#include "leetcode.h"

using namespace std;

class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    return ladderLength1(start, end, dict);
  }

  int ladderLength1(string start, string end, unordered_set<string> &dict) {
    dict.insert(start);
    dict.insert(end);
    return bfs(start, end, dict);
  }
  
  int bfs(string start, string end, unordered_set<string>& dict){
    queue<string> q;
    unordered_set<string> visit;
    visit.insert(start);
    q.push(start);

    int dep = 0;
    while (!q.empty()){
      int n = q.size();
      dep++;
      for (int i = 0; i < n; ++i){
        string w = q.front();
        q.pop();
        if (w == end){
          return dep;
        }
        for (int j = 0; j < w.length(); ++j){
          string w_next = w;
          for (char c = 'a'; c <= 'z'; ++c){
            w_next[j] = c;
            if (w_next != w and dict.count(w_next) > 0 and !visit.count(w_next)){
              visit.insert(w_next);
              q.push(w_next);
            }
          }
        }
      }
    }
    return 0;
  }

};

int main(){
  Solution s;
  unordered_set<string> dict = {"hot","dot","dog","lot","log"};
  string start = "hit";
  string end = "cog";
  cout << s.ladderLength(start, end, dict) << endl;
  return 0;
}
