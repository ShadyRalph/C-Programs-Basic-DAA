#include <stdio.h>
#include <stdlib.h>
#define Buff 1024
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }
    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }
    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        printf("Error opening destination file.\n");
        fclose(source);
        return 1;
    }
    char buffer[Buff];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, Buff, source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }
    fclose(source);
    fclose(destination);
    printf("File copied successfully.\n");
    return 0;
}