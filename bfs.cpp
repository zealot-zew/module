#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int graph[10][10],count=0;
vector<int> visited(10,-1);
void BFS(int n);
void bfs(int node,int n);

int main()
{
    int n;
    cout<<"Enter the number of vertices in the graph :";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>graph[i][j];
        }
    }
    BFS(n);
    return 0;
}

void BFS(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==-1)
        {
            bfs(i,n);
        }
    }
}

void bfs(int node,int n)
{
    queue<int> q;
    count++;
    visited[node]=count;
    q.push(node);
    cout<<node;
    while(!q.empty())
    {
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==-1 && graph[q.front()][i]==1)
            {
                count++;
                visited[i]=count;
                cout<<i;
                q.push(i);
            }
        }
        q.pop();
    }

}