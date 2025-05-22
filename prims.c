#include<stdio.h>
#include<stdlib.h>

int visited[10]={0},cost[10][10],min,mincost=0;
void input(int);
void display(int);
void prims(int);

void input(int num)
{
    int i,j;
    printf("\nEnter the adjacency matrix\n\n");
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            printf("Value of cost[%d][%d]",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
}

void display(int num)
{
    printf("\nThe cost of the adjacency matrix \n\n");
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
}

void prims(int num)
{
    int ne=1,a,b,u,v,i;
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    visited[1]=1;

    while(ne<num)
    {
        for(i=1,min=999;i<=num;i++)
        {
            for(int j=1;j<=num;j++)
            {
                if(cost[i][j]<min)
                {
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }
        printf("\n Edge %d (%d - %d) cost : %d",ne++,a,b,min);
        mincost=mincost+min;
        visited[b]=1;
        cost[a][b]=cost[b][a]=999;
    }

    printf("\n\n Minimum cost = %d",mincost);
}

int main()
{
    int num;
    printf("Enter the number of vertices int the graph :");
    scanf("%d",&num);
    input(num);
    display(num);
    prims(num);
    return 0;
}