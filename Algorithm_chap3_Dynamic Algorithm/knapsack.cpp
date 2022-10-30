#include <iostream>
using namespace std;

//k[i,w] 물건 1~i까지만 고려하고, (임시) 배낭의 용량이 w일 때의 최대 가치
//i = 1,2,...n 이고 w = 1,2...c 이다.
//k[i,w] = max(k[i-1,w], k[i-1,w-w^i]+ i의 가치 v^i])

//**초기 k 배열의 설정**
//k 0 1 2 3 4..w
//0 0 0 0 0 0  //물건 아무것도 고려 안하니까 가치는 빵
//1 0
//2 0
//..0
//i 0 // 배낭 용량이 없으니까 빵

//가치와 무게 멤버변수를 포함하는 물건 클래스
class Stuff
{
	public:
	  int weight; //무게
	  int value; //가치 
	  Stuff(); //위임 생성자
	  Stuff(int weight,int value); //타겟 생성자
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
	int bagWeight = 0; //배낭 용량
	int stuffNum = 0; //물건 갯수

	cout << "배낭의 용량을 입력해주세요. : ";
	cin >> bagWeight;
	cout <<endl<< "물건의 갯수를 입력해주세요.: ";
	cin >> stuffNum;

	//가치를 담은 이차원 배열 k 생성
	int** arr;
	arr = new int*[stuffNum+1];
	for (int i = 0; i < stuffNum+1; i++)
	{
		arr[i] = new int[bagWeight + 1];
	}

	for (int i = 0; i < stuffNum + 1; i++)
	{
		arr[i][0] = 0; //0번째 열 초기화
	}

	for (int i = 0; i < bagWeight + 1; i++)
	{
		arr[0][i] = 0; //0번째 행 초기화
	}



	int weight = 0;
	int value = 0;
	Stuff *s = new Stuff[stuffNum+1]; //물건 배열 생성

	s[0].setStuff(0, 0); //첫번째는 없는 물건이 없으니까 0,0으로 초기화
	for (int i = 1; i < stuffNum+1; i++)
	{
		cout << endl << "물건 " << i << " 의 무게: ";
		cin >> weight;
		cout << "물건 " << i << " 의 가치: ";
		cin >> value;

		s[i].setStuff(weight, value);
	}

	for (int i = 1; i < stuffNum+1; i++)
	{
		for (int j = 1; j < bagWeight + 1; j++)
		{
		
			if (j >= s[i].weight)
			{
				arr[i][j] = max(arr[i - 1][j], arr[i-1][j - (s[i].weight)] + s[i].value); //그 이전까지의 물건을 고려한게 더 크냐? 빼고 새 물품을 넣은게 더 크냐? 
			}
			else
			{
				arr[i][j] = arr[i - 1][j];
			}
			
			
		}
	}

	cout << endl << "배낭 용량 ";
	for (int i = 0; i < bagWeight+1; i++)
	{
		cout << i << " ";
	}

	for (int i = 0; i < stuffNum + 1; i++)
	{
		
		cout << endl<< "물건 " << i << " 무게: " << s[i].weight << "가치 "<< s[i].value << " ";
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