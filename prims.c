#include <stdio.h>
#include <stdlib.h>

int visited[10] = {0}, cost[10][10], min;

void input(int num)
{
    int i, j;
    printf("\nEnter the adjacency matrix\n\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("Value of cost[%d][%d]", i, j);
            scanf("%d", &cost[i][j]);
        }
    }
}

void prims(int num)
{
    int ne = 1, a, b;
    int mincost = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[0] = 1;

    while (ne < num)
    {
        for (int i = 0, min = 999; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (cost[i][j] < min && visited[i] != 0)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        printf("\n Edge %d (%d - %d) cost : %d", ne++, a, b, min);
        mincost = mincost + min;
        visited[b] = 1;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\n Minimum cost = %d", mincost);
}

int main()
{
    int num;
    printf("Enter the number of vertices int the graph :");
    scanf("%d", &num);
    input(num);
    prims(num);
    return 0;
}