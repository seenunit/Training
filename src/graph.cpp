#include "graph.h"
#include "algorithms.h"
#include <iostream>
#include <algorithm>

template <typename T>
Graph<T>::Graph(std::initializer_list<T> l, int v) {
	m_v = v;
	
	for (auto node : l) {

		std::list<T> adjlist;
		m_mapAdjList[node] = adjlist;
		//if (m_mapAdjList.find(node) == m_mapAdjList.end()) {
		//	
		//	m_mapAdjList.insert(std::pair<T, std::list<T>>(node, adjlist));
		//	
		//}			
	}
}

template <typename T>
Graph<T>::~Graph() {
}

template <typename T>
void Graph<T>::BFS(T s) {

	// Mark all the vertices as not visited 
	std::map<T, bool> visited;

	for (auto map : m_mapAdjList) {
		visited[map.first] = false;
	}
	
	// Create a queue for BFS 
	std::list<T> queue;

	// Mark the current node as visited and enqueue it 
	visited[s] = true;
	queue.push_back(s);
	
	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		std::cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (auto i = m_mapAdjList[s].begin(); i != m_mapAdjList[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

template <typename T>
void Graph<T>::addEdge(T v, T w) {

	m_mapAdjList[v].push_back(w);
}

void TestGraphBFS() {
	Graph<int> graph({ 1, 2, 3, 4, 5, 6}, 6);

	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(2, 5);
	graph.addEdge(3, 5);
	graph.addEdge(4, 5);
	graph.addEdge(4, 6);
	graph.addEdge(5, 6);

	std::cout << "Following is Bredth first traversal :";

	graph.BFS(1);

}