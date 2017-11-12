/*
ID: arnavga1
TASK: hamming
LANG: C++
*/

#include<cstdio>
#include<vector>

using namespace std;

int n, b, d;

int ham(int n1, int n2)
{
    int ham = 0;
    for (int i = 0; i < b; i++)
        if (((n1 >> i) & 1) != ((n2 >> i) & 1))
            ham++;
    return ham;
}

int main()
{
    FILE* in = fopen("hamming.in", "r");
    fscanf(in, "%d %d %d", &n, &b, &d);
    fclose(in);

    vector<int> nums;
    nums.push_back(0);

    for (int i = 1; nums.size() < n; i++) {
        bool isHam = true;
        for (int j = 0; j < nums.size(); j++)
            if (ham(nums[j], i) < d) {
                isHam = false;
                break;
            }
        if (isHam)
            nums.push_back(i);
    }

    FILE* out = fopen("hamming.out", "w");
    for (int i = 0; i < n; i++)
        if (i % 10 == 0)
            if (i == 0)
                fprintf(out, "%d", nums[i]);
            else
               fprintf(out, "\n%d", nums[i]);
        else
            fprintf(out, " %d", nums[i]);
    fprintf(out, "\n");
    fclose(out);
}
