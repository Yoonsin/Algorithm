#include <stdio.h>
#include <stdlib.h>

//qsort()�� ���Ǵ� �Լ�
int compare(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;
	return(*x-*y); 
	//*��������*
	//����� 1�� ��ȯ -> x�� �� ŭ
	//0�̸� 0�� ��ȯ -> x�� y�� ����
	//������ -1�� ��ȯ -> y�� �� ŭ
	//*��������*
	//�ݴ�� ���ָ� �� -> return (*y-*x) �̷���
}

int main(int argc,char* argv)
{
	int i = 0, j = 0;
	int array[10] = { 1,2,3,4,5,10,9,8,7,6 };
	
	qsort(array, 10, sizeof(int), compare); //������ �迭, �迭�� �� ���� ����, �迭 ������ ũ��, �񱳸� ������ �Լ� ������

	for (int i = 0; i < 10 ; i++)
	{
		printf("%d ", array[i]);
	}
	

	return 0;
}