#include <iostream>
using namespace std;

int main(void)
{
	int change_num = 0;
	cout << "�Ž������� �� �Դϱ�? ";
	cin >> change_num;
	
	int coin_num = 0; 
	cout << "���� ������ �� ���� �Դϱ�? ";
	cin >> coin_num;

	int* coin = new int[coin_num](); //���� ����
	int* change = new int[change_num+1](); //���� ����

	change[0] = 0; //0������ ���� 0 �� ��

	for (int i = 0; i < coin_num; i++)
	{
		cout << i << " ��° ������ �� �Դϱ�? ";
		cin >> coin[i];
	}


	for (int i = 1; i < change_num+1; i++) //i�� �Ž����� �׼�. 1������ �Ѿ� ���� �˻� 
	{
		for (int j = 0; j < coin_num; j++) //ù��° ���� ���� ������ ���� ���� �˻�
		{
			if (coin[j] <= i) //���� ���� ������ ���� �� �ִٸ� 
			{
				change[i] = change[i - coin[j]]+1; //�� ���� ���� �� �Ž����� ���� ���� ������ +1 �߰�  (���� 1�� �ֱ�)
				 
			}
		}
	}
	 
	cout << "�Ž����� " << change_num << " �� ���� ������ �ּ� ������ " << change[change_num] << "�� �Դϴ�. ";

	delete[] coin;
	delete[] change;

	return 0;

}