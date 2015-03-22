#include "leetcode.h"

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char *buf, int n) {
    int num_chars_read = 0;
    int cnt;
    while (num_chars_read < n and (cnt = read4(buf))) {
      buf += cnt;
      num_chars_read += cnt;
    }
    if (num_chars_read >= n) {
      buf[n] = '\0';
      num_chars_read = n;
    }
    return num_chars_read;
  }
};

int main(){
  return 0;
}
