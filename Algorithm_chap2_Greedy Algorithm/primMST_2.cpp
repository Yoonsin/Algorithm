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

//�ּ� dist[v]���� ���� ������ ��ȯ
int get_min_vertex(int n)
{
	int v = 0, i = 0;

	for (i = 0; i < n; i++)
	{
		if (!selected[i]) //���õ��� ���� ���̸�
		{
			v = i;
			break;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (!selected[i] && (dist[i] < dist[v])) //���õ��� �ʾҰ�, �� ���� ���� �����ְ� �� �Ÿ��� ���� ���� �Ÿ����� ���
			v = i; //����
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
		selected[u] = TRUE; //������ ��� üũ

		if (dist[u] == INF) return;

		printf("����: %d, �Ÿ�: %d \n", u, dist[u]);

		for (v = 0; v < n; v++)
		{
			if (adj_mat[u][v] != INF)
			{
				if (!selected[v] && adj_mat[u][v] < dist[v]) //���� �ȵư�, ���� ��ĺ��� ���� �Ÿ��� ũ��
				{
					dist[v] = adj_mat[u][v]; //�� �����ɷ� ����
				}
			}
		}
	}

}

int main(void)
{
	prim(0, VERTICES);
}