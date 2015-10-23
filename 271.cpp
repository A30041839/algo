#include "leetcode.h"

using namespace std;

class Codec {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string res;
    int n = strs.size();
    for (int i = 0; i < n; ++i) {
      res.append(to_string(strs[i].size()) + ")" + strs[i]);
    }
    return res;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    int cnt = 0;
    int n = s.size();
    vector<string> res;
    for (int i = 0; i < n;) {
      if (isdigit(s[i])) {
        cnt = cnt * 10 + s[i++] - '0';
      }else {
        string tmp = s.substr(i + 1, cnt);
        res.push_back(tmp);
        i += cnt + 1;
        cnt = 0;
      }
    }
    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

int main() {
  Codec codec;
  vector<string> strs = {"x", "ab??", "bx#$%"};
  string encode = codec.encode(strs);
  auto decode = codec.decode(encode);
  print_vec<string>(decode);
}
