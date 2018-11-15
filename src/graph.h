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
	void addEdge(T v, T w);

	// print BFS traversal from given source s
	void BFS(T s);

private:
	int m_v; //n o. of vertices
	std::map<T, std::list<T>> m_mapAdjList;
};

#endif //GRAPH_H