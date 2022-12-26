#include<stdio.h>
int a,b,i,j,n,ne=1,u,v;
int visited[10]={0},min,mincost=0,cost[10][10];
int main(){
    printf("Enter the no of nodes : ");
    scanf("%d",&n);
    printf("Enter the adjancency matrx :\n ");
    for(i=1;i<=n;i++)
    {
         for(j=1;j<=n;j++)
         {
             scanf("%d\n",&cost[i][j]);
             if(cost[i][j]==0)
             cost[i][j]=999;
         }
    }
    visited[1]=1;
    printf("\n");
    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]<min)
        if(visited[i]!=0)
        {
            min = cost[i][j];
            a=u=i;
            b=v=j;
        }
        if(visited[u]==0 || visited[v]==0)
        {
            printf("\n Edge %d : %d %d cost : %d",ne++,a,b,min);
            mincost += min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\nMinimum cost : %d",mincost);
    return 0;
}
/*0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0 */
