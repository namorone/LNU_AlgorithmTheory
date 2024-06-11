#pragma once
#include <iostream>
using namespace std;

const int size_x_size = 6;
//const int size_x_size = 9;

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < size_x_size; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

int printSolution(int dist[])
{
    int sum = 0;
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < size_x_size; i++) {
        cout << i << " \t\t" << dist[i] << endl;
        sum += dist[i];
    }
    return sum;
}
int dijkstra(int graph[size_x_size][size_x_size], int src)
{
    int dist[size_x_size];
    bool sptSet[size_x_size];

    for (int i = 0; i < size_x_size; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;

    for (int count = 0; count < size_x_size - 1; count++) {

        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < size_x_size; v++)

            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    return printSolution(dist);
}