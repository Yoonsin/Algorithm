#include <stdio.h>
#include <stdlib.h>

//qsort()에 사용되는 함수
int compare(const void* a, const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;
	return(*x-*y); 
	//*오름차순*
	//양수면 1을 반환 -> x가 더 큼
	//0이면 0을 반환 -> x랑 y가 같음
	//음수면 -1을 반환 -> y가 더 큼
	//*내림차순*
	//반대로 해주면 됨 -> return (*y-*x) 이렇게
}

int main(int argc,char* argv)
{
	int i = 0, j = 0;
	int array[10] = { 1,2,3,4,5,10,9,8,7,6 };
	
	qsort(array, 10, sizeof(int), compare); //정렬할 배열, 배열의 총 원소 갯수, 배열 원소의 크기, 비교를 수행할 함수 포인터

	for (int i = 0; i < 10 ; i++)
	{
		printf("%d ", array[i]);
	}
	

	return 0;
}