#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv) {
  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }
  int prev = EOF;
  __int32_t count = 0;
  for (int i = 1; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (!file)
      exit(1);
    // Process the file
    int c;
    while((c = fgetc(file)) != EOF){
      if(prev == EOF){
        prev = c;
        count = 1;
      }
      else if(c == prev){
        count++;
      }
      else{
        fwrite(&count, sizeof(__int32_t), 1, stdout);
        unsigned char outc = (unsigned char)prev;
        fwrite(&outc, sizeof(unsigned char), 1, stdout);
        prev = c;
        count = 1;
      }
    }
    fclose(file);
  }
  if (prev != EOF && count > 0) {
    fwrite(&count, sizeof(__uint32_t), 1, stdout);
    unsigned char outc = (unsigned char)prev;
    fwrite(&outc, sizeof(unsigned char), 1, stdout);
  }

  return 0;
}
