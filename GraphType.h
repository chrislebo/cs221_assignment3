//
// Chris Lebeau
// 4/14/2021.
//
// GraphType Header File
//

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

typedef char VertexType;

class GraphType
{
public:
    GraphType(); // Default of 7 vertices
    ~GraphType();
    void AddVertex(VertexType);
    void AddEdge(VertexType, VertexType, int);
    void GetToVertices(VertexType, queue<int>&);
    void ClearMarks();
    void MarkVertex(VertexType);
    bool IsMarked(VertexType);
private:
    int numVertices;
    int maxVertices;
    VertexType* vertices;
    int edges[7][7];
    bool* marks; // marks[i] is mark for vertices[i].
};
