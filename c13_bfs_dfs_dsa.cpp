#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define MAX 10
using namespace std;

int v;
int e;
int adj_mat[MAX][MAX];
vector<vector<int>> adj_list ;

void dfs(int mat[MAX][MAX])
{
    bool visited[MAX] = {false};
    int i = 0;
    stack<int> s;
    s.push(i);
    while (!s.empty())
    {
        int t = s.top();
        if (visited[t] == false)
        {
            cout << t << " ";
        }
        visited[t] = true;
        bool flag = false;
        for (i = 0; i < v; i++)
        {
            if (mat[t][i] == 1 && visited[i] == false)
            {
                s.push(i);
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            s.pop();
        }
    }
}

void bfs()
{
    bool visited[MAX] = {false};
    queue<int> temp;
    temp.push(0);
    visited[0] = true;
    while (!temp.empty())
    {
        int t = temp.front();
        cout << t << " ";
        temp.pop();

        for (int i = 0; i < adj_list[t].size(); i++)
        {
            if (visited[adj_list[t][i]] == false)
            {
                visited[adj_list[t][i]] = true;
                temp.push(adj_list[t][i]);
            }
        }
    }
}

int main()
{
    cout << "Enter number of vertices:";
    cin >> v;

    for (int i = 0; i < v; i++)
    {
    adj_list.push_back({});
    }

    cout << "Enter number of edges:";
    cin >> e;
    for (int c = 0; c < e; c++)
    {
        int i, j;
        cout << "Enter vertex 1:";
        cin >> i;
        cout << "Enter vertex 2:";
        cin >> j;
        adj_mat[i][j] = 1;
        adj_mat[j][i] = 1;
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
    }
    cout << "Adjacency matrix:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }

    cout << "DFS search order is:";
    dfs(adj_mat);
    cout << "\nBFS search order is:";
    bfs();
    return 0;
}
/*
5
5
0
1
0
2
0
3
1
2
2
4
*/