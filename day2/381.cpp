#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

class RandomizedCollection
{
public:
    vector<int> array;                          // to store the elements
    unordered_map<int, unordered_set<int>> map; // to store element indices

    RandomizedCollection()
    {
        // No need to explicitly initialize vector and map, they are initialized by default
    }

    bool insert(int val)
    {
        array.push_back(val);
        map[val].insert(array.size() - 1); // add index to the map
        return map[val].size() == 1;       // return true if it's the first occurrence
    }

    bool remove(int val)
    {
        if (map.find(val) == map.end() || map[val].empty())
        {
            return false; // value not present
        }

        int removeIdx = *map[val].begin(); // get an index of the value to remove
        int lastIdx = array.size() - 1;
        int lastVal = array[lastIdx];

        if (val == array[lastIdx])
        {
            removeIdx = array.size() - 1;
            array.pop_back();
            map[val].erase(removeIdx);
        }
        else
        {
            // Swap the last element with the element to be removed
            array[removeIdx] = lastVal;
            map[lastVal].insert(removeIdx);
            map[lastVal].erase(lastIdx);

            // Remove the last element
            array.pop_back();
            map[val].erase(removeIdx);
        }

        if (map[val].empty())
        {
            map.erase(val);
        }

        return true;
    }

    int getRandom()
    {
        int randomIndex = rand() % array.size();
        return array[randomIndex];
    }

    void printState()
    {
        // Print array state
        cout << "Array: ";
        for (int num : array)
        {
            cout << num << " ";
        }
        cout << endl;

        // Print map state
        cout << "Map: " << endl;
        for (const auto &entry : map)
        {
            cout << entry.first << ": ";
            for (int idx : entry.second)
            {
                cout << idx << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Testing
    vector<string> commands = {"RandomizedCollection", "insert", "insert", "insert", "insert", "insert", "insert", "remove", "remove", "remove", "remove", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"};
    vector<vector<int>> inputs = {{}, {1}, {1}, {2}, {1}, {2}, {2}, {1}, {2}, {2}, {2}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    vector<string> expected = {"null", "true", "false", "true", "false", "false", "false", "true", "true", "true", "true", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"};

    RandomizedCollection *obj = new RandomizedCollection();
    vector<string> result;

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "RandomizedCollection")
        {
            result.push_back("null");
        }
        else if (commands[i] == "insert")
        {
            result.push_back(obj->insert(inputs[i][0]) ? "true" : "false");
        }
        else if (commands[i] == "remove")
        {
            result.push_back(obj->remove(inputs[i][0]) ? "true" : "false");
        }
        else if (commands[i] == "getRandom")
        {
            result.push_back(to_string(obj->getRandom()));
        }

        cout << "After " << commands[i] << "(" << (inputs[i].empty() ? "" : to_string(inputs[i][0])) << "):" << endl;
        obj->printState();
        cout << endl;
    }

    // Print results
    for (const auto &res : result)
    {
        cout << res << " ";
    }
    cout << endl;
}