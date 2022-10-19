#include <stdio.h>

int data[10] = { 4,1,2,3,9,7,8,6,10,5 };

void QuickSort(int* data, int start, int end)
{
	if (start >= end) //���Ұ� 1���� ���
	{
		return;
	}
		

	int pivot = start;
	int i = pivot + 1; //���� ��� ����
	int j = end; //������ ��� ����
	int temp;

	//�����Ͱ� ������ ������ �ݺ�
	while (i <= j)
	{
		while (i <= end && data[i] <= data[pivot])
		{
			i++;
		}

		while (j > start && data[j] >= data[pivot])
		{
			j--;
		}

		if (i > j) //������. but i�� j�� ���� ������ ��¼�ڰ�.....?????????? ���� ������ �ݵ�� ������ �۰ų� Ŀ��. �״����� �������� �������� �ƴұ�?
		{
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else
		{
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	QuickSort(data, start, j - 1);
	QuickSort(data, j + 1, end);
	
}

int main(void)
{
	QuickSort(data, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", data[i]);
	}

	return 0;
}