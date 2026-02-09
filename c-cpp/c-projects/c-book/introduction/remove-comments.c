/* Ex. 1.23 */
#include <stdio.h>
#define MAXLINE 10000
#define TRUE (1 == 1)
#define FALSE !TRUE

// This is a test comment

int get_line(char s[], int maxline); // This is another test comment.
void remove_comments(char line[], char removed_comments[]);

int main() {
  /**
   * This is a multiline
   * block
   * comment.
   */

  char line[MAXLINE];
  char removed_comments[MAXLINE];

  get_line(line, MAXLINE);
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
  int c;
  int i = 0;

  while (i < lim - 1 && (c = getchar()) != EOF) {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

void remove_comments(char line[], char removed_comments[]) {

  int i = 0;
  int j = 0;
  int line_comment = FALSE;
  int block_commet = FALSE;
  int in_quote = FALSE;
  while (line[i] != '\0') {
    if (!block_commet) {
      if (!in_quote && line[i] == '"') {
        in_quote = TRUE;
      } else if (in_quote && line[i] == '"') {
        in_quote = FALSE;
      }
    }

    if (!in_quote) {
      if (line[i] == '/' && line[i + 1] == '*' && !line_comment) {
        block_commet = TRUE;
      }
    }
  }
  removed_comments[j] = '\0';
}
