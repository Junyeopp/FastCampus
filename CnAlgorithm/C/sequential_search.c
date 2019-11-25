#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100

char **array;
int founded;

int main(void) {
    int n;
    char *word;
    word = malloc(sizeof(char) * 100);
    scanf("%d %s", &n, word);
    array = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        array[i] = malloc(sizeof(char) * LENGTH);
        scanf("%s", array[i]);
    }
    for (int i = 0; i < n; i++) {
        if (!strcmp(array[i], word)) {
            printf("%dth element\n", i + 1);
            founded = 1;
        }
    }
    if (!founded) printf("fail\n");
    system("pause");
    return 0;
}