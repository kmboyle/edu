/* Ex. 1-22: Fold long input lines into two or more shorter lines after
 * the last non-blank character that occurs before the n-th column of input.
 * Handle very long, lines, and if there are no blanks or tabs before the
 * specified column */
#include <stdio.h>
#define MAX_LINE_LENGTH 30
#define MAXLINE 1000

int get_line(char s[], int maxline);

int main() {
  int len;
  char line[MAXLINE];
}
/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
