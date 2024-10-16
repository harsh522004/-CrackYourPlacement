#include <bits/stdc++.h>

using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;

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
}

int countFunction(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int rightPointer = mid + 1;
    for (int i = low; i <= mid; i++)
    {

        // for each element in left,we itrate right array
        while (rightPointer <= high && arr[i] > 2 * arr[rightPointer])
        {
            rightPointer++;
            count++;
        }
        // count += (rightPointer - (mid + 1));
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
    count += countFunction(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}
int team(vector<int> &skill, int n)
{
    return mergesort(skill, 0, n - 1);
}
int main()
{
    // your code goes here
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}