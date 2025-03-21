#include <iostream>
#include <vector>

#define INF 999999

std::vector<std::vector<int>> adjMatrix;

void addEdge(int x, int y, int weight){
    // Undirected graph so adjMatrix is symmetrical across diagonal
    adjMatrix[x-1][y-1] = weight;
    adjMatrix[y-1][x-1] = weight;
}

// Helper Function
void printAdjMatrix() {
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            if (val == INF)
                std::cout << "- ";
            else
                std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    // Initialize all values in graph to large value
    adjMatrix.resize(22,std::vector<int>(22,INF));
    
    // Make diagonal 0
    for(int i = 0; i < 22; ++i){
        adjMatrix[i][i] = 0;
    }

    // Add edges
    addEdge(1, 2, 1);
    addEdge(1, 11, 1);
    addEdge(2, 3, 1);
    addEdge(2, 21, 1);
    addEdge(3, 4, 1);
    addEdge(3, 8, 2);
    addEdge(4, 5, 1);
    addEdge(5, 6, 2);
    addEdge(5, 7, 1);
    addEdge(5, 22, 1);
    addEdge(6, 7, 1);
    addEdge(7, 8, 1);
    addEdge(8, 9, 1);
    addEdge(9, 10, 1);
    addEdge(9, 19, 1);
    addEdge(10, 11, 1);
    addEdge(10, 18, 2);
    addEdge(11, 12, 2);
    addEdge(11, 17, 1);
    addEdge(12, 13, 2);
    addEdge(13, 14, 2);
    addEdge(13, 21, 1);
    addEdge(14, 15, 1);
    addEdge(14, 16, 1);
    addEdge(14, 20, 1);
    addEdge(17, 18, 2);
    addEdge(18, 19, 1);
    addEdge(20, 21, 2);
    addEdge(20, 22, 1);

    printAdjMatrix();

    return 0;
}