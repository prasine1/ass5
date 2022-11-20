#include <iostream>
#include <limits.h>
using namespace std;
#define V 11
int minDistance(int D[], bool pathset[])
{
	int min = INT_MAX, index;
	for (int v = 0; v < V; v++)
		if (D[v] <= min && pathset[v] == false)
			 index = v, min = D[v];
	return index;
}
void path(int D[])
{
    int d;
	cout <<"Shortest Distance From capital City to (D and I)      Total weight" << endl;
	for (int i = 0; i < V; i++)
	    if(i==3 || i==8){
		    cout <<"0-->"<< i << " \t\t\t\t\t\t\t  "<<D[i]<< endl;
	        
	    }
		cout<<"Shortest path from D-->A-->I is "; 
		cout<<" "<<D[3] <<" + " <<D[8]<<" = ";
		d=D[3] + D[8];
		cout<< d;

}

void dijkstra(int G[V][V], int source)
{
	bool pathset[V];   
	int D[V];
	for (int i = 0; i < V; i++)
		pathset[i] = false, D[i] = INT_MAX;
	D[source] = 0;
	for (int J = 0; J < V - 1; J++) {
		int u = minDistance(D, pathset);
		pathset[u] = true;
		for (int v = 0; v < V; v++)
			if (!pathset[v] && G[u][v] && D[u] != INT_MAX
				&& D[u] + G[u][v] < D[v])
				D[v] = G[u][v] + D[u];
	}
	path(D);
}

int main()
{
	int G[V][V] = { 
	{ 0, 5, 0, 0, 12, 0, 21, 0, 15, 1, 0 },
	{ 5, 0, 9, 0, 0, 0, 18, 0, 0, 20, 0 },
	{ 0, 9, 0, 16, 0, 0, 17, 0, 0, 0, 8},
	{ 0, 0, 16, 0, 0, 7, 11, 14, 0, 0, 0},
	{ 12, 0, 0, 0, 0, 6, 2, 0, 10, 0, 0},
	{ 0, 0, 0, 7, 6, 0, 0, 4, 0, 19, 13 },
	{ 21, 18, 17, 11, 2, 0, 0, 3, 0, 0, 0 },
	{ 0, 0, 0, 14, 0, 4, 3, 0, 0, 0, 0 },
	{ 15, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0 }, 
	{ 1, 20, 0, 0, 0, 19, 0, 0, 0, 0, 0 },
	{ 0, 0, 8, 0, 0, 13, 0, 0, 0, 0, 0 },};
	dijkstra(G, 0);
	return 0;
}