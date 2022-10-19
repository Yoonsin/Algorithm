#include <stdio.h>

int arr[10] = { 4,7,3,8,9,2,1,2,5,10 };

void QuickSort(int* arr, int start, int end)
{
	if (start >= end) //���Ұ� 1���ΰ��
	{
		return;
	}

	int pivot = start;
	int i = start+1;
	int j = end; //start�� end�� ����Ű�� ������ �ΰ�
	int temp = 0;

	while (i <= j) //���� ������ ������ �ݺ�
	{
		while (i<=end && arr[i] <= arr[pivot]) //���� ���� �ʰ�, �Ǻ������� �۰ų� ������
		{
			i++; //��� ������ �÷��ֱ�
		}

		while (j>start && arr[j] >= arr[pivot]) //������ �����ʰ�, �Ǻ������� ũ�ų� ������
		{
			j--; //��� ������ �÷��ֱ�
		}

		if (i>j) //���� ��������
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

	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);
}


int main(void)
{
	QuickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	

	return 0;
}