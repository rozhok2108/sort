#include <stdio.h>
#include <stdlib.h>

void sort_vstavka( int *arr, int *len )
{
    int i = 1, k;
    while(i <= *len)
    {
        for (k = i; k > 0; k-- )
        {
            if (arr[k] < arr[k-1] )
            {
                int tmp = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = tmp;
            }
        }
        i++;
    }
}

int main (void)
{
    int *arr = NULL;
    int n, len = 0, count = 0, number = 0, k = 1;
    char c;
    printf("введите числа: ");
    arr = (int*) malloc(sizeof(int));
    while (c != EOF)
    {
        scanf("%d", &number);
        arr[count] = number;
        count++;
        if ( count > k)
        {
          k *= 2;
          arr = (int *)realloc(arr, k * sizeof(int));
        } 
        c = getc(stdin);
    }
    count--;
    len = count - 1;
    sort_vstavka(arr, &len);
    printf("отсортированный массив: ");
    for(int j = 0; j <= len; j++)
        printf("%d ", arr[j]);
    return 0;
}