//[SW] 12052. 부서진 타일

#include <stdio.h>

int main()
{
	int TC, flag;
	char map[50][50];
	int n, m;
	int dx[] = {0, 1, 1};
	int dy[] = {1, 0, 1};

	scanf("%d", &TC);

	//test case
	for (int test_case = 1; test_case <= TC; test_case++)
	{
		//input
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", &map[i]);
		
		//greedy
		flag = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '#')
				{
					//2x2 tile
					for (int k = 0; k < 3; k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < n && ny < m)
						{
							if (map[nx][ny] == '.')
							{
								flag = 0;
								break;
							}
							else
								map[nx][ny] = '.';
						}
						else
						{
							flag = 0;
							break;
						}
					}
				}
				if (!flag) break;
			}
			if (!flag) break;
		}

		//result
		if (flag)
			printf("#%d YES\n", test_case);
		else
			printf("#%d NO\n", test_case);
	}
	return (0);
}