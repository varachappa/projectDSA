#include <stdio.h>
int arr[] = {34, 78, 54, 21, 89};
int main()
{
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%d\n", arr[2]);
    printf("%d\n", 2 [arr]);
    printf("%p\n", arr + 2);
    printf("%d\n", *(arr + 2));
    printf("%d\n", *(2 + arr));
    printf("%d\n", *arr + 2);
    printf("%d\n", arr[-1]);
    int *p = arr;
    printf("%d\n", p[2]);
    printf("%d\n", 2 [p]);
    printf("%d\n", *(p + 2));
    printf("%d\n", *(2 + p));
    p = &arr[3];
    printf("%d\n", p[-1]);
}