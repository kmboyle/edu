/* Ex. 1-22: Fold long input lines into two or more shorter lines after
 * the last non-blank character that occurs before the n-th column of input.
 * Handle very long lines, and if there are no blanks or tabs before the
 * specified column */
#include <stdio.h>
#define BREAK_POINT 30
#define OFFSET 10
#define MAXLINE 10000

#define TRUE (1 == 1)
#define FALSE !TRUE

int get_line(char s[], int maxline);
void fold_line(char line[], char fold_str[], int n_break);

int main() {
  char line[MAXLINE];
  char fold_str[MAXLINE];

  while ((get_line(line, MAXLINE)) > 0) {
    fold_line(line, fold_str, BREAK_POINT);
    printf("%s", fold_str);
  }
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
/* fold_line takes current line and splits to smaller lines */
void fold_line(char line[], char fold_str[], int n_break) {
  int i, j;
  int column = 0;
  int split = FALSE;
  int last_blank = 0;

  for (i = 0, j = 0; line[i] != '\0'; ++i, ++j) {
    fold_str[j] = line[i];

    if (fold_str[j] == '\n') {
      column = 0;
    }

    column++;

    if (column == n_break - OFFSET) {
      split = TRUE;
    }

    if (split && (fold_str[j] == ' ' || fold_str[j] == '\t')) {
      last_blank = j;
    }

    if (column == n_break) {
      if (last_blank) {
        fold_str[last_blank] = '\n';
        column = j = last_blank;
        last_blank = 0;
      } else {
        fold_str[j++] = '-';
        fold_str[j] = '\n';

        column = 0;
      }

      split = FALSE;
    }
  }
  fold_str[j] = '\0';
}
