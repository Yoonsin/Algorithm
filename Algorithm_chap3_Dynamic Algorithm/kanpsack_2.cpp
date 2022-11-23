#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STUFF_NUM 5 //���� ������ 5���� ����
#define MAX_BAG_NUM 20 //�賶 ���Դ� 20���� ����

//n���� ���ǰ� �� ���� i�� ���� wi�� ��ġ vi�� �־�����, �賶�� �뷮�� C�� �� �賶�� ���� �� �ִ� ������ �ִ� ��ġ��?
//��, �賶�� ���� ������ ������ ���� C�� �ʰ����� ���ƾ� �ϰ�, �� ������ 1������ �ִ�.

//�Է�: �賶�� �뷮 C�� n���� ���� //���: �뷮 C�� �� ���� �� �ִ� ������ �ִ밡ġ k[i,w] 

//k[i,w]�� �ִٰ� ����. w�� 0~C������ �賶 �����̰�, i�� 0~n������ �����̴�. k[i,w]�� �ִ� �뷮 w�� �����ʰ� 0~i�������� ������ ��� �־� ������ �ִ� ��ġ�̴�.
//k 0 1 2 3 4 .. C
//0 0 0 0 0 0 .. 0 ������ 0���� ��ġ�� 0
//1 0
//2 0
//..0
//n 0 �뷮�� 0�̸� ��ġ�� 0

//k[i,w] = max(k[i-1,w],k[i-1,w-w^i]+v^i] i-1������ ������ ���� ��ġ�� �� Ŀ�� �״�� �� ����, �ƴϸ� i ������ ���� ��ġ�� �� ū�� ���ϰ� ������ �ȴ�.


//���� ����ü
typedef struct Stuff {
	int weight; //����
	int value; //��ġ
}Stuff;

//�� dp���� ���� ���ǵ��� ���ÿ��θ� ��� ����ü 
typedef struct SelStuff {
	int sel[MAX_STUFF_NUM];
}SelStuff;

int max(int a, int b)
{
	if (a > b) return a;
	else if (a < b) return b;
	else if (a == b) return a;
	return b;
}

void kanpsack()
{
	srand(time(NULL)); //�����Լ� ������ ������  �Ź� �ٸ� �õ尪 �ֵ��� �ϱ�

	Stuff stuff[MAX_STUFF_NUM]; //5���� ���� ����ü ����
	for (int i = 0; i < MAX_STUFF_NUM; i++) //����, ��ġ �������� �ֱ�
	{
		stuff[i].weight = rand() % 9 + 1; //1~9����
		stuff[i].value = rand() % 9 + 1; //1~9���� 
	}

	int arr[MAX_STUFF_NUM + 1][MAX_BAG_NUM + 1]; // �뷮 C�� �� ���� �� �ִ� ������ �ִ밡ġ k[i,w]�迭. 0�� ����ؾ� �ؼ� �ε����� +1 ���ֱ�  
	SelStuff selStuff[MAX_STUFF_NUM + 1][MAX_BAG_NUM + 1];


	for (int i = 0; i < MAX_STUFF_NUM + 1; i++)
	{
		arr[i][0] = 0;
		for (int j = 0; j < MAX_STUFF_NUM; j++)
			selStuff[i][0].sel[j] = 0; //0�� ���õ��� ����. 1�� ���õ�.

	}

	for (int i = 0; i < MAX_BAG_NUM + 1; i++) //�� �� �ּ�ó�� ���� 0��, �뷮 0�� ���� ��ġ�� ���� 0���� �ʱ�ȭ ���ֱ�
	{
		arr[0][i] = 0;
		for (int j = 0; j < MAX_STUFF_NUM; j++)
			selStuff[0][i].sel[j] = 0; //0�� ���õ��� ����. 1�� ���õ�.
	}




	for (int i = 1; i < MAX_STUFF_NUM + 1; i++) {
		for (int j = 1; j < MAX_BAG_NUM + 1; j++) {
			if (j >= stuff[i - 1].weight) { //j�� ���� ���Ժ��� ũ�ų� ���� ����(�迭 �ε��� ������ ������ ��� ����)

				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - (stuff[i - 1].weight)] + stuff[i - 1].value); //stuff�� 0���� �����ϰ� i�� 1���� �����ؼ� stuff�� ��Ȯ�� �����Ϸ��� i-1�� �������
				if (arr[i][j] == arr[i - 1][j - (stuff[i - 1].weight)] + stuff[i - 1].value) { //i�� ���Ǳ��� ������ ��

					for (int k = 0; k < MAX_STUFF_NUM; k++) {
						selStuff[i][j].sel[k] = selStuff[i - 1][j - (stuff[i - 1].weight)].sel[k]; //������ ������ j-���� ���� �� ������ ���ǿ��ٰ�
					}

					selStuff[i][j].sel[i - 1] = 1;
				}
				else {
					for (int k = 0; k < MAX_STUFF_NUM; k++) {
						selStuff[i][j].sel[k] = selStuff[i - 1][j].sel[k]; //i-1���� ���Ǳ����� ������شٸ� ���õ� ���ǵ� i-1 ����� ����.
					}
				}
			}
			else {
				arr[i][j] = arr[i - 1][j];
				for (int k = 0; k < MAX_STUFF_NUM; k++)
					selStuff[i][j].sel[k] = selStuff[i - 1][j].sel[k]; //i-1���� ���Ǳ����� ������شٸ� ���õ� ���ǵ� i-1 ����� ����.
			}
		}
	}

	printf("�ִ� ��ġ�� %d�Դϴ�.\n", arr[MAX_STUFF_NUM][MAX_BAG_NUM]);
	printf("���õ� ������ ");
	for (int i = 0; i < MAX_STUFF_NUM; i++)
	{
		if (selStuff[MAX_STUFF_NUM][MAX_BAG_NUM].sel[i] == 1)
			printf("%d ", i + 1);


	}

	printf("�Դϴ�.");




}

int main(void)
{
	kanpsack();

	return 0;
}