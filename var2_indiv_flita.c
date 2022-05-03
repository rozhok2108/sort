#include <stdio.h>
#include <stdlib.h>

void qs(int *s_arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(s_arr, first, right);
        qs(s_arr, left, last);
    }
}

int main()
{
    FILE *matr;
    matr = fopen("matr.txt", "r");
    int  a = 0, i = 0, n = 0, sum = 0, k = 0, j, h;
    char s, c;
    while((fscanf(matr, "%c", &s)) == 1)
    {
        if(s=='\n'){
             n++;  //количество вершин
        }
    }
    
    int *str = (int*) malloc(sizeof(int*) * n);
    int *str2 = (int*) malloc(sizeof(int*) * n);
    fseek (matr, 0 , SEEK_SET);
    while(fscanf(matr, "%c", &c) == 1)
    {
        if (c == '\n')
        {
            str[i] = sum;
            str2[i] = sum;
            sum = 0;
            i++;
        }
        if ( c == '1')
        {
             sum++;
        }
    }
    qs(str2, 0, n-1);
    for( k = 0 ;  k < n ; k++)
    {
        printf("Номер вершины: %d, степень: %d\n ", k, str[k]);
    }
    printf("Отсортированный порядок вершин: ");
    for( h = 0;  h < n; h++)
    {
        for(j = 0 ; j < n ; j++)
        {
            if ( str2[h] == str[j])
            {
                printf("%d ", j);
                str[k] = '\0';
                break;
            }
        }
    }
    fclose(matr);
    free(str);
    free(str2);
    return 0;
}