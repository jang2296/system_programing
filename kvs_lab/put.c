#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value) {
    printf("put: %s, %s\n", key, value);

    // 노드 업데이트 혹은 새 노드 추가
    node_t* current = kvs->db;
    node_t* prev = NULL;

    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        // 기존 키 업데이트
        free(current->value);
        current->value = strdup(value);
    } else {
        // 새 노드 추가
        node_t* new_node = (node_t*) malloc(sizeof(node_t));
        if (new_node == NULL) return -1;

        strcpy(new_node->key, key);
        new_node->value = strdup(value);
        new_node->next = NULL;

        if (prev == NULL) {
            // 리스트가 비어 있을 때
            kvs->db = new_node;
        } else {
            prev->next = new_node;
        }

        kvs->items++;
    }

    return 0;
}
