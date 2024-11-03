#ifndef KVS_H
#define KVS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 정의 (Skip List를 사용하지 않는 기본 구조)
typedef struct node {
    char key[100];
    char* value;
    struct node* next;
} node_t;

// Key-Value Store 정의
typedef struct kvs {
    node_t* db; // 데이터베이스 연결 리스트의 시작점
    int items;  // 저장된 아이템의 수
} kvs_t;

// 함수 선언
kvs_t* open();
int close(kvs_t* kvs); // 모든 메모리 공간 해제
int put(kvs_t* kvs, const char* key, const char* value); // 데이터 저장
char* get(kvs_t* kvs, const char* key); // 데이터 검색, 없는 경우 NULL 반환

#endif // KVS_H
