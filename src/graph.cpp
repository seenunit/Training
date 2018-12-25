#include "graph.h"
#include "algorithms.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

template <typename T>
Graph<T>::Graph(std::initializer_list<T> l, int v) {
	m_v = v;
	
	for (auto node : l) {

		std::list<std::pair<T,int>> adjlist;
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
		for (auto it = m_mapAdjList[s].begin(); it != m_mapAdjList[s].end(); it++)
		{
			if (!visited[(*it).first])
			{
				visited[(*it).first] = true;
				queue.push_back((*it).first);
			}
		}
	}
}

template <typename T>
void Graph<T>::addEdge(T v, T w, int Wt) {

	m_mapAdjList[v].push_back(std::make_pair<T,int>(std::move(w), std::move(Wt)));
}

template <typename T>
void Graph<T>::ShortPath(T start, T end, bool bWieghts) {
		// Mark all the vertices as not visited 
	std::map<T, bool> visited;
	std::map<T, int> distance;
	std::map<T, T> pred;

	for (auto map : m_mapAdjList) {
		visited[map.first] = false;
		distance[map.first] = std::numeric_limits<int>::max();
		pred[map.first] = map.first;
	}
	
	// Create a queue for BFS 
	std::list<T> queue;

	T s = start;

	// Mark the current node as visited and enqueue it 
	visited[s] = true;
	distance[s] = 0;
	queue.push_back(s);

	bool reached_end = false;
	
	while (!queue.empty()) {
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (auto it = m_mapAdjList[s].begin(); it != m_mapAdjList[s].end(); it++) {
			T item = (*it).first;

			if (pred[s]!= item && distance[item] > distance[s]+1) {
				
				distance[item] = distance[s] + 1;
				pred[item] = s;
				queue.push_back(item);

				if (item == end) {
					reached_end = true;
					break;
				}					
			}
		}

		if (reached_end == true)
			break;
	}

	if (reached_end == false) {
		std::cout << "Given source and destiantion are not connected" << std::endl;
	}
	else {

		// vector path stores the shortest path 
		std::vector<T> path;
		T crawl = end;
		path.push_back(crawl);
		while (pred[crawl] != crawl) {
			path.push_back(pred[crawl]);
			crawl = pred[crawl];
		}

		// distance from source is in distance array 
		std::cout << "Shortest path length is : "
			<< distance[end];

		// printing path from source to destination 
		std::cout << "\nPath is::\n";
		for (int i = path.size() - 1; i >= 0; i--)
			std::cout << path[i] << " ";

		std::cout << std::endl;
	}


}

void TestGraphBFS() {
	Graph<int> graph({ 0, 1, 2, 3, 4, 5, 6, 7}, 8);

	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 2);
	graph.addEdge(3, 7);
	graph.addEdge(3, 4);
	graph.addEdge(4, 5);
	graph.addEdge(4, 6);
	graph.addEdge(5, 6);
	graph.addEdge(6, 7);
	
	std::cout << "Following is Bredth first traversal :";

	graph.ShortPath(0, 7);

}