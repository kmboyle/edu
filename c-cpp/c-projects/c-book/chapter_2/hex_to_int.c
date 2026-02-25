
#include <math.h>
#include <stdio.h>
#include <string.h>
int htoi(char s[]) {
  int i, n = 0;
  int exp = strlen(s) - 1;
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i = 2;
    exp = exp - 2;
  }
  for (; s[i] >= '0' && s[i] <= 'F'; ++i) {
    int alpha;
    if (s[i] >= 'A' && s[i] <= 'F') {
      alpha = (s[i] - 'A') + 10;
    } else {
      alpha = s[i] - '0';
    }
    int result = pow(16, exp);
    n = n + result * alpha;
    exp--;
  }
  return n;
}
int main() {
  printf("convert FF to decimal: %d\n", htoi("FF"));       // 255
  printf("convert 1F7 to decimal: %d\n", htoi("1F7"));     // 503
  printf("convert E7 to decimal: %d\n", htoi("E7"));       // 231
  printf("convert 1000 to decimal: %d\n", htoi("1000"));   // 4096
  printf("convert 0xA7B to decimal: %d\n", htoi("0xA7B")); // 2683
}
