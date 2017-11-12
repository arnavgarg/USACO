/*
ID: arnavga1
TASK: preface
LANG: C++11
 */

#include <cstdio>
#include<cmath>

int sums[7];

/*
 * Mag 0
 * 0 - I:1
 * 1 - V:5
 * Mag 1
 * 2 - X:10
 * 3 - L:50
 * Mag 2
 * 4 - C:100
 * 5 - D:500
 * Mag 3
 * 6 - M:1000
 */
void addRoman(int n, int m)
{
    printf("%d %d\n", n, m);
    switch (n) {
        case 1:
            sums[2*m]++;
            break;
        case 2:
            sums[2*m] += 2;
            break;
        case 3:
            sums[2*m] += 3;
            break;
        case 4:
            sums[2*m]++;
            sums[2*m+1]++;
            break;
        case 5:
            sums[2*m+1]++;
            break;
        case 6:
            sums[2*m]++;
            sums[2*m+1]++;
            break;
        case 7:
            sums[2*m] += 2;
            sums[2*m+1]++;
            break;
        case 8:
            sums[2*m] += 3;
            sums[2*m+1]++;
            break;
        case 9:
            sums[2*m]++;
            sums[2*m+2]++;
            break;
    }
}

int main()
{
    int n;

    FILE* in = fopen("preface.in", "r");
    fscanf(in, "%d", &n);
    fclose(in);
    for (int i = 1; i <= n; i++) {
        int j = 0, num = i;
        while (num > 0) {
            num /= 10;
            j++;
        }
        num = i;
        for (; j > 0; j--) {
            addRoman(num/pow(10,j-1), j-1);
            num = num % (int)pow(10,j-1);
        }
    }

    FILE* out = fopen("preface.out", "w");
    char chars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for (int i = 0; i < 7; i++)
        if (sums[i] != 0)
            fprintf(out, "%c %d\n", chars[i], sums[i]);
    fclose(out);
}
