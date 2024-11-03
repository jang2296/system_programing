#include "kvs.h"
#include <stdio.h>
#include <string.h>

int main() {
    kvs_t* kvs = open();

    if (!kvs) {
        printf("Failed to open kvs\n");
        return -1;
    }

    // query.dat 파일 읽기
    FILE* input = fopen("query.dat", "r");
    FILE* output = fopen("answer.dat", "w");
    if (!input || !output) {
        printf("Failed to open input or output file\n");
        if (input) fclose(input);
        if (output) fclose(output);
        close(kvs);
        return -1;
    }

    char operation[10], key[100], value[100];
    while (fscanf(input, "%[^,],%[^,],%[^\n]\n", operation, key, value) != EOF) {
        if (strcmp(operation, "put") == 0) {
            if (put(kvs, key, value) != 0) {
                fprintf(output, "put failed for key: %s\n", key);
            }
        } else if (strcmp(operation, "get") == 0) {
            char* result = get(kvs, key);
            if (result) {
                fprintf(output, "get: key = %s, value = %s\n", key, result);
                free(result);
            } else {
                fprintf(output, "get: key = %s not found\n", key);
            }
        } else {
            fprintf(output, "Unknown operation: %s\n", operation);
        }
    }

    fclose(input);
    fclose(output);
    close(kvs);
    return 0;
}
