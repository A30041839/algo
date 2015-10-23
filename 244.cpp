class WordDistance {
  unordered_map<string, vector<int>> pos;
public:
  WordDistance(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n; ++i) {
      pos[words[i]].push_back(i);
    }
  }

  int shortest(string word1, string word2) {
    vector<int>& v = pos[word1];
    int res = INT_MAX;
    for (int p2 : pos[word2]) {
      int i = 0, j = v.size() - 1;
      while (i <= j) {
        int mid = i + (j - i) / 2;
        res = min(res, abs(p2 - v[mid]));
        if (p2 > v[mid]) {
          i = mid + 1;
        }else {
          j = mid - 1;
        }
        if (res == 1) {
          return 1;
        }
      }
    }
    return res;
  }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
