//[SW] 1868. 파핑파핑 지뢰찾기

#include <stdio.h>
#include <string.h>
 
int table[302][302];
int N;
 
void plusArr(int x, int y) {
    table[x][y] = -1;
    if (table[x - 1][y - 1] != -1) {
        table[x - 1][y - 1]++;
    }
    if (table[x - 1][y] != -1) {
        table[x - 1][y]++;
    }
    if (table[x - 1][y + 1] != -1) {
        table[x - 1][y + 1]++;
    }
    if (table[x][y - 1] != -1) {
        table[x][y - 1]++;
    }
    if (table[x][y + 1] != -1) {
        table[x][y + 1]++;
    }
    if (table[x + 1][y - 1] != -1) {
        table[x + 1][y - 1]++;
    }
    if (table[x + 1][y] != -1) {
        table[x + 1][y]++;
    }
    if (table[x + 1][y + 1] != -1) {
        table[x + 1][y + 1]++;
    }
}
 
int dfs(int x, int y) {
    table[x][y] = -1;
 
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (table[i][j] == 0 && i >= 1 && j >= 1 && i <= N && j <= N) {
                table[i][j] = -1;
                dfs(i, j);
            }
            table[i][j] = -1;
        }
    }
    return 0;
}
 
int main() {
    int T;
    scanf("%d", &T);
 
    char input[301];
    for (int test_case = 1; test_case <= T; test_case++) {
        memset(table, 0, sizeof(table));
        scanf("%d", &N);
 
        //표 입력받기
        for (int i = 0; i < N; i++) {
            scanf("%s", input);
            for (int j = 0; j < N; j++) {
                if (input[j] == '*') {
                    //인접 8칸 1+ 해주기
                    plusArr(i + 1, j + 1);
                }
            }
        }
         
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (table[i][j] == 0) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
 
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (table[i][j] > 0) {
                    cnt++;
                }
            }
        }
 
        printf("#%d %d\n", test_case, cnt);
    }
    return 0;
}