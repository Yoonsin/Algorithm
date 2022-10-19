#include<stdio.h>

int matrix[500][2]; //n by m 행열의 첫번째 열(=[][0])은 n. 두번째 열(=[][1])은 m으로 생각한다.
int dp[500][500]; //각 행열마다의 곱셈을 하나하나 고려해야 하므로 nxn의 2차원 배열.

int ShortMatrix(int n)
{
	int a = 0;
	int b = 0;
	int k = 0; //괄호치기를 어떻게 해줄지 확인할때 쓸 변수
	int min = 0;
	int temp = 0;

	for (int i = 0; i < n; i++) //부분 문제의 크기 갯수, (i=0은 부분문제 크기가 1개다라는 뜻임)
	{
		for (int j = 0; j < n-i;j++ ) //부분 문제에 따라 원소 돌리는 횟수도 달라짐 ( 1개면 n-1개씩 확인. 이유? 쌍으로 비교하니까)
		{
			a = j; 
			b = j + i;

			if (a == b) //만약 행과 열이 같다면
			{
				dp[a][b] = 0; //그건 1개의 행렬의 행렬 '간' 최소 곱셈수를 따지는 셈이므로 값이 있을 수 없음. 0으로 설정 
			}
			else //아니면
			{
				dp[a][b] = 100000; //일단 초기화는 해줘야 하니까 최대값 넣어줌
				for (k = a; k < b; k++) //dp[a][b] 안에서 괄호를 어떻게 쳐야 최솟값이 나올지 판단
				{
					int temp = dp[a][k]+dp[k+1][b]+(matrix[a][0] * matrix[k][1] * matrix[b][1]);
					if (temp < dp[a][b]) //현재있는 dp[a][b]값보다 temp값이 더 작다면
					{
						dp[a][b] = temp; //새로 갱신시켜 주기
					}
				}
			}
		}
	}

	return dp[0][n-1]; //배열 인덱스는 실제 갯수 -1을 해줘야 하므로 n-1를 해준다.  
}


int main(void)
{
	int answer = 0;
	int n = 10;

	for (int i = 0; i < n; i++) //우선 10개의 행열만 값을 넣어준다.
	{
		scanf("%d %d", &matrix[i][0],&matrix[i][1]);
	}

	answer = ShortMatrix(n);

	printf("최소 행렬 곱셈 값은 %d 입니다.", answer);

	return 0;
}