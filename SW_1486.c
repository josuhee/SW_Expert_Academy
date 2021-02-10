//[SW] 1486. 장훈이의 높은 선반

#include <stdio.h>
#define MIN(a,b) a<b?a:b
int H[20];
 
int main() {
    int T, N, B;
    scanf("%d", &T);
 
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d %d", &N, &B);
 
        for (int i = 0; i < N; i++)
            scanf("%d", &H[i]);
 
        int sum, min = 200000;
        for (int check = 1; check < (1 << N); check++) {
            sum = 0;
            for (int i = 0; i < N; i++) {
                if (check & (1 << i)) {
                    sum += H[i];
                }
            }
            //printf("sum = %d\n", sum);
            if (sum > B) {
                min = MIN(min, sum - B);
            }
            if (sum == B) {
                min = 0;
                break;
            }
        }
 
        printf("#%d %d\n", test_case, min);
    }
    return 0;
}