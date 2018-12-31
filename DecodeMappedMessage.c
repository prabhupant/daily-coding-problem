#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int countDecoding(char* digits, int n)
{
    if(n == 0 || n == 1)
        return 1;

    int count;
    count = 0;

    if(digits[n-1] > '0')
    {
        count = countDecoding(digits, n-1);
    }

    if(digits[n-2] == '1' || (digits[n-2] == '2' && digits[n-1] < '7'))
    {
        count += countDecoding(digits, n-2);
    }

    return count;
}

int main()
{
    char digits[] = "001";
    int n = strlen(digits);
    printf("Number of ways to decode this message is %d", countDecoding(digits, n));
    return 0;
}

