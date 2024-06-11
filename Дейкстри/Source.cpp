#include "Header.h"

void main()
{
    int graph[size_x_size][size_x_size] = {
                        {0, 10, 20, 0, 0, 0},
                        {10, 0, 0, 50, 10, 0},
                        {20, 0, 0, 20, 33, 0},
                        {0, 50, 20, 0, 20, 2},
                        {0, 10, 33, 20, 0, 1},
                        {0, 0, 0, 2, 1, 0} };

    cout << "\nSum = " << dijkstra(graph, 0) << endl;
}
