#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
struct Edge
{int src, dest, weight;};
struct Graph
{
 int V, E; // V-> Number of vertices, E-> Number of edges
 struct Edge* edge; // graph is represented as an array of edges.
};
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
 struct Graph* graph = (struct Graph*) malloc( sizeof (struct Graph) );
 graph->V = V;
 graph->E = E;
 graph->edge =(struct Edge*) malloc( graph->E * sizeof (struct Edge ) );
 return graph;
}
// A utility function used to print the solution
void printArr(int dist[], int n)
{
 printf("Vertex Distance from Source\n");
 for (int i = 0; i< n; ++i)
 printf("%d \t\t %d\n", i, dist[i]);
}
void BellmanFord(struct Graph* graph, int src)
{
 int V = graph->V;
 int E = graph->E;
 int dist[V];
 // Step 1: Initialize distances from src to all other vertices as INFINITE
 for (int i = 0; i< V; i++)
 dist[i] = INT_MAX;
 dist[src] = 0;
 for (int i = 1; i<= V-1; i++)
 {
 for (int j = 0; j < E; j++)
 {
 int u = graph->edge[j].src;
 int v = graph->edge[j].dest;
 int weight = graph->edge[j].weight;
 if (dist[u] != INT_MAX &&dist[u] + weight <dist[v])
 dist[v] = dist[u] + weight;
 }
 }
 for (int i = 0; i< E; i++)
 {
 int u = graph->edge[i].src;
 int v = graph->edge[i].dest;
 int weight = graph->edge[i].weight;
 if (dist[u] != INT_MAX &&dist[u] + weight <dist[v])
 printf("Graph contains negative weight cycle");
 }
 printArr(dist, V);
return;
}
int main()
{
 int V,E;
 printf("\nEnter the no. of vertics: ");
 scanf("%d", &V);
 printf("\nEnter the no. of Edges: ");
 scanf("%d", &E);
 struct Graph* graph = createGraph(V, E);
 int p,q,r;
 char a='y';
 int i=0;
 while(i<E)
 {
 printf("for %d edge Enter the source:", i);
 scanf("%d",&p);
 graph->edge[i].src = p;
 printf("Enter the destination:");
 scanf("%d", &q);
 graph->edge[i].dest =q;
 printf("Enter the weight:");
 scanf("%d",&r);
 graph->edge[i].weight = r;
 i++;
 }
 BellmanFord(graph, 0);
 return 0;
}
