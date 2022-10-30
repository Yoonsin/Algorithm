#include <iostream>
using namespace std;

//k[i,w] ���� 1~i������ ����ϰ�, (�ӽ�) �賶�� �뷮�� w�� ���� �ִ� ��ġ
//i = 1,2,...n �̰� w = 1,2...c �̴�.
//k[i,w] = max(k[i-1,w], k[i-1,w-w^i]+ i�� ��ġ v^i])

//**�ʱ� k �迭�� ����**
//k 0 1 2 3 4..w
//0 0 0 0 0 0  //���� �ƹ��͵� ��� ���ϴϱ� ��ġ�� ��
//1 0
//2 0
//..0
//i 0 // �賶 �뷮�� �����ϱ� ��

//��ġ�� ���� ��������� �����ϴ� ���� Ŭ����
class Stuff
{
	public:
	  int weight; //����
	  int value; //��ġ 
	  Stuff(); //���� ������
	  Stuff(int weight,int value); //Ÿ�� ������
	  void setStuff(int weight, int value);
};

Stuff::Stuff() : Stuff(0,0)
{}

Stuff::Stuff(int weight,int value)
{
	this->weight = weight;
	this->value = value;
}

void Stuff::setStuff(int weight, int value)
{
	this->weight = weight;
	this->value = value;
}

int max(int temp,int temp_2)
{
	int max = temp;
	if (max < temp_2)
		max = temp_2;

	return max;
}

int main(void)
{
	int bagWeight = 0; //�賶 �뷮
	int stuffNum = 0; //���� ����

	cout << "�賶�� �뷮�� �Է����ּ���. : ";
	cin >> bagWeight;
	cout <<endl<< "������ ������ �Է����ּ���.: ";
	cin >> stuffNum;

	//��ġ�� ���� ������ �迭 k ����
	int** arr;
	arr = new int*[stuffNum+1];
	for (int i = 0; i < stuffNum+1; i++)
	{
		arr[i] = new int[bagWeight + 1];
	}

	for (int i = 0; i < stuffNum + 1; i++)
	{
		arr[i][0] = 0; //0��° �� �ʱ�ȭ
	}

	for (int i = 0; i < bagWeight + 1; i++)
	{
		arr[0][i] = 0; //0��° �� �ʱ�ȭ
	}



	int weight = 0;
	int value = 0;
	Stuff *s = new Stuff[stuffNum+1]; //���� �迭 ����

	s[0].setStuff(0, 0); //ù��°�� ���� ������ �����ϱ� 0,0���� �ʱ�ȭ
	for (int i = 1; i < stuffNum+1; i++)
	{
		cout << endl << "���� " << i << " �� ����: ";
		cin >> weight;
		cout << "���� " << i << " �� ��ġ: ";
		cin >> value;

		s[i].setStuff(weight, value);
	}

	for (int i = 1; i < stuffNum+1; i++)
	{
		for (int j = 1; j < bagWeight + 1; j++)
		{
		
			if (j >= s[i].weight)
			{
				arr[i][j] = max(arr[i - 1][j], arr[i-1][j - (s[i].weight)] + s[i].value); //�� ���������� ������ ����Ѱ� �� ũ��? ���� �� ��ǰ�� ������ �� ũ��? 
			}
			else
			{
				arr[i][j] = arr[i - 1][j];
			}
			
			
		}
	}

	cout << endl << "�賶 �뷮 ";
	for (int i = 0; i < bagWeight+1; i++)
	{
		cout << i << " ";
	}

	for (int i = 0; i < stuffNum + 1; i++)
	{
		
		cout << endl<< "���� " << i << " ����: " << s[i].weight << "��ġ "<< s[i].value << " ";
		for (int j = 0; j < bagWeight + 1; j++)
		{
			cout << arr[i][j] << " ";
		}
	}

	for (int i = 0; i < stuffNum + 1; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
	
	delete[] s;


	return 0;
}