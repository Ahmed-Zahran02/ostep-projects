#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Your code here
    if (argc < 2) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (!file) {
            fprintf(stdout, "wcat: cannot open file\n");
            exit(1);
        }
        // Read and print the contents of the file
        char buffer[2 * 1024];
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    }
    return 0;
}