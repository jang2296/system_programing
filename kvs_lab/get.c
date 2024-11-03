#include "kvs.h"

char* get(kvs_t* kvs, const char* key) {
    node_t* current = kvs->db;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // 값이 있으면 복사하여 반환
            return strdup(current->value);
        }
        current = current->next;
    }

    // 찾지 못했을 때
    printf("[get] Key: %s not found\n", key);
    return NULL;
}
