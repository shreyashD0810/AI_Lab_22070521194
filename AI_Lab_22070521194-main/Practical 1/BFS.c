#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int matrix[SIZE][SIZE], visitedNodes[SIZE], queueArr[SIZE];
int head = -1, tail = -1;

void addToQueue(int node) {
    if (tail == SIZE - 1) return;
    if (head == -1) head = 0;
    queueArr[++tail] = node;
}

int removeFromQueue() {
    if (head == -1 || head > tail) return -1;
    return queueArr[head++];
}

void breadthFirstSearch(int startNode, int totalNodes) {
    for (int i = 0; i < totalNodes; i++) visitedNodes[i] = 0;
    addToQueue(startNode);
    visitedNodes[startNode] = 1;
    printf("BFS Order: ");
    while (head <= tail) {
        int currentNode = removeFromQueue();
        printf("%d ", currentNode);
        for (int i = 0; i < totalNodes; i++) {
            if (matrix[currentNode][i] && !visitedNodes[i]) {
                addToQueue(i);
                visitedNodes[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int nodes, links, startNode, node1, node2;

    printf("Enter total nodes: ");
    scanf("%d", &nodes);

    printf("Enter total edges: ");
    scanf("%d", &links);

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            matrix[i][j] = 0;
        }
    }

    printf("Enter edges (node1 node2):\n");
    for (int i = 0; i < links; i++) {
        scanf("%d %d", &node1, &node2);
        matrix[node1][node2] = 1;
        matrix[node2][node1] = 1;
    }

    printf("Enter start node: ");
    scanf("%d", &startNode);

    breadthFirstSearch(startNode, nodes);

    return 0;
}
