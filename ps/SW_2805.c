//[SW] 2805. 농작물 수확하기

#include <stdio.h>
 
int main() {
    int T, N;
    scanf("%d", &T);
 
    int sum;
    int arr[50][50];
 
    for (int test_case = 1; test_case <= T; test_case++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%1d", &arr[i][j]);
            }
        }
 
        sum = 0;
        int mid = N / 2;
        for (int i = 0; i < mid; i++) {
            for (int j = mid - i, cnt = 1; cnt <= i * 2 + 1; j++, cnt++) {
                sum += arr[i][j];
            }
        }
 
        for (int i = mid; i < N; i++) {
            for (int j = i - mid, cnt = 1; cnt <= (mid * 2 - i) * 2 + 1; j++, cnt++) {
                sum += arr[i][j];
            }
        }
 
        printf("#%d %d\n", test_case, sum);
    }
 
    return 0;
}