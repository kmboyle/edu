/* Buid histogram of modification hour of files */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

/* Hour-by-hour histogram of modification time */
int modtimehist[24];
int rflag = 0, aflag = 0;

void processfile(char *name) {
  struct stat sb;    /* The stat buffer */
  struct tm *bdtime; /* Broken down time */

  printf("processing file %s\n", name);
  if (stat(name, &sb) < 0) {
    perror(name);
    exit(2);
  }

  bdtime = localtime(&sb.st_mtime);
  modtimehist[bdtime->tm_hour]++;
}

void processdir(char *dirname) {
  DIR *d;
  struct dirent *info;
  char fullfilename[PATH_MAX];
  struct stat sb;

  printf("processing directory %s\n", dirname);
  d = opendir(dirname);
  if (d == NULL) {
    perror(dirname);
    exit(1);
  }

  while ((info = readdir(d)) != NULL) {
    if (info->d_name[0] == '.' && !aflag)
      continue;
    /* Build absolute name of file */
    strcpy(fullfilename, dirname);
    strcat(fullfilename, "/");
    strcat(fullfilename, info->d_name);
    /* Recurse if rflag set, but not an "." or ".." */
    /* strcmp returns an int, if values are equal, returns 0, otherwise > 0 */
    stat(fullfilename, &sb);
    if (strcmp(info->d_name, ".") && strcmp(info->d_name, "..") && rflag &&
        S_ISDIR(sb.st_mode))
      processdir(fullfilename); /* Recurse */
    else
      processfile(fullfilename);
  }
  closedir(d);
}
int main(int argc, char *argv[]) {
  int i, c;
  char dirname[PATH_MAX];

  /* Zero out the historgram */
  for (i = 0; i < 24; i++)
    modtimehist[i] = 0;

  opterr = 0; /* Surpress getopt's own error messages */

  while ((c = getopt(argc, argv, "ar")) != EOF) {
    switch (c) {
    case 'a':
      aflag = 1;
      break;
    case 'r':
      rflag = 1;
      break;
    case '?':
      fprintf(stderr, "invalid option: %c\n", optopt);
    }
  }

  argv += optind; /* Adjust to move past the options */
  argc -= optind;

  if (argc != 1) {
    fprintf(stderr, "usage: modtimehist [-a] [-r] drname\n");
    exit(1);
  }
  /* If not an absolute path, make it so */
  if (argv[0][0] == '/')
    strncpy(dirname, argv[0], PATH_MAX);
  else {
    getcwd(dirname, PATH_MAX);
    strcat(dirname, "/");
    strcat(dirname, argv[0]);
  }
  processdir(dirname);

  /* Display the histogram */
  for (i = 0; i < 24; i++)
    printf("hour %2d: count = %6d\n", i, modtimehist[i]);
}
