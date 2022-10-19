#include <stdio.h>
#define VERTICES 5 //정점의 수
#define INF 1000 //무한대

int Matrix[5][5] = { {0, 4, 2, 5, INF},
				  {INF,0,1,INF,4},
				  {1,3,0,1,2},
				  {-2,INF,INF,0,2},
				  {INF,-3,3,1,0} }; //2차원 배열. m[i][j]는 간선 (i,j)의 가중치



void AllPairsShortest()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp = 0;

	for (int k = 0; k < 5; k++) //k-> 경유 가능한 점
	{
		for (int i = 0; i < 5; i++) //i부터 
		{
			for (int j = 0; j < 5; j++) //j까지의 거리
			{
				temp = Matrix[i][k] + Matrix[k][j]; //경유할 수 있는점 k로 인해 생긴 새로운 i->j의 거리

				if (temp < Matrix[i][j]) //만약 새로운 거리가 현재 거리보다 짧다면
				{
					Matrix[i][j] = temp; //새로 갱신

				}

			}
		}
	}

	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{

			printf("%3d", Matrix[i][j]);
		}

		printf("\n");
	}

}

int main(void)
{

	AllPairsShortest();

	return 0;
}