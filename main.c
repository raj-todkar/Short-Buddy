#include <stdio.h>
#define INFINITY 9999
#define V 7

struct city
{
char name[20];
}c[6];

void Dijkstra(int Graph[V][V], int n, int start);

void Dijkstra(int Graph[V][V], int n, int start)
        {
            int cost[V][V], distance[V], pred[V];
            int visited[V], count, mindistance, nextnode, i, j;


            for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if (Graph[i][j] == 0)
                        cost[i][j] = INFINITY;
                        else
                        cost[i][j] = Graph[i][j];
                    }
                }
            for (i = 0; i < n; i++)
                {
                    distance[i] = cost[start][i];
                    pred[i] = start;
                    visited[i] = 0;
                }

            distance[start] = 0;
            visited[start] = 1;
            count = 1;

            while (count < n - 1)
            {
                mindistance = INFINITY;
                for (i = 0; i < n; i++)
                    {
                        if (distance[i] < mindistance && !visited[i])
                            {
                                mindistance = distance[i];
                                nextnode = i;
                            }
                    }

            visited[nextnode] = 1;
            for (i = 0; i < n; i++)
                {
                    if (!visited[i])
                    if (mindistance + cost[nextnode][i] < distance[i])
                        {
                            distance[i] = mindistance + cost[nextnode][i];
                            pred[i] = nextnode;
                        }
                }
        count++;
  }


    for (i = 0; i < n; i++)
        {
            if (i != start)
                {
                    printf("\nDistance from Royton to %s: %d miles", c[i], distance[i]);
                }
        }

        printf("\n\n*********************Final Answer************************\nThe minimum distance for Leon's journey to work is %d miles\n",distance[6]);
}
int main()
{
    int i, j, n, u;
    n = 7;

   strcpy(c[1].name, "Shaw");
   strcpy(c[2].name, "Chadderton");
   strcpy(c[3].name, "Lees");
   strcpy(c[4].name, "Dukinfield");
   strcpy(c[5].name, "Mossley");
   strcpy(c[6].name, "Aston");

    int Graph[V][V] = {
                        {0, 4, 3, 0, 0, 0, 0},
						{4, 0, 0, 3, 12, 0, 0},
						{3, 0, 0, 5, 6, 0, 0},
						{0, 3, 5, 0, 0, 6, 0},
						{0, 12, 6, 0, 0, 3, 7},
						{0, 0, 0, 6, 3, 0, 3},
						{0, 0, 0, 0, 7, 3, 0},
                      };

    u = 0;
    Dijkstra(Graph, n, u);

    return 0;
}
