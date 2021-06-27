//[SW] 11736. 평범한 숫자

#include <stdio.h>

int main() {
	int TC, N, cnt;
	int arr[20];

	scanf("%d", &TC);
	for (int test_case = 1; test_case <= TC; test_case++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		cnt = 0;
		for (int i = 1; i < N - 1; i++) {
			if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1])
				cnt++;
			else if (arr[i - 1] > arr[i] && arr[i] > arr[i + 1])
				cnt++;
		}
		printf("#%d %d\n", test_case, cnt);
	}

	return 0;
}