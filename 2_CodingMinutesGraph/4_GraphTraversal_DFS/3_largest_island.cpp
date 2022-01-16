#include <iostream>
#include <vector>
using namespace std;

int dfsSize(
    vector<vector<int>> grid,
    vector<vector<int>> &visited, int i, int j, int m, int n)
{
    // mark current node as visited
    visited[i][j] = true;

    // we need to perform 4 way DFS from current node so
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int size = 1;
    // performing 4 Way DFS
    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];

        // index must be greater than zero
        // must not exceed row and column
        // value should be 1 and it not visited erlier
        if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1 && !visited[nx][ny])
        {
            // add subcomponent size to the current node
            size += dfsSize(grid, visited, nx, ny, m, n);
        }
    }
    return size;
}

int largest_island(vector<vector<int>> grid)
{
    // find size of the row and column
    int m = grid.size();
    int n = grid[0].size();

    // a visited array of size m*n
    vector<vector<int>> visited(m, vector<int>(n, false));

    // variable to store the largest island
    int largest = 0;

    // call dfs on every node which is not visited erlier and having value as 1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                // dfsSize will return size of island after performing DFS
                int size = dfsSize(
                    grid,
                    visited, i, j, m, n);
                if (size > largest)
                {
                    largest = size;
                }
            }
        }
    }
    return largest;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 0}};

    cout << largest_island(grid) << endl;
}