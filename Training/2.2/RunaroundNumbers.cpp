/*
ID: arnavga1
TASK: runround
LANG: C++11
 */

#include <cstdio>
#include <cmath>

bool isRound(int a)
{
    bool used[9] = {false};
    int n = a, digits = 0;
    while (n > 0) {
        n /= 10;
        digits++;
    }

    int num[digits];
    for (int j = digits; j > 0; j--) {
        int digit = a/pow(10,j-1);
        if (used[digit-1])
            return false;
        used[digit-1] = true;
        if (digit == 0)
            return false;
        num[digits-j] = digit;
        a = a % (int)pow(10,j-1);
    }

    bool reached[digits];
    for (int i = 0; i < digits; i++)
        reached[i] = false;
    int curr = 0;
    for (int i = 0; i < digits; i++) {
        if (reached[curr])
            return false;
        reached[curr] = true;
        curr = (num[curr]+curr) % digits;
    }
    if (curr != 0)
        return false;
    return true;
}

int main()
{
    int m;
    FILE* in = fopen("runround.in", "r");
    fscanf(in, "%d\n", &m);
    fclose(in);

    int i = m+1;
    while (!isRound(i))
        i++;

    FILE* out = fopen("runround.out", "w");
    fprintf(out, "%d\n", i);
    fclose(out);
}
