#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stdout, "wgrep: searchterm [file ...]\n");
    exit(1);
  }
  char *target = argv[1];
  if (strcmp(target, "") == 0) { // empty search term
    exit(0);
  }
  if (argc == 2) { // No search files
    FILE *file = stdin;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file))
      if (strstr(buffer, target))
        printf("%s", buffer);
    exit(0);
  }
  for (int i = 2; i < argc; ++i) {
    FILE *file = fopen(argv[i], "r");
    if (!file) {
      fprintf(stdout, "wgrep: cannot open file\n");
      exit(1);
    }
    char *line = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, file)) != -1)
      {
        if (strstr(line, target))
          printf("%s", line);
      }
    fclose(file);
  }
  exit(0);
}
