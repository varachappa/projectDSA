#include <stdio.h>
double max(double arr[]);
double min(double arr[]);
int main()
{
    double arr[7];
    double num;
    printf("Enter data(float): ");
    for (int i = 0; i < 7; i++)
    {
        scanf("%lf", &num);
        arr[i] = num;
    }

    double highTemp = max(arr);
    double minTemp = min(arr);
    printf("The max temp recorded is : %f\n", highTemp);
    printf("The minimun temp recorded is : %f\n ", minTemp);
}
double max(double arr[])
{
    double max = arr[0];
    for (int i = 1; i < 7; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
double min(double arr[])
{
    double min = arr[0];
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}