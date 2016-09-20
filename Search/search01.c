#include <stdio.h>

int binary_search(int *a, int length, int target)
{
    int left = 0;
    int right = length - 1;
    int middle = 0;
    while (left <= right)
    {
        middle = (left + right) >> 1;
        if (a[middle] > target)
        {
            right = middle - 1;
        }
        else if (a[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

int main()
{
    int a[5] = {2, 3, 4, 8, 10};
    int i = binary_search(a, 5, 8);
    printf("%d\n", i);
    return 0;
}
