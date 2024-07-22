#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k)
{
    // int fromLeft = k;
    // int max_sum = 0;
    // while (fromLeft >= 0)
    // {
    // can pick fromLeft cards from left side
    //     int leftindex = 0;
    //     int leftcount = 0;
    //     int sum = 0;
    //     cout << "from left " << endl;
    //     while (leftcount < fromLeft)
    //     {
    //         // cout << "left count : " << leftcount << endl;
    //         cout << cardPoints[leftindex] << "  ";
    //         sum = sum + cardPoints[leftindex];
    //         leftindex++;
    //         leftcount++;
    //     }
    //     cout << endl;
    //     cout << "from right " << endl;

    //     int fromRight = k - fromLeft;
    //     int rightIndex = cardPoints.size() - 1;
    //     int rightCount = 0;
    //     int rightSum = 0;
    //     while (rightCount < fromRight)
    //     {
    //         cout << cardPoints[rightIndex] << "  ";
    //         rightSum += cardPoints[rightIndex];
    //         rightIndex--;
    //         rightCount++;
    //     }
    //     cout << endl;

    //     sum += rightSum;
    //     max_sum = max(sum, max_sum);
    //     fromLeft--;
    // }

    // ap 2
    int n = cardPoints.size();
    int leftsum = 0;
    int leftindex = 0;

    while (leftindex < k)
    {
        leftsum += cardPoints[leftindex];
        leftindex++;
    }
    // cout << leftindex << "  " << leftsum << endl;

    leftindex--;
    int rightIndex = n - 1;
    int rightSum = 0;
    int max_sum = leftsum;
    cout << (n - k) << endl;
    while (leftindex >= 0 && rightIndex >= (n - k))
    {
        cout << "left Index : " << leftindex << "  left sum :  " << leftsum << endl;
        cout << "right Index : " << rightIndex << "  right sum :  " << rightSum << endl;

        leftsum = leftsum - cardPoints[leftindex];
        rightSum = rightSum + cardPoints[rightIndex];
        int sum = leftsum + rightSum;
        max_sum = max(max_sum, sum);

        leftindex--;
        rightIndex--;
    }

    return max_sum;
}

int main()
{
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    cout << maxScore(cardPoints, 3);
    return 0;
}
