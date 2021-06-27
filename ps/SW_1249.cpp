//[SW] 1249 : 보급로

#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
 
int result[101][101];
int map[101][101];
int visit[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
 
int main() {
    int TC, N;
    scanf("%d", &TC);
 
    queue<pair<int,int>> q;
    for (int test_case = 1; test_case <= TC; test_case++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                scanf("%1d", &map[i][j]);
 
        //초기화
        memset(visit, 0, sizeof(visit));
        memset(result, 0, sizeof(result));
 
        //bfs
        q.push({ 1,1 });
        visit[1][1] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
 
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > 0 && ny > 0 && nx <= N && ny <= N) {
                    if (!visit[nx][ny]) {
                        result[nx][ny] = result[x][y] + map[nx][ny];
                        visit[nx][ny] = true;
                        q.push({ nx,ny });
                    }
                    else if (visit[nx][ny] && result[nx][ny] > result[x][y] + map[nx][ny]) {
                        result[nx][ny] = result[x][y] + map[nx][ny];
                        q.push({ nx,ny });
                    }
                }
            }
        }
 
        printf("#%d %d\n", test_case, result[N][N]);
    }
 
    return 0;
}