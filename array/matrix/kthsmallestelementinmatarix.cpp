#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int kthSmallest(int mat[10][10], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q.push(mat[i][j]);
        }
    }

    int count = 0;
    while (count < k - 1)
    {
        q.pop();
        count++;
    }
    return q.top();
}
