//[SW] 10966 : 물놀이를 가자

#include <stdio.h>
#include <string.h>
#include <vector>
#define MIN(a,b) a<b?a:b
using namespace std;
 
char map[4000][4000];
int arr[2000][2000];
int visit[2000][2000];
int N, M;
/*
void printArr() {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
*/
int main() {
    int T, sum;
    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    scanf("%d", &T);
    for (int test_case = 1; test_case <= T; test_case++) {
        memset(arr, 0, sizeof(arr));
        memset(visit, 0, sizeof(visit));
        sum = 0;
        scanf("%d %d", &N, &M);
 
        for (int i = 0; i < N; i++) {
            scanf("%s", map[i]);
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 'L') arr[i][j] = 2000;
                else {
                    v1.push_back(make_pair(i, j));
                    visit[i][j] = 1;
                }
            }
        }
        int num = 1;
        int cnt = 0, v = 1;
        while (cnt!=N*M) {
            //printf("cnt : %d, NM : %d\n", cnt, N * M);
            if (v == 1) {
                cnt += v1.size();
                //if (cnt == N * M) break;
                for (int i = 0; i < v1.size(); i++) {
                    int x = v1[i].first;
                    int y = v1[i].second;
 
                    if (x + 1 < N && !visit[x + 1][y]) {
                        arr[x + 1][y] = MIN(num, arr[x + 1][y]);
                        v2.push_back(make_pair(x + 1, y));
                        visit[x + 1][y] = 1;
                    }
                    if (x - 1 >= 0 && !visit[x - 1][y]) {
                        arr[x - 1][y] = MIN(num, arr[x - 1][y]);
                        v2.push_back(make_pair(x - 1, y));
                        visit[x - 1][y] = 1;
                    }
                    if (y + 1 < M && !visit[x][y + 1]) {
                        arr[x][y + 1] = MIN(num, arr[x][y + 1]);
                        v2.push_back(make_pair(x, y + 1));
                        visit[x][y + 1] = 1;
                    }
                    if (y - 1 >= 0 && !visit[x][y - 1]) {
                        arr[x][y - 1] = MIN(num, arr[x][y - 1]);
                        v2.push_back(make_pair(x, y - 1));
                        visit[x][y - 1] = 1;
                    }
                }
                v1.clear();
                num++;
                v = 0;
            }
            else {
                cnt += v2.size();
                //if (cnt == N * M) break;
                for (int i = 0; i < v2.size(); i++) {
                    int x = v2[i].first;
                    int y = v2[i].second;
 
                    if (x + 1 < N && !visit[x + 1][y]) {
                        arr[x + 1][y] = MIN(num, arr[x + 1][y]);
                        v1.push_back(make_pair(x + 1, y));
                        visit[x + 1][y] = 1;
                    }
                    if (x - 1 >= 0 && !visit[x - 1][y]) {
                        arr[x - 1][y] = MIN(num, arr[x - 1][y]);
                        v1.push_back(make_pair(x - 1, y));
                        visit[x - 1][y] = 1;
                    }
                    if (y + 1 < M && !visit[x][y + 1]) {
                        arr[x][y + 1] = MIN(num, arr[x][y + 1]);
                        v1.push_back(make_pair(x, y + 1));
                        visit[x][y + 1] = 1;
                    }
                    if (y - 1 >= 0 && !visit[x][y - 1]) {
                        arr[x][y - 1] = MIN(num, arr[x][y - 1]);
                        v1.push_back(make_pair(x, y - 1));
                        visit[x][y - 1] = 1;
                    }
                }
                v2.clear();
                num++;
                v = 1;
            }
            //printArr();
        }
 
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                sum += arr[i][j];
        printf("#%d %d\n", test_case, sum);
        v1.clear();
        v2.clear();
    }
    return 0;
}