class Solution {
  int getCode(string word) {
    int res = 0;
    for (int i = 0; i < word.size(); ++i) {
      res |= (1 << (word[i] - 'a'));
    }
    return res;
  }

public:
  int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(make_pair(getCode(words[i]), (int)words[i].size()));
    }
    sort(v.begin(), v.end(), [](pair<int, int>& p1, pair<int, int>& p2) {return p1.second < p2.second;});
    int res = 0;
    for (int i = n - 1; i >= 1; --i) {
      for (int j = i - 1; j >= 0; --j) {
        int len = v[i].second * v[j].second;
        if (len < res) {
          break;
        }
        if ((v[i].first & v[j].first) == 0) {
          res = max(res, len);
        }
      }
    }
    return res;
  }
};
