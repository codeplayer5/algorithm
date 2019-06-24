// Greedy Algorithm - Dijkstra's single source shortest path 
#include <stdio.h> 
#include <limits.h> 
#include <iostream>

// Number of vertices
#define V 9 

// find the vertex with minimum distance value
int minDestVertex(int dist[], bool spSet[]) 
{     
    int min = INT_MAX; // infinite
    int min_v_index; 

    for (int v = 0; v < V; v++)     // 0 ~ 8 for all vertex
    {
	    if (spSet[v] == false &&    // if vertex is not in path
            dist[v] <= min)         // and distance is smaller or equal than min
        {
            min = dist[v];
            min_v_index = v; 
        }
    }	    

    return min_v_index;             // vertex index for minimal distance
} 

void printCurrentStatus(int dist[], bool spSet[]) 
{
    for (int v = 0; v < V; v++)
    {
        if (dist[v] == INT_MAX)
            std::cout << "INF" << '\t';
        else
            std::cout << dist[v] << '\t';
    }

    std::cout << std::endl;

    for (int v = 0; v < V; v++)
    {
        std::cout << spSet[v] << '\t';
    }    

    std::cout << std::endl << std::endl;
}

void printSolution(int dist[], int n) 
{ 
    printf("Vertex Distance from Source\n"); 
    
    for (int i = 0; i < V; i++) 
	    printf("%d \t %d\n", i, dist[i]); 
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V];	 // output, dist[i] = the shortest distance from src to i 

	bool spSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
					// path tree or shortest distance from src to i is finalized 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, spSet[i] = false; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 


	// Find shortest path for all vertices 
	for (int count = 0; count < V-1; count++) // 0 ~ 7 why?
	{ 
        printCurrentStatus(dist, spSet);

	    // Pick the minimum distance vertex from the set of vertices not 
	    // yet processed. u is always equal to src in the first iteration. 
	    int u = minDestVertex(dist, spSet); // pick a vertex 

	    // Mark the picked vertex as processed (final shortest path from src to u)
	    spSet[u] = true; 
        
	    // Update dist value of the adjacent vertices of the picked vertex
	    for (int v = 0; v < V; v++) // 0 ~ 8
        {
		    if (!spSet[v] &&         // v not in path
                graph[u][v] &&       // u and v are adjacent
                dist[u] != INT_MAX)  // if we already have dist[u]
            {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v])      // if new path is shorter
			        dist[v] = newDist;      // calc dist[v]
            } 
        }
	} 

	// print the constructed distance array 
	printSolution(dist, V); 
} 

int main() 
{ 
    // adjacency matrix (symmetric)
    // dist = graph[src][dest] = graph[dest][src]
    int graph[V][V] = { {0,  4,  0,  0,  0,  0,  0,  8,  0}, 
	    				{4,  0,  8,  0,  0,  0,  0, 11,  0}, 
		    			{0,  8,  0,  7,  0,  4,  0,  0,  2}, 
			    		{0,  0,  7,  0,  9, 14,  0,  0,  0}, 
				    	{0,  0,  0,  9,  0, 10,  0,  0,  0}, 
    					{0,  0,  4, 14, 10,  0,  2,  0,  0}, 
	    				{0,  0,  0,  0,  0,  2,  0,  1,  6}, 
		    			{8, 11,  0,  0,  0,  0,  1,  0,  7}, 
			    		{0,  0,  2,  0,  0,  0,  6,  7,  0} 
				    	}; 

    printf("graph[%d][%d] : %d\n", 3, 5, graph[3][5]);

	dijkstra(graph, 0); 

	return 0; 
} 
