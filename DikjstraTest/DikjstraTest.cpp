#include "pch.h"
#include "CppUnitTest.h"
#include"../Дейкстри/Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DijkstraTest
{
    TEST_CLASS(DijkstraTest)
    {
    public:

        TEST_METHOD(Test_dijstra_6x6_1)
        {
            int graph[size_x_size][size_x_size] = {
                {0, 5, 3, 0, 0, 0},
                { 0, 0, 0, 0, 5, 10 },
                { 3, 5, 0, 4, 0, 0 },
                { 0, 1, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 6 },
                { 0, 10, 0, 0, 0, 0 }
            };
            Assert::AreEqual(dijkstra(graph, 0), 40);
        }

        TEST_METHOD(Test_dijstra_6x6_2)
        {
            int graph[size_x_size][size_x_size] =
            {
                {0, 1, 2, 0, 0, 0},
                {1, 0, 0, 5, 1, 0},
                {2, 0, 0, 2, 3, 0},
                {0, 5, 2, 0, 2, 2},
                {0, 1, 3, 2, 0, 1},
                {0, 0, 0, 2, 1, 0}
            };
            Assert::AreEqual(dijkstra(graph, 0), 12);
        }

        /* TEST_METHOD(Test_dijstra_9x9)
         {
             int graph[size_x_size][size_x_size] = {
                 { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                 { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                 { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                 { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                 { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                 { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                 { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                 { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                 { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
             };

             Assert::AreEqual(dijkstra(graph, 0), 98);
         }*/
    };
}