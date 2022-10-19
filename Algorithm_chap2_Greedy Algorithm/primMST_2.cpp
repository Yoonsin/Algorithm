#include <stdio.h>
#define TRUE 1
#define FALSE 0

#define VERTICES 7
#define INF 1000

int adj_mat[VERTICES][VERTICES] = {
	{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}
};

int selected[VERTICES];
int dist[VERTICES];

//최소 dist[v]값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v = 0, i = 0;

	for (i = 0; i < n; i++)
	{
		if (!selected[i]) //선택되지 않은 점이면
		{
			v = i;
			break;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (dist[i] < dist[v])) //선택되지 않았고, 그 점에 새로 갈수있게 된 거리가 현재 가는 거리보다 길면
			v = i; //갱신
	}

	return v;
}

void prim(int s, int n)
{
	int i = 0, u = 0, v = 0;

	for (u = 0; u < n; u++)
	{
		dist[u] = INF;
	}

	dist[s] = 0;
	for (i = 0; i < n; i++)
	{
		u = get_min_vertex(n);
		selected[u] = TRUE; //지나간 경로 체크

		if (dist[u] == INF) return;

		printf("정점: %d, 거리: %d \n", u, dist[u]);

		for (v = 0; v < n; v++)
		{
			if (adj_mat[u][v] != INF)
			{
				if (!selected[v] && adj_mat[u][v] < dist[v]) //선택 안됐고, 현재 행렬보다 지금 거리가 크면
				{
					dist[v] = adj_mat[u][v]; //더 작은걸로 갱신
				}
			}
		}
	}

}

int main(void)
{
	prim(0, VERTICES);
}