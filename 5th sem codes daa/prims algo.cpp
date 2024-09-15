/*prim's algo*/
#include <limits.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 5

// A utility function to find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], int mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
    // Key values used to pick the minimum weight edge in cut
    int key[V];
    // To represent the set of vertices included in MST
    int mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    // Always include the first vertex in MST.
    // Make key 0 so that this vertex is picked as the first vertex.
    key[0] = 0;

    // First node is always the root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
            // graph[u][v] is non-zero only for adjacent vertices, and mstSet[v] is 0 for vertices not yet included in MST. 
			// Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Driver's code
int main()
{
    int graph[V][V];
    
    printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
    
    // Input the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the solution
    primMST(graph);

    return 0;
}

