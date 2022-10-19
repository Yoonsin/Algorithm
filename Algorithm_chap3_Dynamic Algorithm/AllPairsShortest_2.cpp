#include <stdio.h>
#define VERTICES 5 //������ ��
#define INF 1000 //���Ѵ�

int Matrix[5][5] = { {0, 4, 2, 5, INF},
				  {INF,0,1,INF,4},
				  {1,3,0,1,2},
				  {-2,INF,INF,0,2},
				  {INF,-3,3,1,0} }; //2���� �迭. m[i][j]�� ���� (i,j)�� ����ġ



void AllPairsShortest()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp = 0;

	for (int k = 0; k < 5; k++) //k-> ���� ������ ��
	{
		for (int i = 0; i < 5; i++) //i���� 
		{
			for (int j = 0; j < 5; j++) //j������ �Ÿ�
			{
				temp = Matrix[i][k] + Matrix[k][j]; //������ �� �ִ��� k�� ���� ���� ���ο� i->j�� �Ÿ�

				if (temp < Matrix[i][j]) //���� ���ο� �Ÿ��� ���� �Ÿ����� ª�ٸ�
				{
					Matrix[i][j] = temp; //���� ����

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