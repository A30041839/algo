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
    int char_read = 0, cur = 0;
    while (char_read < n) {
      cur = read4(buf + char_read);
      char_read += cur;
      if (cur < 4) {
        break;
      }
    }
    char_read = min(char_read, n);
    buf[char_read] = '\0';
    return char_read;
  }
};

int main(){
  return 0;
}
