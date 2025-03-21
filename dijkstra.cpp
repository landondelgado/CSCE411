#include <iostream>
#include <vector>
#include <queue>

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

std::vector<int> dijkstra(int source){
    std::vector<int> distances(22, INF);
    distances[source] = 0;

    // Using a priority queue with the greater argument to give 
    // highest priority to the smallest element making it a min-queue
    // The pairs are in the form of {distance, vertex}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
    std::greater<std::pair<int, int>>> mq;
    mq.push({0,source});

    while(!mq.empty()){
        // Process vertex with lowest distance
        int currVertex = mq.top().second;
        mq.pop();

        for(int neighbor = 0; neighbor < 22; neighbor++){
            // If neighbor found
            if(adjMatrix[currVertex][neighbor] != INF){
                int weight = adjMatrix[currVertex][neighbor];

                // If distance can be improved update and push to queue
                if(distances[currVertex] + weight < distances[neighbor]){
                    distances[neighbor] = distances[currVertex] + weight;
                    mq.push({distances[neighbor],neighbor});
                }
            }
        }
    }

    return distances;
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

    std::vector<int> distances = dijkstra(0);

    std::cout << "Shortest Distance from 1->6 is: " << distances[5] << std::endl;
    std::cout << "Shortest Distance from 1->8 is: " << distances[7] << std::endl;
    std::cout << "Shortest Distance from 1->9 is: " << distances[8] << std::endl;
    std::cout << "Shortest Distance from 1->15 is: " << distances[14] << std::endl;
    std::cout << "Shortest Distance from 1->16 is: " << distances[15] << std::endl;
    std::cout << "Shortest Distance from 1->22 is: " << distances[21] << std::endl;

    return 0;
}