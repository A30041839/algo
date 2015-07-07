#include "leetcode.h"

using namespace std;

class Solution {
private:
  string justify(vector<string>& words, int s, int e, int width) {
    int wordcnt = e - s + 1, wordlen = 0;
    for (int i = s; i <= e; ++i) {
      wordlen += words[i].size();
    }
    int avgsp = 1, leftsp = 0;
    if (wordcnt > 1 and e != words.size() - 1) {
      avgsp = (width - wordlen) / (wordcnt - 1);
      leftsp = (width - wordlen) % (wordcnt - 1);
    }
    string res;
    for (int i = s; i < e; ++i) {
      res.append(words[i]);
      res.append(avgsp, ' ');
      if (leftsp > 0) {
        res.append(1, ' ');
        leftsp--;
      }
    }
    res.append(words[e]);
    if (res.size() < width) {
      //last line
      res.append(width - res.size(), ' ');
    }
    return res;
  }

public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int n = words.size();
    for (int i = 0, j = 0, len = 0; i < n; ++i) {
      if (len + words[i].size() > maxWidth) {
        res.push_back(justify(words, j , i - 1, maxWidth));
        len = words[i].size() + 1;
        j = i;
      }else {
        len += words[i].size() + 1;
      }
      if (i == n - 1) {
        res.push_back(justify(words, j , i, maxWidth));
      }
    }
    return res;
  }
};

int main(){
  Solution s;
  vector<string> words = {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
  auto res = s.fullJustify(words, 30);
  for (auto str : res) {
    cout << str << ":" << str.size() << endl;
  }
  return 0;
}
