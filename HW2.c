#include <stdio.h>
#include <stdlib.h>


int **makearr();
void print_arr(int ** p);
int **swap_arr(int ** p);

int main()
{
	int **array = makearr();
	print_arr(array);
	swap_arr(array);
	print_arr(array);	

	return 0;
}

int **makearr()
{
	int **p = (int**) calloc(3, sizeof(int*));
	int	i;
//	int state;
	FILE *fp;	

	for (i = 0; i < 3; i++) {
		p[i] = (int*) calloc(3, sizeof(int));
	}

	fp = fopen("num.txt","rt");
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 3; j++) {
				p[i][j] = fgetc(fp)-'0';
				}
			}			
	fclose(fp);	
	return p;
}

void print_arr(int ** p)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t", p[i][j]);
		}
		printf("\n");
	}
}

int **swap_arr(int ** p)
{
	int *tmp;
	
	tmp = p[0];
	p[0] = p[1];
	p[1] = p[2];
	p[2] = tmp;

	return p;
}
