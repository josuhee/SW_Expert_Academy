//[SW] 격자판의 숫자 이어 붙이기

#include <stdio.h>
#include <math.h>
#include <set>
using namespace std;
 
int arr[4][4];
set<int> s;
 
int dfs(int x, int y, int num, int cnt) {
    //printf("cnt : %d\n", cnt);
    //검사종료
    if (cnt == 7) {
        //집합에 넣을 것
        s.insert(num);
        //printf("num = %d\n", num);
        return 0;
    }
 
    //상하좌우 4방향으로
    if (x - 1 >= 0) dfs(x - 1, y, arr[x - 1][y] * int(pow(10,cnt)) + num, cnt + 1);
    if (x + 1 < 4) dfs(x + 1, y, arr[x + 1][y] * int(pow(10, cnt)) + num, cnt + 1);
    if (y - 1 >= 0) dfs(x, y - 1, arr[x][y - 1] * int(pow(10, cnt)) + num, cnt + 1);
    if (y + 1 < 4) dfs(x, y + 1, arr[x][y + 1] * int(pow(10, cnt)) + num, cnt + 1);
}
 
int main(int argc, char** argv) {
    int test_case, T;
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case){
        //값 입력받기
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &arr[i][j]);
 
        //dfs 시작
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                dfs(i, j, arr[i][j], 1);
 
        printf("#%d %d\n", test_case, s.size());
        s.clear();
    }
 
    return 0;
}