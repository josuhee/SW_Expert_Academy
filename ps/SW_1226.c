//[SW] 1226 : 미로1

#include <stdio.h>
#include <string.h>
#define SIZE 16

int map[17][17];
int visit[17][17];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

t_point start;
t_point end;

void dfs(int x, int y)
{
	visit[x][y] = 1;

	if (end.x == x && end.y == y)
		return ;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && map[nx][ny] != 1 && visit[nx][ny] == 0)
			dfs(nx, ny);
	}
}

int main()
{
	int TC = 10, test_case;

	while (TC--)
	{
		scanf("%d", &test_case);
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2)
					start = (t_point){i, j};
				if (map[i][j] == 3)
					end = (t_point){i,j};
			}
		}
		memset(visit, 0, sizeof(visit));
		dfs(start.x, start.y);
		if (visit[end.x][end.y])
			printf("#%d 1\n", test_case);
		else
			printf("#%d 0\n", test_case);
	}
	return (0);
}