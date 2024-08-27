#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// Graph class to represent the graph
class Graph
{
public:
    // Number of vertices
    int V;

    // Adjacency list to store the graph
    vector<vector<int>> adjList;

    // Constructor
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since the graph is undirected
    }

    // Function to display the graph
    void displayGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << ":";
            for (int j : adjList[i])
            {
                cout << " -> " << j;
            }
            cout << endl;
        }
    }
};

void bfs(Graph g)
{
    queue<int> q;
    cout << "Start from " << g.adjList[0][0] << endl;
    q.push(g.adjList[0][0]);
    vector<bool> isVisited(g.adjList.size(), false);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        isVisited[front] = true;
        cout << front << " ";
        for (int i = 0; i < g.adjList[front].size(); i++)
        {
            int element = g.adjList[front][i];
            if (!isVisited[element])
            {
                isVisited[element] = true;
                q.push(element);
            }
        }
    }
}

void dfs(vector<vector<int>> &adj, int node, vector<bool> &isVisited)
{
    isVisited[node] = true;
    cout << node << " ";
    for (auto i : adj[node])
    {
        if (!isVisited[i])
        {
            isVisited[i] = true;
            dfs(adj, i, isVisited);
        }
    }
}

int main()
{
    // Number of vertices in the graph
    int V = 5;

    // Create a graph with V vertices
    Graph graph(V);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Display the graph
    // graph.displayGraph();
    vector<bool> isVisited(graph.adjList.size(), false);
    dfs(graph.adjList, 1, isVisited);

    return 0;
}
