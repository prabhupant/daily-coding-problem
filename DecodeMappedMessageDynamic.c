#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int decoder(char* digits, int n)
{
    int count[n+1];
    count[0] = 1;
    count[1] = 1;
    int i;

    for(i = 2; i <= n; i++)
    {
        if(digits[i-1] > '0')
        {
            count[i] = count[i-1];
        }
        if(digits[i-2] == '1' || digits[i-2] == '2' && digits[i-1] < '7')
        {
            count[i] += count[i-2];
        }
    }
    return count[n];
}


int main()
{
    char digits[] = "111";
    int n = strlen(digits);
    printf("Number of ways are: %d", decoder(digits, n));
    return 0;
}
