//
// Chris Lebeau
// 3/9/2021.
//
// TreeType Test Driver
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <stack>
#include <queue>
#include "GraphType.h"

void BreadthFirstSearch(GraphType graph, VertexType startVertex, VertexType endVertex);

using namespace std;

int main() {
    ifstream infile;
    ofstream outfile;
    string infileName;
    string outfileName;
    string outputLabel;
    string command;

    char item;
    char item2;
    int weight;
    GraphType myGraph;
    int numCommands;

    cout << "Enter name of input file; press return." << endl;
    cin >> infileName;
    infile.open(infileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin >> outfileName;
    outfile.open(outfileName.c_str());

    cout << "Enter name of test run; press return" << endl;
    cin >> outputLabel;
    outfile << outputLabel << endl;

    if (!infile) {
        cout << "File not found." << endl;
        exit(2);
    }

    infile >> command;
    numCommands = 0;
    while (command != "Quit")
    {
        if (command == "AddVertex")
        {
            infile >> item;
            myGraph.AddVertex(item);
            outfile << item;
            outfile << " is added to graph." << endl;
        }
        else if (command == "AddEdge")
        {
            infile >> item >> item2 >> weight;
            myGraph.AddEdge(item, item2, weight);
            outfile << "Edge created between " << item << " and " << item2;
            outfile << " with weight of " << weight << "." <<  endl;
        }
        else
            cout << command << " is not a valid command." << endl;

        numCommands++;
        cout << " Command number " << numCommands << " completed." << endl;
        infile >> command;
    }

    cout << endl << endl;
    BreadthFirstSearch(myGraph, 'A', 'E');
    cout << endl << endl;

    cout << "Testing completed." << endl;
    infile.close();
    outfile.close();
    return 0;

}


void BreadthFirstSearch(GraphType graph, VertexType startVertex, VertexType endVertex)
// Assumption: VertexType is a type for which the Ò==Ò and
//             "<<" operators are defined.
{
    using namespace std;
    queue<int> queue, vertexQ;

    bool found = false;
    VertexType vertex;
    VertexType item;



    graph.ClearMarks();
    queue.push(startVertex);
    do
    {
        queue.pop();

        if (vertex == endVertex)
        {
            cout  << vertex;
            found = true;
        }
        else
        {
            if (!graph.IsMarked(vertex))
            {
                graph.MarkVertex(vertex);
                cout  << vertex;
                graph.GetToVertices(vertex, vertexQ);

                while (!vertexQ.empty())
                {
                    vertexQ.pop();
                    if (!graph.IsMarked(item))
                        queue.push(item);
                }
            }
        }
    } while (!queue.empty() && !found);
    if (!found)
        cout << "Path not found." << endl;
}

