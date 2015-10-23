class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.empty()) {
          return true;
        }
        int i = 0, j = num.size() - 1;
        while (i <= j) {
          if (num[i] == num[j]) {
              if (num[i] != '8' and num[i] != '1' and num[i] != '0') {
                return false;
              }
          }else {
           if (!((num[i] == '6' and num[j] == '9') or (num[i] == '9' and num[j] == '6'))) {
             return false;
           }
          }
          i++;
          j--;
       }
       return true;
    }
};
