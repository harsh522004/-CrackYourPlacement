#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> firstPreviousSmaller(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s;

    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            result[i] = s.top();
        }
        s.push(i);
    }

    return result;
}

vector<int> firstNextSmaller(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result with -1
    stack<int> s;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            result[i] = s.top();
        }
        s.push(i);
    }

    return result;
}
int largestRectangleArea(vector<int> &heights)
{
    vector<int> leftArr = firstPreviousSmaller(heights);
    vector<int> rightArr = firstNextSmaller(heights);

    int max_area = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        int currentHeight = heights[i];

        if (currentHeight > 0)
        {
            int leftIndex = leftArr[i];
            int rightIndex = rightArr[i];

            leftIndex++;
            if (rightIndex == -1)
            {
                rightIndex = heights.size();
            }
            rightIndex--;
            cout << "current Height : " << currentHeight << endl;

            cout << "Left Index : " << leftIndex << endl;
            cout << "Right Inex  : " << rightIndex << endl;

            cout << endl;

            int width = rightIndex - leftIndex + 1;
            int area = currentHeight * width;
            max_area = max(max_area, area);
        }
    }

    return max_area;
}

int main()
{
    vector<int> heights = {2, 1, 2};
    int ans = largestRectangleArea(heights);
    cout << "Largest rectangle area: " << ans << endl;
    return 0;
}
