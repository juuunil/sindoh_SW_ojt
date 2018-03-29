#include <stdio.h>

int main()
{
	int array[3][3];
	int i,j;
	int tmp[3];	

	printf("배열에 추가하고자 하는 9가지 수를 입력하세요\n");
	
	for (i = 0; i < 3; i++) {
		for (j =0; j<3; j++) {
			scanf("%d", &array[i][j]);
		}
	}
	
	printf("\n입력한 수의 배열은 다음과 같습니다\n");
	
	for (i = 0; i < 3; i++)	{
		for (j = 0; j < 3; j++)	{
			printf("%d\t",array[i][j]);
		}
		printf("\n");		
	}
	
	for (j = 0; j < 3; j++)	{
		tmp[j] = array[2][j];
		array[2][j] = array[1][j];
		array[1][j] = array[0][j];
		array[0][j] = tmp[j];
	}
	
	printf("\n입력한 배열의 순서를 변경하면 다음과 같습니다\n");

	for (i = 0; i < 3; i++)	{
		for (j = 0; j < 3; j++)	{
			printf("%d\t",array[i][j]);
		}
		printf("\n");		
	}
}
