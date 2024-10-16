// gfg . count inversion
#include <bits/stdc++.h>

using namespace std;
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    int count = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            count += (mid - i + 1);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}

int mergesort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;

    int mid = (high + low) / 2;
    count += mergesort(arr, low, mid);
    count += mergesort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);
    return count;
}
int main()
{
    // your code goes here
    vector<int> arr = {2, 3, 4, 5, 6};
    cout << mergesort(arr, 0, 4);

    return 0;
}