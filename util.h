#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

char* get_random_line(const char* filename) {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Count the number of lines in the file
    int num_lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            num_lines++;
        }
    }

    // Go back to the start of the file
    rewind(file);

    // Choose a random line number
    int line_num = rand() % num_lines;

    // Read the file line by line until we reach the chosen line
    char* line = NULL;
    size_t len = 0;
    for (int i = 0; i <= line_num; i++) {
        getline(&line, &len, file);
    }

    // Close the file and return the line
    fclose(file);
    // remove newline
    line[strlen(line) -1]=0;
    return line;
}


// Function to copy a file from one location to another
void copy_file(const char *src, const char *dst)
{
    // Open the source file
    FILE *src_file = fopen(src, "r");
    if (src_file == NULL)
    {
        printf("Could not open source file: %s\n", src);
        exit(1);
    }

    // Open the destination file
    FILE *dst_file = fopen(dst, "w");
    if (dst_file == NULL)
    {
        printf("Could not open destination file: %s\n", dst);
        fclose(src_file);
        exit(1);
    }

    // Copy the contents of the source file to the destination file
    int c;
    while ((c = fgetc(src_file)) != EOF)
    {
        fputc(c, dst_file);
    }

    // Close the source and destination files
    fclose(src_file);
    fclose(dst_file);
}


#undef explicit_bzero
void explicit_bzero(void *, size_t);
