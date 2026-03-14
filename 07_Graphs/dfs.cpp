#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

static int call = 1;
void dfs(
    unordered_map<int, vector<int>> &graph,
    int node,
    unordered_set<int> &visited)
{
    cout << "| Called : " << node << "\n\n";
    if (!visited.count(node))
    {
        visited.insert(node);
        cout << "  " << node << " Traversed \n";
        for (int n : graph[node])
        {
            dfs(graph, n, visited);
            cout << "\n  Backtrack to " << node << " <--\n\n";
        }
    }
    else
        cout << "  " << node << " Already Visited !\n";
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
    dfs(graph, 0, visited);
    return 0;
}
