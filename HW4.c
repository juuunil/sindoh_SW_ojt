/* exercise - 문자열 Bubble sorting */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

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
    fp = fopen("homework.1.txt","rt");
    while(!feof(fp)) {
        for (int i = 0; i < p_infor[0]; i++) {
            fgets(p_array[i], BUFFER_SIZE, fp);
        }
    }
    fclose(fp);
    return p_array;
}

char** bubble_sort(char** p_array, int* p_infor)
{
	char *tmp;
	for (int i = 0; i < p_infor[1]-1; i++) {
        for (int j = i+1; j < p_infor[1]; j++) {
            if (strcmp(p_array[i], p_array[j]) > 0) {
                tmp = p_array[i];
                p_array[i] = p_array[j];
                p_array[j] = tmp;
            }
        }
    }
	return p_array;
}

void print_arr(char** p_array, int* p_infor)
{
    for (int i = 0; i < p_infor[1]; i++) {
        printf("%s", p_array[i]);
    }
    printf("\n");
}

int main()
{
    int* arr_inf = arr_infor();
    char** array = make_arr(arr_inf);
    input_arr(array, arr_inf);
    bubble_sort(array, arr_inf);
    print_arr(array, arr_inf);
}