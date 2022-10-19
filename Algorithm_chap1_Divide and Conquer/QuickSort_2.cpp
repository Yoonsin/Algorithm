#include <stdio.h>

int data[10] = { 4,1,2,3,9,7,8,6,10,5 };

void QuickSort(int* data, int start, int end)
{
	if (start >= end) //원소가 1개인 경우
	{
		return;
	}
		

	int pivot = start;
	int i = pivot + 1; //왼쪽 출발 지점
	int j = end; //오른쪽 출발 지점
	int temp;

	//포인터가 엇갈릴 때까지 반복
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

		if (i > j) //엇갈림. but i와 j가 서로 같으면 어쩌자고.....?????????? 서로 같으면 반드시 한쪽이 작거나 커짐. 그다음에 엇갈려서 괜찮은거 아닐까?
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