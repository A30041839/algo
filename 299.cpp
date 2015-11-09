class Solution {
public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> mp;
    int n = secret.size(), bulls = 0, cows = 0;
    for (char c : secret) mp[c]++;
    for (int i = 0; i < n; ++i) {
      if (secret[i] == guess[i]) {
        bulls++;
        mp[guess[i]]--;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (secret[i] != guess[i] and mp[guess[i]] > 0) {
        cows++;
        mp[guess[i]]--;
      }
    }
    char res[100];
    sprintf(res, "%dA%dB", bulls, cows);
    string r = res;
    return r;
  }
};
