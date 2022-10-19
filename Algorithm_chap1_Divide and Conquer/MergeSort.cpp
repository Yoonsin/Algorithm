#include <stdio.h>

int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };


void Merge(int *arr,int start,int mid,int end) //�պ�
{
	int b[11];
	int k = 0; //b�� �ε��� ����

	int i = start; //���� ���� 
	int j = mid + 1; //������ ����
	


	while (i <= mid && j <= end) //i�� mid����
	{
		if (arr[i] <= arr[j]) //���� �迭 ��Ұ� �� ������
		{
			b[k++] = arr[i++];
		}
		else //������ �迭 ��Ұ� �� ������
		{
			b[k++] = arr[j++];
		}
	}

	while (i <= mid)
		b[k++] = arr[i++]; //������ ���� ���� �迭�� �ִٸ� �迭 b�� ���� ä���

	while (j <= end)
		b[k++] = arr[j++]; //������ ���� ������ �迭�� �ִٸ� �迭 b�� ���� ä���

	k--; //�������� k++�Ǵϱ� -1��ߵ�

	while (k>=0)
	{
		arr[start + k] = b[k]; //..?? �̰� ������ low�� 0�� �ƴҼ��� �����ϱ� �̷��� ���Ű���?
		k--;
	}
}


void MergeSort(int *arr,int start,int end) //����
{
	int mid;
	
	if (start < end) //������ 2���̻� ���̳����� ���ǹ� ���� ���� ����
	{
		mid = (start + end) / 2; //�� mid�� mergesort�� ���� �ʰ� �׳� ���⼭ �����ұ�?*/
		MergeSort(arr, start,mid);
		MergeSort(arr,mid+1,end );
		Merge(arr, start, mid, end);
	}

}

int main(void)
{
	MergeSort(arr, 0,9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}