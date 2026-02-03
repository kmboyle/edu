/* Ex. 1-20: Replace tabs in the input with the proper number of blanks to space
 * to the next tab stop. Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter? */
#include <stdio.h>

int main() {
  int n = 6; /* number of columns */
  int c;
  int col = 1;
  while ((c = getchar()) != EOF) {
    if (c == '\t' && col <= n) {
      putchar(' ');
      putchar(' ');
      putchar(' ');
      putchar(' ');
      putchar(' ');
      putchar(' ');
      putchar(' ');
      putchar(' ');
      col++;
    } else if (col > n) {
      putchar('\n');
      putchar(c);
      col = 1;
    } else
      putchar(c);
  }
}
