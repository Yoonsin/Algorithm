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
	for (i = 0; i < n; i++) //i+1 => 부분문제의 크기. ex. i=1일 때 dp[0][1], dp[1][2]..dp[n-1][1] A1xA2, A2XA3...이렇게 됨
	{
		for (j = 0; j < n - i; j++) //n-i까지 해야 b가 n까지 가서 멈출수있음 그냥 n으로가면 더 넘어버림
		{
			a = j; //행
			b = j + i; //열 
			if (a == b) //같으면 (dp[0][0]이면 그냥 행렬 1개니까 행렬 간 최소 곱셈횟수는 0.)
			{
				dp[a][b] = 0;
			}
			else
			{
				dp[a][b] = 987654321;
				for (k = a; k < b; k++) //대각선간 괄호 어떻게 치기에 따라 바뀌는 값 넣기
				{
					dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
					//ex.k=0 dp[0][2] = min(dp[0][2] / dp[0][0] + dp[1][2] + (A0의 n * Ak의 m * Ab의 m)
					//   k=1 dp[0][2] = min(dp[0][2] / dp[0][1] + dp[2][2] + (A0의 n * Ak의 m * Ab의 m)
					//아니 그러면 만약 k=0에 더작은 값이 들어있어도 k=1으로 갱신하는거임?
					//k=0에 더 작은값은 미리 dp[a][b]에 넣어줘서 걔랑 비교할 수 있게 했네
				}
			}
		}
	}

	return dp[0][n - 1]; //for문의 마지막 라운드에서 i==n이었다가 문을 나갈 때 i++되서 i==n+1이므로 i를 -1시켜준다.
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
	printf("최소연산 횟수 : %d\n", ans);

	return 0;
}