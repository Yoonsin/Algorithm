#include <iostream>
#include <string>
using namespace std;

int min(int temp, int temp2, int temp3)
{
	int min = temp;

	if (min > temp2)
		min = temp2;

	if (min > temp3)
		min = temp3;

	return min;
}


int main()
{
	string before;
	string after;

	cout << "변환 전 문자열을 입력해 주세요." << endl;
	cin >> before;
	cout << "변환 후 문자열을 입력해 주세요." << endl;
	cin >> after;

	int** arr; //이차원 배열 생성
	arr = new int*[before.length() + 1]; //행
	for (int i = 0; i < before.length() + 1; i++)
		arr[i] = new int[after.length() + 1]; //열

	for (int i = 0; i < before.length() + 1; i++)
	{
		arr[i][0] = i; //0번째 열 1,2...before 문자열 길이+1 까지로 초기화. +1하는 이유는 0번째 인덱스에 해당하는 문자열이 없기 때문
	}

	for (int i = 0; i < after.length() + 1; i++)
	{
		arr[0][i] = i; //0번째 행 1,2..after 문자열 길이+1 까지로 초기화
	}

	int a = 0; //왼쪽 대각선 한칸 위 값 구할 때 +1 또는 +0 을 넣어줄 변수

	for (int i = 1; i < before.length() + 1; i++)
	{
		for (int j = 1; j < after.length() + 1; j++)
		{
			if (before[i-1] == after[j-1]) //이번 라운드의 변환 전 문자와 변환 된 문자가 같을거라면
			{
				a = 0; //연산 필요없으므로 0
			}
			else
			{
				a = 1; //아니면 연산이 1번 필요하므로 1
			}
				

			arr[i][j] = min(arr[i-1][j-1]+a, arr[i-1][j]+1, arr[i][j-1]+1); //왼쪽 대각선 한칸 위, 한칸 위(삭제 연산+1), 한칸 왼쪽 값(삽입 연산+1) 각각 비교
		}
	}
	
	for (int i =0; i < before.length() + 1; i++)
	{
		cout << endl;

		for (int j = 0; j < after.length() + 1; j++)
		{
			cout << arr[i][j] << " ";
		}

	}


	for (int i = 0; i < before.length() + 1; i++)
	{
		delete [] arr[i];
	}
		
	delete [] arr;



	return 0;
}