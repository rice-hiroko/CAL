/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
using namespace std;

template <class T> class Edge;
template <class T> class Graph;

template <class T>
class Vertex {
	T info;
	vector<Edge<T>  > adj;
	bool visited;
public:
	Vertex(T in);
	friend class Graph<T>;
};


template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false){}



template <class T>
class Edge {
	Vertex<T> * dest;
	double weight;
public:
	Edge(Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w){}

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
public:
	vector<Vertex<T> * > getVertexSet() const;
	int getNumVertex() const;
	bool addVertex(const T &in);
	bool removeVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeEdge(const T &sourc, const T &dest);

};

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
	return vertexSet;
}

template <class T>
bool Graph<T>::addVertex(const T &in) {
	Vertex<T>* c = new Vertex<T>(in);
	for(int i = 0; i < vertexSet.size(); i++) {
		if(vertexSet[i]->info == c->info) {
			return false;
		}
	}
	vertexSet.push_back(c);
	return true;
}

template <class T>
bool Graph<T>::removeVertex(const T &in) {
	Vertex<T>* c = new Vertex<T>(in);
	for(int i = 0; i < vertexSet.size(); i++) {
		if(vertexSet[i]->info == c->info) {
			vertexSet.erase(vertexSet.begin() + i);
			return true;
		}
	}
	return false;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	Vertex<T>* sour = new Vertex<T>(sourc);
	Vertex<T>* des = new Vertex<T>(dest);
	bool sourExists = false, desExists = false;
	int sourIndex = 0;
	for(int i = 0; i < vertexSet.size(); i++) {
		if(vertexSet[i]->info == sour->info) {
			sourIndex = i;
			sourExists = true;
		}
		if(vertexSet[i]->info == des->info) {
			desExists = true;
		}
	}
	if(desExists && sourExists) {
		Edge<T>* edge = new Edge<T>(des,w);
		vertexSet[sourIndex]->adj.push_back(*edge);
		return true;
	}
	return false;
}

template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	Vertex<T>* sour = new Vertex<T>(sourc);
	Vertex<T>* des = new Vertex<T>(dest);
	for (int i = 0; i < vertexSet.size(); i++) {
		for (int j = 0; j < vertexSet[i]->adj.size(); j++) {
			if(vertexSet[i]->adj[j].dest->info == des->info) {
				vertexSet[i]->adj.erase(vertexSet[i]->adj.begin() + j);
				return true;
			}
		}
	}
	return false;
}
#endif /* GRAPH_H_ */
