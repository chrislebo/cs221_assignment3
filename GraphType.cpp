//
// Chris Lebeau
// 4/14/2021.
//
// GraphType Implementation File
//

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>

#include "GraphType.h"

GraphType::GraphType()
// Post: Arrays of size 7 are dynamically allocated for
//       marks and vertices.  numVertices is set to 0; 
//       maxVertices is set to 7.
{
  numVertices = 0;
  maxVertices = 7;
  vertices = new VertexType[7];
  marks = new bool[7];
}



/*
GraphType::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for  
//       marks and vertices.  
//       numVertices is set to 0; maxVertices is set to maxV.
{
  numVertices = 0;
  maxVertices = maxV;
  vertices = new VertexType[maxV];
  marks = new bool[maxV];
}
*/



// Post: arrays for vertices and marks have been deallocated.
GraphType::~GraphType()
{
  delete [] vertices;
  delete [] marks;
}
const int NULL_EDGE = 0;


void GraphType::AddVertex(VertexType vertex)
// Post: vertex has been stored in vertices.
//       Corresponding row and column of edges has been set 
//       to NULL_EDGE.
//       numVertices has been incremented.
{
  vertices[numVertices] = vertex;

  for (int index = 0; index < numVertices; index++)
  {
    edges[numVertices][index] = NULL_EDGE;
    edges[index][numVertices] = NULL_EDGE;
  }
  numVertices++;
}

int IndexIs(VertexType* vertices, VertexType vertex)
// Post: Returns the index of vertex in vertices.
{
  int index = 0;

  while (!(vertex == vertices[index]))
    index++;  
  return index;
}       


void GraphType::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex);
  edges[row][col] = weight;
}



/*
int GraphType::WeightIs(VertexType fromVertex, VertexType toVertex)
// Post: Returns the weight associated with the edge 
//       (fromVertex, toVertex).
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex);
  return edges[row][col];
}
*/



void GraphType::GetToVertices(VertexType vertex, queue<int>& adjVertices)
// Post: 
{
    int fromIndex;
    int toIndex;

    fromIndex = IndexIs(vertices, vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.push(vertices[toIndex]);
}

void GraphType::ClearMarks()
{
    for (int i = 0; i < maxVertices; i++)
        marks[i] = false;
}

void GraphType::MarkVertex(VertexType vertex)
{
    int index = IndexIs(vertices, vertex);
    marks[index] = true;
}

bool GraphType::IsMarked(VertexType vertex)
{
    int index = IndexIs(vertices, vertex);
    return marks[index];
}




