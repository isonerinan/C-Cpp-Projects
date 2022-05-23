// Ýbrahim Soner ÝNAN - 040200075
// C program for linked list implementation of weighted directed graph data structure
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// Define the maximum number of vertices in the graph
#define N 7

// Data structure to store a graph object
struct Graph
{
    // An array of pointers to Node to represent an adjacency list
    struct Node* head[N];
};

// Data structure to store adjacency list nodes of the graph
struct Node
{
    int destination, distance;
    struct Node* next;
};

// Data structure to store a graph edge
struct Edge {
    int source, destination, weight;
};

// Function to create an adjacency list from specified edges
struct Graph* createGraph(struct Edge edges[], int n)
{
    // Allocate storage for the graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    // Initialize head pointer for all vertices
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }

    // Add edges to the directed graph one by one
    for (int i = 0; i < n; i++)
    {
        // Get the source and destination vertex
        int src = edges[i].source;
        int dest = edges[i].destination;
        int weight = edges[i].weight;

        // Allocate a new node of adjacency list from src to dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->destination = dest;
        newNode->distance = weight;

        // Point new node to the current head
        newNode->next = graph->head[src];

        // Point head pointer to the new node
        graph->head[src] = newNode;
    }

    return graph;
}

// Function to print adjacency list representation of a graph
void printGraph(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        // Print current vertex/node (city), all its neighbours and the weight (distance) between them
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("%d -> %d (%d)\t", i, ptr->destination, ptr->distance);
            ptr = ptr->next;
        }

        printf("\n");
    }
}


// Function to find a path from a city to another.
// This function finds the path by selecting the city which has the smaller city code first (e.g. Prague = 0, Helsinki= 1)
void findPath(struct Edge edges[], char cities[7][10], int sourceCity, int destCity, int numberofEdges)
{
    int sum = 0;    // Total distance thus far
    int tempCity = sourceCity;  // Used to traverse the graph
    int tempDistance = 0;

    printf("\nFrom: %s to: %s", cities[sourceCity], cities[destCity]);
    printf("\nThe path is: ", cities[sourceCity]);

    // Check if the first and second city are the same
    if (sourceCity == destCity) {
        printf("%s", cities[destCity]);
    }

    // This first loop is to ensure we traverse the graph not once, but until finding the destination
    while (sourceCity != destCity) {

        // Traverse the graph, starting from index 0
        for (int i = 0; (i < numberofEdges) && (sourceCity != destCity); i++) {

            // Check if the current vertex's source city matches the input's source city
            if (edges[i].source == sourceCity) {

                printf("%s, ", cities[sourceCity]); // Outputting the path one by one

                // If the current vertex's destination matches the input's destination, directly go there
                if (edges[i].destination == destCity) {
                    printf("%s", cities[destCity]);
                    sourceCity = destCity;
                    sum += edges[i].weight;
                    break;
                }

                // If not, this means no direct path. Then we need to go to the next vertex and start over as if that is our new source city
                else {
                    tempCity = edges[i].destination;
                    tempDistance = edges[i].weight;
                }

                sum += tempDistance;    // Since we're moving from one city to another, we need to account for the distance traversed
            }

            sourceCity = tempCity;      // Move to the new city

        }

    }



    printf("\nThe distance is: %d km", sum);
}


int main(void)
{
    // The graph given in the homework
    struct Edge edges[] =
    {
        {0, 1, 1845}, {0, 5, 1264}, {1, 3, 7815}, {2, 3, 1303}, {2, 5, 8132}, {2, 6, 11550}, {3, 4, 5782}, {3, 6, 10838}, {4, 2, 4616}, {5, 3, 9566}, {6, 5, 5567}
    };

    // String array to store the names of the cities, indexed by the codes. This will be used in our path finding function
    char cities[7][10] = { "Prague", "Helsinki", "Beijing", "Tokyo", "Jakarta", "London", "New York" };

    // Calculate the total number of edges, this will be used in our functions' loops
    int n = sizeof(edges) / sizeof(edges[0]);

    // Construct a graph from the given edges
    struct Graph* graph = createGraph(edges, n);

    int from, to;

    // Loop until user closes the window
    while (1) {

        printf("\n********************************\n");

        printf("Cities:\n");
        for (int i = 0; i < N; i++) {
            printf("%s = %d\n", cities[i], i);
        }

        // Print the graph to make things more understandable for the user
        printf("\n\nThe graph is:\n\n");
        printGraph(graph);

        // Get user input for the desired path
        printf("\nEnter the first city: ");
        scanf("%d", &from);

        printf("\nEnter the second city: ");
        scanf("%d", &to);

        // Function to print the found path
        findPath(edges, cities, from, to, n);

        Sleep(2000);    //
    }

    return 0;
}