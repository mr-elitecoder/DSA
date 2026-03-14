#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void bfs(
    unordered_map<int, vector<int>> &graph,
    int node,
    unordered_set<int> &visited)
{
    queue<int> q;
    q.push(node);
    visited.insert(node);

    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            for (int n : graph[curr])
            {
                if (!visited.count(n))
                {
                    q.push(n);
                    visited.insert(n);
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 3, 4}},
        {2, {0, 5}},
        {3, {1}},
        {4, {1, 5}},
        {5, {2, 4}}};

    unordered_set<int> visited;
    bfs(graph, 0, visited);

    return 0;
}
