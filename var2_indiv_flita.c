#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int *array, int *num, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    int j;
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot) 
        {
            i++;
            swap(&array[i], &array[j]);
            swap(&num[i], &num[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    swap(&num[i + 1], &num[high]);
    return (i + 1);
}

void quickSort(int *array, int *num, int low, int high)
{
    if (low < high) 
    {
        int pi = partition(array, num, low, high);
        quickSort(array, num, low, pi - 1);
        quickSort(array, num, pi + 1, high);
    }
}

int main()
{
    FILE *matr;
    matr = fopen("matr.txt", "r");
    int i = 0, n = 0, sum = 0, k = 0;
    char s, c;
    while( (s = fgetc(matr)) != EOF)
    {
        if(s=='\n'){
             n++;  //количество вершин
        }
    }
    int *str = (int*) malloc(sizeof(int*) * n);
    int *str2 = (int*) malloc(sizeof(int*) * n);
    fseek (matr, 0 , SEEK_SET);
    while( (c = fgetc(matr)) != EOF)
    {
        if (c == '\n')
        {
            str[i] = i;
            str2[i] = sum;
            printf("%d -> %d\n", i, str2[i]);
            sum = 0;
            i++;
        }
        if ( c == '1')
        {
             sum++;
        }
    }
    quickSort(str2, str, 0, n-1);
    for( k = 0 ;  k < n ; k++)
    {
        printf("%d ", str[k]);
    }
    fclose(matr);
    free(str);
    free(str2);
    return 0;
}