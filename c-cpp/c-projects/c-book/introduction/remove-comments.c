#include <stdio.h>
#define MAXLINE 10000

int get_line(char s[], int maxline);
void remove_comments(char line[], char removed_comments[]);

int main() {
  char line[MAXLINE];
  char removed_comments[MAXLINE];

  while ((get_line(line, MAXLINE)) > 0) {
    remove_comments(line, removed_comments);
    printf("%s", removed_comments);
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

void remove_comments(char line[], char removed_comments[]) {

  int i, j;
  int column = 0;
  int inside = 0;
  for (i = 0, j = 0; line[i] != '\0'; ++i, ++j) {
    // removed_comments[j] = line[i];

    if (removed_comments[j] == '\n') {
      column = 0;
    }
    column++;

    if (line[j] == '/' && line[j + 1] == '*') {
      inside = j + 1;
      while (line[++inside] != '*' && getchar() != EOF) {
        j++;
        continue;
      }
      removed_comments[j] = line[i];
    }
    if (line[j] != '/' && line[j + 1] != '/') {
      removed_comments[j] = line[i];
    }
  }
  removed_comments[j] = '\0';
}
