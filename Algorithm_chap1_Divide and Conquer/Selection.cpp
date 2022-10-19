#include <stdio.h>

int arr[10] = { 6, 3, 11, 9, 12, 2, 8, 15,4,10};

void QuickSort(int* arr, int start, int end, int k)
{
	if (start == end) //�����׷��� 1���ϰ��
	{
		printf("%d", arr[start]); //�׳� �װ� ����ϸ� ��
		//return;
		return;
	}

	int pivot = start;
	int i = start + 1;
	int j = end; //start�� end�� ����Ű�� ������ �ΰ�
	int temp = 0;

	while (i <= j) //���� ������ ������ �ݺ�
	{
		while (i <= end && arr[i] <= arr[pivot]) //���� ���� �ʰ�, �Ǻ������� �۰ų� ������
		{
			i++; //��� ������ �÷��ֱ�
		}

		while (j > start && arr[j] >= arr[pivot]) //������ �����ʰ�, �Ǻ������� ũ�ų� ������
		{
			j--; //��� ������ �÷��ֱ�
		}

		if (i > j) //���� ��������
		{
			temp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = temp; //�Ǻ��� �� ��ȯ..�ٵ� arr[j]���� �Ǻ��� ��ȯ����..?
		}
		else //�ƴϸ�
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; //i�� j ���� ����
		}
	}

	int s = j - start;


	if (k<=s)
	{
		QuickSort(arr, start, j - 1,k);
	}
	else if (k == s+1)
	{
		printf("%d", arr[j]);
		//return;
	
	}
	else
	{
		QuickSort(arr, j+1, end, k-(s+1));
	}



}


int main(void)
{
	int k = 8;
	printf("%d ��° ���� ", k);
	QuickSort(arr, 0, 9,k);

	
	


	return 0;
}