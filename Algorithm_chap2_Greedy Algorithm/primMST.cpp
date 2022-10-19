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


//현재 갈수 있는 거리중 최소로 갈수 있는 정점 반환
int FindMinVertix(int n)
{
	int tempDistIndex = 0;

	for (int i = 0; i < n; i++) //여기 for문은 아래 for문에서 맨처음 라운드에 비교할 대상값을 넣어주어야 하기 때문에 돌리는거
	{
		if (!selected[i])
		{
			tempDistIndex = i; //인덱스는 인덱스에 넣어주자
			break;
		}//선택되지 않은 점 선택

	}

	for (int i = 0; i < n; i++)
	{    
		if (!selected[i] && (dist[i] < dist[tempDistIndex]))
		{
			//다른 선택되지 않은 점이고 아까 맨 처음 선택한 얘들보다 딴 얘들이 작으면 
			tempDistIndex = i; //그걸로 갱신
		}
	}

	return tempDistIndex; //값이 아니라 인덱스를 반환해야함..
}

//프림 알고리즘
void prim(int s,int n) //s는 시작할 임의의 점!!!!! n은 정점의 갯수
{
	int m = 0;

	for (int i = 0; i < n; i++)
	{
		dist[i] = INF; //dist값 전부 INF로 우선 초기화
	}
	dist[s] = 0;

	for (int i = 0; i < n; i++)
	{
		m = FindMinVertix(n); //최소로 갈수 있는 정점의 인덱스 갱신하고
		selected[m] = TRUE; //지나간 경로 체크

		if (dist[m] == INF) //아니..ㅋㅋ 왜 아까 dist[i] INF초기화 시켜줬는데 이건 무슨일이야
			return;
		
		printf("정점: %d, 거리: %d \n", m, dist[m]);

		//dist는 각 정점간의 거리?
		for (int j = 0; j < n; j++)
		{
			if (adj_mat[m][j] != INF)
			{
				if (!selected[j] && adj_mat[m][j] < dist[j]) //선택하지 않았고, 현재 가는 거리보다 더 짧으면
				{
					dist[j] = adj_mat[m][j]; //갈 수 있는 거리 갱신
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