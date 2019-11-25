#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

typedef struct Student {
    int id;
    char name[20];
} Student;

void init(Student** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void destructor(Student** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }
}

// hash table 내 빈 공간을 선형 탐색으로 찾음
int findEmpty(Student** hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
        if (hashTable[i % TABLE_SIZE] ==
            NULL) {  // i++를 하면서 TABLE_SIZE를 벗어날 수도 있어서 한 번 더
                     // 나눠줌
            return i % TABLE_SIZE;
        }
        i++;
    }
}

// 특정 ID 값에 매칭되는 데이터를 hash table내에서 찾음
int search(Student** hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
        if (hashTable[i % TABLE_SIZE] == NULL) {
            return -1;
        } else if (hashTable[i % TABLE_SIZE]->id == id)
            return i;
        i++;
    }
}

// 특정한 key index에 data를 삽입
void add(Student** hashTable, Student* input, int key) {
    hashTable[key] = input;
}

// hash table에서 특정한 key의 data를 반환
Student* getValue(Student** hashTable, int key) { return hashTable[key]; }

// hash table에 존재하는 모든 data를 출력
void show(Student** hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("key : [%d], name : [%s]\n", i, hashTable[i]->name);
        }
    }
}

int main(void) {
    Student** hashTable;
    hashTable = (Student**)malloc(sizeof(Student*) * TABLE_SIZE);
    init(hashTable);

    printf("start");

    for (int i = 0; i < INPUT_SIZE; i++) {
        Student* student = (Student*)malloc(sizeof(Student));
        student->id = rand() % 1000000;
        sprintf(student->name, "Person%d", student->id);
        if (search(hashTable, student->id) == -1) {
            int index = findEmpty(hashTable, student->id);
            add(hashTable, student, index);
        }
    }

    show(hashTable);
    destructor(hashTable);
    system("pause");
    return 0;
}