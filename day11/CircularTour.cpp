#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
// approach 1
bool isTour(vector<pair<int, int>> &petrolPump, int currentPetrol, int startIndex, int currentIndex, bool isFirst)
{
    cout << "Checking tour from start index " << startIndex << " at current index " << currentIndex << endl;

    if (isFirst == false && currentIndex == startIndex && currentPetrol >= 0)
    {
        cout << "Tour completed successfully from start index " << startIndex << endl;
        return true;
    }

    isFirst = false;

    // add petrol
    currentPetrol += petrolPump[currentIndex].first;
    cout << "At petrol pump " << currentIndex << ", added petrol: " << petrolPump[currentIndex].first
         << ", current petrol: " << currentPetrol << endl;

    int nextDistance = petrolPump[currentIndex].second;

    // check if petrol is sufficient or not
    if (currentPetrol >= nextDistance)
    {
        // you can go
        // remove petrol
        currentPetrol -= nextDistance;
        cout << "Traveling to next petrol pump, distance: " << nextDistance
             << ", remaining petrol: " << currentPetrol << endl;

        int nextIndex = (currentIndex >= petrolPump.size() - 1) ? 0 : currentIndex + 1;
        bool ans = isTour(petrolPump, currentPetrol, startIndex, nextIndex, isFirst);
        return ans;
    }

    cout << "Not enough petrol to travel to next petrol pump, distance: " << nextDistance
         << ", remaining petrol: " << currentPetrol << endl;

    return false;
}

int tour(vector<pair<int, int>> &petrolPump)
{
    int ansIndex = -1;
    // Your code here
    for (int i = 0; i < petrolPump.size(); i++)
    {
        cout << "\n\n\n\n";
        cout << "Trying start index " << i << endl;
        bool ans = isTour(petrolPump, 0, i, i, true);
        if (ans)
        {
            ansIndex = i;
            break;
        }
    }
    return ansIndex;
}

// app 2

// int tour(petrolPump p[])
// {
//     // queue<petrolPump> q;
//     int front = 0;
//     int rear = 0;
//     int currentPetrol = 0;
//     int start = 0;

//     do
//     {
//         int nextDistance = p[rear].distance;
//         currentPetrol = currentPetrol + p[rear].petrol;
//         if (currentPetrol >= nextDistance)
//         {
//             currentPetrol = currentPetrol - p[rear].distance;
//             // good to go
//             rear++;
//         }
//         else
//         {
//             front = rear + 1;
//             rear = front;

//             start = front;
//             currentPetrol = 0;
//         }
//     } while (front != rear);

//     if (currentPetrol >= 0)
//     {
//         return start;
//     }
//     return -1;
// }

int main()
{
    vector<pair<int, int>> petrolPump = {{3, 2}, {4, 3}, {5, 4}, {1, 5}, {2, 1}};
    int result = tour(petrolPump);
    cout << "Starting index for the tour: " << result << endl;
    return 0;
}
