#include <stdio.h>

void merge(int *a, int low, int mid, int hight) //����
{
	int b[6];
	int i = low; //���� ����
	int j = mid + 1; //������ ����
	int k = 0; //�迭 b�� �ε��� ��

	while (i <= mid && j <= hight)
	{
		if (a[i] <= a[j]) //�и��� ���� �迭�� ������ �迭 ��. ������ �迭 ��Ұ� �� ������
			b[k++] = a[i++]; //�װ� �ֱ�
		else
			b[k++] = a[j++];
	}

	while (i <= mid)
		b[k++] = a[i++]; //������ ���� ���� �迭�� �ִٸ� �迭 b�� ���� ä���
	while (j <= hight)
		b[k++] = a[j++]; //������ ���� ������ �迭�� �ִٸ� �迭 b�� ���� ä���

	k--; //k++ �����ϱ� 1�� �ٿ��ߵ�.

	while (k>=0) //�迭 b ������ �迭 a ���뿡 ���� ����
	{
		a[low + k] = b[k]; //..?? �̰� ������ low�� 0�� �ƴҼ��� �����ϱ� �̷��� ���Ű���?
		k--;
	}

}

void mergeSort(int* a, int low, int hight) //�迭�� ��Ҹ� �����ϴ� �Լ�
{
	int mid;
	if (low < hight) //���� ������ 2�� �̻��϶���
	{
		mid = (low + hight) / 2;
		mergeSort(a, low, mid);//���� �迭�� ��� �и�
		mergeSort(a, mid + 1, hight); //������ �迭�� ��� �и�
		merge(a, low, mid, hight); //�и��� �迭 ���� �� ���� �Լ�
	}
}

int main(void)
{
	int arr[6] = { 3,4,5,2,1,6 };

	mergeSort(arr, 0, 6 - 1);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
}