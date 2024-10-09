// Longest Sub-Array with Sum K from GFG
#include <bits/stdc++.h>

using namespace std;
int lenOfLongSubarr(int A[], int N, int K)
{
    int max_len = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += A[j];
            if (sum == K)
            {
                max_len = max(j - 1 + 1, max_len);
            }
        }
    }
    return max_len;
}
int main()
{
    int A[3] = {-1, 2, 3};
    cout << lenOfLongSubarr(A, 3, 6);
    return 0;
}