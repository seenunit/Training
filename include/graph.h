#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <initializer_list>
#include <map>

template <typename T>
class Graph
{
public:
	Graph(std::initializer_list<T> l, int v);
	virtual ~Graph();

	// Add edge to graph
	void addEdge(T v, T w, int Wt=1);

	// print BFS traversal from given source s
	void BFS(T s);

	// Find shortest path 
	void ShortPath(T start, T end, bool bWieghts = false);

private:
	int m_v; //n o. of vertices
	std::map<T, std::list<std::pair<T,int>>> m_mapAdjList;
};

#endif //GRAPH_H