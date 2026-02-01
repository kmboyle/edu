#include <stdio.h>

int test() {
  if (0)
    printf("never here");
  else
    printf("0 is false");
}
int main() {
  print("test");
  test();
  return 0;
}
