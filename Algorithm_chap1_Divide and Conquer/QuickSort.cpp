#include <stdio.h>
#define MAX 3 //�迭�� ���� ���� �̸� ����

int arr[MAX]; //������ �迭 ����


void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return; //���� left�� right���� ũ�ų� ������ ���̻� ���ʿ� ����. Ż��. 
	}

	int temp = 0; //�ٲܶ� �ʿ��� �ӽð� ����
	int pivot = left + right / 2; //�Ǻ��� �ε����� �߾Ӱ����� ����
	int l = left; int r = right; //left�� right�� ���� �� �ٲ��� �� ����ؾ� �ϴ� �̸� arr�� �� �����̶� ������ �ε��� �����ϱ�

	temp = arr[pivot];
	arr[pivot] = arr[left];
	arr[left] = temp; //�Ǻ��̶� �� ���ʰ� �ٲٱ�

	pivot = left;  //�ϴ� �Ǻ��� �� ���ʿ� ����
	left++; //���� �ε��� ��ĭ �ø���

	// �Ǻ� ����           ������  <- arr�� ���� �ε��� ����

	int leftFlag = 0, rightFlag = 0; //����/�����ʿ��� �Ǻ��� ���ؼ� �� �۰ų�/ũ�� �ٲ���·� ǥ������(�ٲ��� �ʰ� �ε����� �������� �Ѿ�� �ȵǴϱ�!!)


	while (1) //���ʰ� ������ �ε����� ��ĭ�� ���� �߾����� �;ߵ�
	{


		if (!leftFlag && arr[left] > arr[pivot]) //���� ������ �ٲ���°� �ƴϰ�, ���� ���� �Ǻ����� ũ�ٸ�
		{
			leftFlag = 1; //�ٲ���·� �ٲ���
		}
		else if (!leftFlag) //�׳� �ٲ���°� �ƴ϶��
		{
			left++; //�ε��� ��ĭ �ø���
		}
		//�ٲ� ���¶�� �ε��� �ø��� ���� �׳� ���α�


		if (!rightFlag && arr[right] < arr[pivot]) //���� �������� �ٲ���°� �ƴϰ�, ������ ���� �Ǻ����� �۴ٸ�
		{
			rightFlag = 1; //�ٲ���·� �ٲ���
		}
		else if (!rightFlag) //�׳� �ٲ���°� �ƴ϶��
		{
			right--; //�ε��� ��ĭ �ø���

		}
		//�ٲ� ���¶�� �ε��� �ø��� ���� �׳� ���α�


		if (leftFlag && rightFlag) //�Ѵ� �ٲ� ���¶�� ���� �ٲٱ�
		{
			temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;

			leftFlag = 0; rightFlag = 0; //�ٲ����� �ٽ� false�� ��ȯ
		}

		if (left + 1 == right) //���� ���� �ٷ� ���� �پ��ִٸ�
		{
			break; //Ż�� 
		}

	}

	temp = arr[left];
	arr[left] = arr[pivot];
	arr[pivot] = temp; //�Ǻ����̶� left���� ��ȯ

	pivot = left; // �ε����� �Űܰ���

	QuickSort(arr, l, pivot - 1);
	QuickSort(arr, pivot + 1, r);

}


int main(void)
{


	for (int i = 0; i < MAX; i++)
	{
		scanf_s("%d", &arr[i]); //�� �־��ֱ�
	}

	QuickSort(arr, 0, MAX - 1); //�� ���� �Լ� ȣ�� 

	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]); //�� ���
	}


	return 0;
}