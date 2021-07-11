//[SW] 10994 : 동전 수집

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int	TC;
	int	N, K;
	int c, e;
	vector<pair<int, int>> coin;

	scanf("%d", &TC);
	for (int test_case = 1; test_case <= TC; test_case++)
	{
		scanf("%d %d", &N, &K);

		//input coin
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &c, &e);
			coin.push_back({c, e});
		}

		//algoirthm
		int sum = 0;
		int cnt = 0;
		
		for (int i=0;i<N;i++)
		{
			if (sum + coin[i].first >= K)
				break ;
			if (coin[i].second == 0)
			{
				if (sum + coin[i].first < coin[i + 1].first || i == N - 1)
				{
					sum += coin[i].first;
					cnt++;
				}
			}
		}
		if (sum == 0)
			sum = 1;

		//result
		printf("#%d %d %d\n", test_case, cnt, K - sum);
			
		//clear vector
		coin.clear();
	}
	return (0);
}
