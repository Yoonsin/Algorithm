#include <stdio.h>
#define TRUE 1
#define FALSE 0

#define MAX_VERTIX 7
#define INF 1000


int adj_mat[MAX_VERTIX][MAX_VERTIX] = {
	{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0}
};

int selected[MAX_VERTIX];
int dist[MAX_VERTIX];


//���� ���� �ִ� �Ÿ��� �ּҷ� ���� �ִ� ���� ��ȯ
int FindMinVertix(int n)
{
	int tempDistIndex = 0;

	for (int i = 0; i < n; i++) //���� for���� �Ʒ� for������ ��ó�� ���忡 ���� ����� �־��־�� �ϱ� ������ �����°�
	{
		if (!selected[i])
		{
			tempDistIndex = i; //�ε����� �ε����� �־�����
			break;
		}//���õ��� ���� �� ����

	}

	for (int i = 0; i < n; i++)
	{    
		if (!selected[i] && (dist[i] < dist[tempDistIndex]))
		{
			//�ٸ� ���õ��� ���� ���̰� �Ʊ� �� ó�� ������ ��麸�� �� ����� ������ 
			tempDistIndex = i; //�װɷ� ����
		}
	}

	return tempDistIndex; //���� �ƴ϶� �ε����� ��ȯ�ؾ���..
}

//���� �˰���
void prim(int s,int n) //s�� ������ ������ ��!!!!! n�� ������ ����
{
	int m = 0;

	for (int i = 0; i < n; i++)
	{
		dist[i] = INF; //dist�� ���� INF�� �켱 �ʱ�ȭ
	}
	dist[s] = 0;

	for (int i = 0; i < n; i++)
	{
		m = FindMinVertix(n); //�ּҷ� ���� �ִ� ������ �ε��� �����ϰ�
		selected[m] = TRUE; //������ ��� üũ

		if (dist[m] == INF) //�ƴ�..���� �� �Ʊ� dist[i] INF�ʱ�ȭ ������µ� �̰� �������̾�
			return;
		
		printf("����: %d, �Ÿ�: %d \n", m, dist[m]);

		//dist�� �� �������� �Ÿ�?
		for (int j = 0; j < n; j++)
		{
			if (adj_mat[m][j] != INF)
			{
				if (!selected[j] && adj_mat[m][j] < dist[j]) //�������� �ʾҰ�, ���� ���� �Ÿ����� �� ª����
				{
					dist[j] = adj_mat[m][j]; //�� �� �ִ� �Ÿ� ����
				}
			}
			
		}


	}

	
}

int main(int avgc, char* argv)
{
	prim(0,MAX_VERTIX);

	return 0;
}