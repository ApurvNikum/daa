#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Graph{
int source, destination, weight;
};
void printOutput(int dist[], int v){
cout<<"Vertex"<<"\t"<<"Distance from source vertex"<<endl;
for(int i=0;i<v;i++){
cout<<i<<"\t"<<dist[i]<<endl;
}
}
void Bellman_Ford(Graph g[], int sourceV, int v, int e)
{
int dist[v];
for(int i=0;i<v;i++)
{
dist[i] = 999999;
}
dist[sourceV] = 0;
for(int i=1;i<v;i++){
for(int j=0;j<e;j++){
int u = g[j].source;
int v = g[j].destination;
int w = g[j].weight;
if(dist[u]+w < dist[v]){
dist[v] = dist[u] + w;
}
}
}
for(int i=0;i<e;i++){
int u = g[i].source;
int v = g[i].destination;
int w = g[i].weight;
if(dist[u]+w < dist[v]){
cout<<"Negative cycle is present"<<endl;
}
}
printOutput(dist, v);
return;
}
int main(){
int vertices = 5, edges = 10, sourceV = 0;
Graph g[edges] = {{0,1,6},{0,2,7},{1,2,8},{1,4,-4},{1,3,5},{3,1,-2},{2,3,-
3},{2,4,9},{4,0,2},{4,3,7}};
Bellman_Ford(g, 0, 5, 10);
return 0;
}