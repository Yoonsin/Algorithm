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

	cout << "��ȯ �� ���ڿ��� �Է��� �ּ���." << endl;
	cin >> before;
	cout << "��ȯ �� ���ڿ��� �Է��� �ּ���." << endl;
	cin >> after;

	int** arr; //������ �迭 ����
	arr = new int*[before.length() + 1]; //��
	for (int i = 0; i < before.length() + 1; i++)
		arr[i] = new int[after.length() + 1]; //��

	for (int i = 0; i < before.length() + 1; i++)
	{
		arr[i][0] = i; //0��° �� 1,2...before ���ڿ� ����+1 ������ �ʱ�ȭ. +1�ϴ� ������ 0��° �ε����� �ش��ϴ� ���ڿ��� ���� ����
	}

	for (int i = 0; i < after.length() + 1; i++)
	{
		arr[0][i] = i; //0��° �� 1,2..after ���ڿ� ����+1 ������ �ʱ�ȭ
	}

	int a = 0; //���� �밢�� ��ĭ �� �� ���� �� +1 �Ǵ� +0 �� �־��� ����

	for (int i = 1; i < before.length() + 1; i++)
	{
		for (int j = 1; j < after.length() + 1; j++)
		{
			if (before[i-1] == after[j-1]) //�̹� ������ ��ȯ �� ���ڿ� ��ȯ �� ���ڰ� �����Ŷ��
			{
				a = 0; //���� �ʿ�����Ƿ� 0
			}
			else
			{
				a = 1; //�ƴϸ� ������ 1�� �ʿ��ϹǷ� 1
			}
				

			arr[i][j] = min(arr[i-1][j-1]+a, arr[i-1][j]+1, arr[i][j-1]+1); //���� �밢�� ��ĭ ��, ��ĭ ��(���� ����+1), ��ĭ ���� ��(���� ����+1) ���� ��
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