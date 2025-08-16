#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (!file)
      exit(1);
    uint32_t count = 0;
    unsigned char ch;
    while ((fread(&count, sizeof(uint32_t), 1, file) == 1) &&
           (fread(&ch, sizeof(unsigned char), 1, file) == 1)) {
      for (uint32_t j = 0; j < count; j++)
        putchar(ch);
    }
    fclose(file);
  }
  return 0;
}
