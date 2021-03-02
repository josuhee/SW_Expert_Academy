//[SW] 10580 : 전봇대

#include <stdio.h>
 
typedef struct _point {
    int x;
    int y;
}point;
 
point p[1000];
int main(void)
{
    int test_case;
    int T, N, a, b, cnt;
     
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d", &N);
        cnt = 0;
        for (int i = 0; i < N; i++)
            scanf("%d %d", &p[i].x, &p[i].y);
        for (int i = 0; i < N - 1; i++) {
            for (int j = i+1; j < N; j++) {
                a = p[i].x - p[j].x;
                b = p[i].y - p[j].y;
                if ((a < 0 && b>0) || (a > 0 && b < 0)) cnt++;
            }
        }
        printf("#%d %d\n", test_case, cnt);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}