#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** make_arr();
char** input_arr(char** parray);
void print_arr(char** parray);

struct NODE {
	struct NODE *next;
	char data[100];
};

void add_node(struct NODE *target, char data[100])
{
    struct NODE *new_node = malloc(sizeof(struct NODE));
    new_node->next = target->next;
    new_node->data[100] = data[100];
    target->next = new_node;
}

char** make_arr()
{
	char **parray = (char**)calloc(3, sizeof(char));
	for (int i = 0; i < 3; i++) {
		parray[i] = (char*)calloc(50, sizeof(char));
	}
	return parray;
}

char** input_arr(char** parray)
{
	FILE *fp;
	fp = fopen("HW3.txt","rt");
	struct NODE *head = malloc(sizeof(struct NODE));
	for (int i = 0; i < 3; i++) {
		add_node(head, fgets(parray[i],50,fp));
	}
	fclose(fp);
	return parray;
}

void print_arr(char** parray)
{
	for (int i = 0; i < 3; i++) {
			printf("%s", parray[i]);
	}
	printf("\n");
}

int main()
{
	char **array = make_arr();
	input_arr(array);
	print_arr(array);
}