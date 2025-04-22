#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int adjacencyMatrix[SIZE][SIZE], explored[SIZE];

void depthFirstSearch(int node, int totalNodes) {
    explored[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < totalNodes; i++) {
        if (adjacencyMatrix[node][i] && !explored[i]) {
            depthFirstSearch(i, totalNodes);
        }
    }
}

int main() {
    int nodes, connections, startNode, node1, node2;

    printf("Enter total nodes: ");
    scanf("%d", &nodes);

    printf("Enter total edges: ");
    scanf("%d", &connections);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }

    printf("Enter edges (node1 node2):\n");
    for (int i = 0; i < connections; i++) {
        scanf("%d %d", &node1, &node2);
        adjacencyMatrix[node1][node2] = 1;
        adjacencyMatrix[node2][node1] = 1;
    }

    printf("Enter start node: ");
    scanf("%d", &startNode);

    printf("DFS Order: ");
    for (int i = 0; i < nodes; i++) explored[i] = 0;
    depthFirstSearch(startNode, nodes);
    printf("\n");

    return 0;
}
