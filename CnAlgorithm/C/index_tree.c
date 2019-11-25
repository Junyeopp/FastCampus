#include <stdio.h>
#include <stdlib.h>
#define NUMBER 7

int tree[NUMBER];

int sum(int i) {
    int res = 0;
    while (i > 0) {
        res += tree[i];
        // 마지막 비트만큼 빼면서 앞으로 이동
        i -= (i & -i);
    }
    return res;
}

void update(int i, int dif) {
    while (i <= NUMBER) {
        tree[i] += dif;
        // 마지막 비트만큼 더하면서 뒤로 이동
        i += (i & -i);
    }
}

int getSection(int start, int end) { return sum(end) - sum(start - 1); }

int main(void) {
    update(1, 7);
    update(2, 1);
    update(3, 9);
    update(4, 5);
    update(5, 6);
    update(6, 4);
    update(7, 1);
    printf("1-7 sum: %d\n", getSection(1, 7));
    printf("update : index 6 -> +3\n");
    update(6, 3);
    printf("4-7 sum: %d\n", getSection(4, 7));
    system("pause");
}