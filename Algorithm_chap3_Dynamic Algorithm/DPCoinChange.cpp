#include <iostream>
using namespace std;

int main(void)
{
	int change_num = 0;
	cout << "거스름돈은 얼마 입니까? ";
	cin >> change_num;
	
	int coin_num = 0; 
	cout << "동전 종류는 몇 가지 입니까? ";
	cin >> coin_num;

	int* coin = new int[coin_num](); //동전 종류
	int* change = new int[change_num+1](); //동전 갯수

	change[0] = 0; //0원에는 동전 0 개 들어감

	for (int i = 0; i < coin_num; i++)
	{
		cout << i << " 번째 동전은 얼마 입니까? ";
		cin >> coin[i];
	}


	for (int i = 1; i < change_num+1; i++) //i는 거스름돈 액수. 1원부터 총액 까지 검사 
	{
		for (int j = 0; j < coin_num; j++) //첫번째 동전 부터 마지막 동전 까지 검사
		{
			if (coin[j] <= i) //만약 돈에 동전을 넣을 수 있다면 
			{
				change[i] = change[i - coin[j]]+1; //그 동전 값을 뺀 거스름돈 값의 동전 갯수에 +1 추가  (동전 1개 넣기)
				 
			}
		}
	}
	 
	cout << "거스름돈 " << change_num << " 에 대한 동전의 최소 갯수는 " << change[change_num] << "개 입니다. ";

	delete[] coin;
	delete[] change;

	return 0;

}