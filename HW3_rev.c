#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

struct NODE {
	struct NODE* next;
	char* buf;
};

int* arr_infor()
{
    char buffer[BUFFER_SIZE];
    int num_infor[2] = {0, 1};
    int* p_infor = num_infor;
    FILE *fp;
    fp = fopen("homework.txt","rt");
    while(!feof(fp)) {
        num_infor[0] = fread(buffer, sizeof(char), sizeof(buffer), fp);
        for (int i = 0; i < num_infor[0]; i++) {
            if (buffer[i] == '\n') {
                num_infor[1] = num_infor[1] + 1;
            }
        }    
    }
    printf("%d\n %d\n", num_infor[0], num_infor[1]);
    return p_infor;
}

char** make_arr(int p_infor[])
{
    char** p_array = (char**)calloc(p_infor[1],sizeof(char*));
    for (int i = 0; i < p_infor[1]; i++) {
        p_array[i] = (char*)malloc(BUFFER_SIZE);
    }
    return p_array;
}

char** input_arr(char** p_array, int* p_infor)
{
    FILE *fp;
    fp = fopen("homework.txt","rt");
    while(!feof(fp)) {
        for (int i = 0; i < p_infor[0]; i++) {
            fgets(p_array[i], BUFFER_SIZE, fp);
        }
    }
    fclose(fp);
	return p_array;
}

struct NODE* init_list()
{
	struct NODE* head = malloc(sizeof(struct NODE));
	head -> next = NULL;
	return head;
}

void add_node(struct NODE *old, char* buf)
{
	struct NODE* new = malloc(sizeof(struct NODE));
	new -> next = old -> next;
	new -> buf = buf;
	old -> next = new;
}

void input_node(struct NODE* head, char** p_array, int* p_infor)
{
	for(int i = 0; i < p_infor[1]; i++) {
		add_node(head, p_array[i]);
	}
}

void print_node(struct NODE* head)
{
	struct NODE* curr = head -> next;
 	while(curr != NULL) {
		printf("%s", curr -> buf);
		curr = curr -> next;
	}
}

void main()
{
    int* arr_inf = arr_infor();
    char** array = make_arr(arr_inf);
    input_arr(array, arr_inf);
    struct NODE* head = init_list();
	input_node(head, array, arr_inf);
	print_node(head);
}