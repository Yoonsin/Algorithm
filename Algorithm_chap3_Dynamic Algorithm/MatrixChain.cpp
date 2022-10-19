#include <stdio.h>

int matrix[501][2];
int dp[501][501];

int min(int x, int y)
{
	return (x < y ? x : y);
}

int mat(int n)
{
	int a, b;
	int i, j, k;
	for (i = 0; i < n; i++) //i+1 => �κй����� ũ��. ex. i=1�� �� dp[0][1], dp[1][2]..dp[n-1][1] A1xA2, A2XA3...�̷��� ��
	{
		for (j = 0; j < n - i; j++) //n-i���� �ؾ� b�� n���� ���� ��������� �׳� n���ΰ��� �� �Ѿ����
		{
			a = j; //��
			b = j + i; //�� 
			if (a == b) //������ (dp[0][0]�̸� �׳� ��� 1���ϱ� ��� �� �ּ� ����Ƚ���� 0.)
			{
				dp[a][b] = 0;
			}
			else
			{
				dp[a][b] = 987654321;
				for (k = a; k < b; k++) //�밢���� ��ȣ ��� ġ�⿡ ���� �ٲ�� �� �ֱ�
				{
					dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
					//ex.k=0 dp[0][2] = min(dp[0][2] / dp[0][0] + dp[1][2] + (A0�� n * Ak�� m * Ab�� m)
					//   k=1 dp[0][2] = min(dp[0][2] / dp[0][1] + dp[2][2] + (A0�� n * Ak�� m * Ab�� m)
					//�ƴ� �׷��� ���� k=0�� ������ ���� ����־ k=1���� �����ϴ°���?
					//k=0�� �� �������� �̸� dp[a][b]�� �־��༭ �¶� ���� �� �ְ� �߳�
				}
			}
		}
	}

	return dp[0][n - 1]; //for���� ������ ���忡�� i==n�̾��ٰ� ���� ���� �� i++�Ǽ� i==n+1�̹Ƿ� i�� -1�����ش�.
}


int main(void)
{
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &matrix[i][0], &matrix[i][1]);
	}
	int ans = mat(n);
	printf("�ּҿ��� Ƚ�� : %d\n", ans);

	return 0;
}