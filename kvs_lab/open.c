#include "kvs.h"

kvs_t* open() {
    kvs_t* kvs = (kvs_t*) malloc(sizeof(kvs_t));
    if (kvs) {
        kvs->db = NULL; // 빈 데이터베이스로 초기화
        kvs->items = 0; // 초기 아이템 개수는 0
    }
    printf("Open: kvs has %d items\n", kvs->items);
    return kvs;
}
