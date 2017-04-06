/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include "RefuelStation.h"
#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <climits>
#include <cmath>
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <fstream>
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "graphviewer.h"

using namespace std;

template<class T> class Edge;
template<class T> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template<class T>
class Vertex {
	T info;
	float x;
	float y;
	float z;
	vector<Edge<T> > adj;
	bool visited;
	bool processing;
	int indegree;
	int dist;
	bool known;
	bool isRefuelStation;
	int stationVelocity;
public:

	Vertex(T in, float i, float j);
	friend class Graph<T> ;

	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);

	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;
	float getX();
	float getY();
	float getZ();
	vector<Edge<T> > getAdj();
	void setIsRefuelStation(bool b);
	bool getIsRefuelStation();
	void setZ(float i);
	void setVisited(bool b);
	bool getVisited();
	Vertex* path;
};

template<class T>
struct vertex_greater_than {
	bool operator()(Vertex<T> * a, Vertex<T> * b) const {
		return a->getDist() > b->getDist();
	}
};

template<class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--; //adicionado do exercicio 5
	typename vector<Edge<T> >::iterator it = adj.begin();
	typename vector<Edge<T> >::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

//atualizado pelo exercício 5
template<class T>
Vertex<T>::Vertex(T in, float i, float j) :
		info(in), x(i), y(j), z(0), isRefuelStation(false), visited(false), stationVelocity(
				0), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w) {
	Edge<T> edgeD(dest, w);
	adj.push_back(edgeD);
}

template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
int Vertex<T>::getDist() const {
	return this->dist;
}

template<class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template<class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

/**
 * Gets the X Position of the Vertex
 * @return x position
 */
template<class T>
float Vertex<T>::getX() {
	return this->x;
}

/**
 * Gets the Y Position of the Vertex
 * @return y position
 */
template<class T>
float Vertex<T>::getY() {
	return this->y;
}

/**
 * Gets the Z Position of the Vertex
 * @return z position
 */
template<class T>
float Vertex<T>::getZ() {
	return this->z;
}

/**
 * Sets the Z Position of the Vertex equal to i
 * @param i new value of the Z
 */
template<class T>
void Vertex<T>::setZ(float i) {
	z = i;
}

/**
 * Gets the Adj Vector of the Vertex
 * @return adj vector
 */
template<class T>
vector<Edge<T> > Vertex<T>::getAdj() {
	return adj;
}

/**
 * Sets the parameter isRefuelStation of Vertex to the value of b
 * @param b new value of the parameter isRefuelStation
 */
template<class T>
void Vertex<T>::setIsRefuelStation(bool b) {
	isRefuelStation = b;
}

/**
 * Gets the parameter isRefuelStation of Vertex
 * @return isRefuelStation
 */
template<class T>
bool Vertex<T>::getIsRefuelStation() {
	return isRefuelStation;
}

/**
 * Sets if the Vertex was visited or not
 * @param b the new value for the visited parameter
 */
template<class T>
void Vertex<T>::setVisited(bool b) {
	visited = b;
}

/**
 * Gets the Visited parameter Vertex
 * @return visited
 */
template<class T>
bool Vertex<T>::getVisited() {
	return visited;
}

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template<class T>
class Edge {
	Vertex<T> * dest;
	double weight;
public:
	Edge(Vertex<T> *d, double w);
	Vertex<T>* getDest();
	double getWeight();

	friend class Graph<T> ;
	friend class Vertex<T> ;
};

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w) :
		dest(d), weight(w) {
}

/**
 * Gets the destiny of the edge
 * @return the destiny Vertex
 */
template<class T>
Vertex<T>* Edge<T>::getDest() {
	return dest;
}

/**
 * Gets the Weight of the edge
 * @return the destiny Vertex
 */
template<class T>
double Edge<T>::getWeight() {
	return weight;
}

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
template<class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, vector<T> &res) const;

	//exercicio 5
	int numCycles;
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();
	void getPathTo(Vertex<T> *origin, list<T> &res);

public:
	bool addVertex(const T &in, float x, float y);
	bool addEdge(const T &sourc, const T &dest);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	vector<Vertex<T> *> getVertexSet() const;
	int getNumVertex() const;

	//exercicio 5
	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();
	vector<Vertex<T>*> getSources() const;
	int getNumCycles();
	vector<T> topologicalOrder();
	vector<T> getPath(const T &origin, const T &dest);
	void unweightedShortestPath(const T &v);
	bool isDAG();
	void bellmanFordShortestPath(const T &s);
	void dijkstraShortestPath(const T &s, Automovel* a);
	void getInitialPath(const T &x, const T &s, Automovel* a,
			vector<RefuelStation> r, GraphViewer *gv);
	void getNearbyStation(const T &x, const T &s, Automovel* a,
			vector<RefuelStation> r, GraphViewer *gv);
	void getFullPath(const T &s, Automovel* a, GraphViewer *gv);
	void checkIsPointAndRefuelStation(vector<RefuelStation> r);
	float calculateConsume(const T &s, const T &x);
	bool existsPoint(const T &s);
	bool existsEdge(const T &s, const T &x);
	int readPontos(string name);
};

template<class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template<class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

template<class T>
int Graph<T>::getNumCycles() {
	numCycles = 0;
	dfsVisit();
	return this->numCycles;
}

template<class T>
bool Graph<T>::isDAG() {
	return (getNumCycles() == 0);
}

template<class T>
bool Graph<T>::addVertex(const T &in, float x, float y) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in)
			return false;
	Vertex<T> *v1 = new Vertex<T>(in, x, y);
	vertexSet.push_back(v1);
	return true;
}

template<class T>
bool Graph<T>::removeVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) {
			Vertex<T> * v = *it;
			vertexSet.erase(it);
			typename vector<Vertex<T>*>::iterator it1 = vertexSet.begin();
			typename vector<Vertex<T>*>::iterator it1e = vertexSet.end();
			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}

			typename vector<Edge<T> >::iterator itAdj = v->adj.begin();
			typename vector<Edge<T> >::iterator itAdje = v->adj.end();
			for (; itAdj != itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vD->indegree++;
	vS->addEdge(vD,
			calculateDist(vD->getX(), vD->getY(), vS->getX(), vS->getY()));

	return true;
}

template<class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;

	vD->indegree--;

	return vS->removeEdgeTo(vD);
}

template<class T>
vector<T> Graph<T>::dfs() const {
	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	vector<T> res;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfs(*it, res);
	return res;
}

template<class T>
void Graph<T>::dfs(Vertex<T> *v, vector<T> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<T> >::iterator it = (v->adj).begin();
	typename vector<Edge<T> >::iterator ite = (v->adj).end();
	for (; it != ite; it++)
		if (it->dest->visited == false) {
			dfs(it->dest, res);
		}
}

template<class T>
vector<T> Graph<T>::bfs(Vertex<T> *v) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename vector<Edge<T> >::iterator it = v1->adj.begin();
		typename vector<Edge<T> >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex<T> *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
			}
		}
	}
	return res;
}

template<class T>
int Graph<T>::maxNewChildren(Vertex<T> *v, T &inf) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	queue<int> level;
	int maxChildren = 0;
	inf = v->info;
	q.push(v);
	level.push(0);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		int l = level.front();
		level.pop();
		l++;
		int nChildren = 0;
		typename vector<Edge<T> >::iterator it = v1->adj.begin();
		typename vector<Edge<T> >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex<T> *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
				level.push(l);
				nChildren++;
			}
		}
		if (nChildren > maxChildren) {
			maxChildren = nChildren;
			inf = v1->info;
		}
	}
	return maxChildren;
}

template<class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v)
			return vertexSet[i];
	return NULL;
}

template<class T>
void Graph<T>::resetIndegrees() {
	//colocar todos os indegree em 0;
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		vertexSet[i]->indegree = 0;

	//actualizar os indegree
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		//percorrer o vector de Edges, e actualizar indegree
		for (unsigned int j = 0; j < vertexSet[i]->adj.size(); j++) {
			vertexSet[i]->adj[j].dest->indegree++;
		}
	}
}

template<class T>
vector<Vertex<T>*> Graph<T>::getSources() const {
	vector<Vertex<T>*> buffer;
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		if (vertexSet[i]->indegree == 0)
			buffer.push_back(vertexSet[i]);
	}
	return buffer;
}

template<class T>
void Graph<T>::dfsVisit() {
	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfsVisit(*it);
}

template<class T>
void Graph<T>::dfsVisit(Vertex<T> *v) {
	v->processing = true;
	v->visited = true;
	typename vector<Edge<T> >::iterator it = (v->adj).begin();
	typename vector<Edge<T> >::iterator ite = (v->adj).end();
	for (; it != ite; it++) {
		if (it->dest->processing == true)
			numCycles++;
		if (it->dest->visited == false) {
			dfsVisit(it->dest);
		}
	}
	v->processing = false;
}

template<class T>
vector<T> Graph<T>::topologicalOrder() {
	//vector com o resultado da ordenacao
	vector<T> res;

	//verificar se é um DAG
	if (getNumCycles() > 0) {
		cout << "Ordenacao Impossivel!" << endl;
		return res;
	}

	//garantir que os "indegree" estao inicializados corretamente
	this->resetIndegrees();

	queue<Vertex<T>*> q;

	vector<Vertex<T>*> sources = getSources();
	while (!sources.empty()) {
		q.push(sources.back());
		sources.pop_back();
	}

	//processar fontes
	while (!q.empty()) {
		Vertex<T>* v = q.front();
		q.pop();

		res.push_back(v->info);

		for (unsigned int i = 0; i < v->adj.size(); i++) {
			v->adj[i].dest->indegree--;
			if (v->adj[i].dest->indegree == 0)
				q.push(v->adj[i].dest);
		}
	}

	//testar se o procedimento foi bem sucedido
	if (res.size() != vertexSet.size()) {
		while (!res.empty())
			res.pop_back();
	}

	//garantir que os "indegree" ficam atualizados ao final
	this->resetIndegrees();

	return res;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) {

	list<T> buffer;
	Vertex<T>* v = getVertex(dest);

	//cout << v->info << " ";
	buffer.push_front(v->info);
	while (v->path != NULL && v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if (v->path != NULL)
		buffer.push_front(v->path->info);

	vector<T> res;
	while (!buffer.empty()) {
		res.push_back(buffer.front());
		buffer.pop_front();
	}
	return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &s) {

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;
	queue<Vertex<T>*> q;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (w->dist == INT_INFINITY) {
				w->dist = v->dist + 1;
				w->path = v;
				q.push(w);
			}
		}
	}
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &s) {
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;
	queue<Vertex<T>*> q;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (w->dist > v->dist + v->adj[i].weight) {
				w->dist = v->dist + v->adj[i].weight;
				w->path = v;
				q.push(w);
			}
		}
	}
}

/**
 * Calculates the shortest path starting in the vertex with info s
 * in the vehicle a (if a Vertex is a Refuel Station with is reduced to the
 * distance of the Vertex 100 / (vehicle consume * station rechargement velocity)
 * @param s initial point info
 * @param a vehicle to be calculated the path
 */
template<class T>
void Graph<T>::dijkstraShortestPath(const T &s, Automovel* a) {
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->known = false;
	}
	Vertex<T>* v = getVertex(s);
	v->dist = 0;
	v->known = true;
	vector<Vertex<T> *> pq;
	pq.push_back(v);
	make_heap(pq.begin(), pq.end(), vertex_greater_than<int>());
	while (!pq.empty()) {
		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();
		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (w->dist > v->dist + v->adj[i].weight) {
				w->dist = v->dist + v->adj[i].weight;
				if (w->isRefuelStation) {
					w->dist -= 100 / (a->getConsume() * w->stationVelocity);
				}
				w->path = v;
				w->known = true;
				pq.push_back(w);
				push_heap(pq.begin(), pq.end(), vertex_greater_than<int>());
			}
		}
	}

}

/**
 * Checks if a vehicle a can go or not to the end with info s without refueling
 * If he can it will be called the function getFullPath
 * If not it will be called the function getNearbyStation
 * @param s info of the destiny vertex
 * @param a vehicle to calculate the distance
 * @param r vector with all Refuel Stations
 */
template<class T>
void Graph<T>::getInitialPath(const T &x, const T &s, Automovel* a, vector<RefuelStation> r, GraphViewer *gv) {
	Vertex<T>* dest = getVertex(s);
	Vertex<T>* start = getVertex(x);
	this->checkIsPointAndRefuelStation(r);
	this->dijkstraShortestPath(x, a);
	cout << "Shortest Distance to arrive to " << s << " without Refueling: "
			<< dest->getDist() << endl;
	if (dest->getDist() == INT_MAX)
		cout << "Impossible to arrive to the end" << endl;
	else {
		if (a->getBattery() <= 0)
			return;
		float consume = a->getConsume();
		float consumePerc = this->calculateConsume(dest->info, start->info);
		a->setConsume(consume * consumePerc);
		if (dest->path != NULL && a->checkDist(dest->dist)) {
			a->setConsume(consume);
			getFullPath(dest->info, a, gv);
		} else if (dest->path != NULL && !a->checkDist(dest->dist)) {
			cout << "To arrive to: " << dest->info << " you need to refuel"
					<< endl;
			a->setConsume(consume);
			this->getNearbyStation(x, s, a, r, gv);
		}
	}
}

/**
 * Prints the full path to the point with info s in the vehicle a and
 * updates the battery level
 * @param s info of the destiny vertex
 * @param a vehicle to calculate the distance
 */
template<class T>
void Graph<T>::getFullPath(const T &s, Automovel* a, GraphViewer *gv) {
	Vertex<T>* dest = getVertex(s);
	vector<Vertex<T>*> path;
	while (dest->path != NULL) {
		path.push_back(dest);
		dest = dest->path;
	}
	if(!dest->isRefuelStation)
		gv->setVertexColor(dest->info,"yellow");
	else
		gv->setVertexColor(dest->info,"GREEN");

	for (int i = path.size() - 1; i > -1; i--) {
		float consume = a->getConsume();
		float consumePerc = this->calculateConsume(path[i]->info,
				path[i]->path->info);
		a->setConsume(consume * consumePerc);
		if (a->checkDist(path[i]->dist - path[i]->path->dist)) {
			if(!path[i]->isRefuelStation)
				gv->setVertexColor(path[i]->info,"yellow");
			else
				gv->setVertexColor(path[i]->info,"GREEN");
			cout << "Distance between " << path[i]->path->info << " and "
					<< path[i]->info << ": "
					<< path[i]->dist - path[i]->path->dist << endl;
			a->setBattery(
					a->getBattery()
							- (a->getConsume()
									* (path[i]->dist - path[i]->path->dist)));
			cout << "Go to: " << path[i]->info
					<< " You arrive with the battery at: " << a->getBattery()
					<< endl;

		} else {
			a->setBattery(
					a->getBattery()
							- (a->getConsume()
									* (path[i]->dist - path[i]->path->dist)));
			cout << "Distance between " << path[i]->path->info << " and "
					<< path[i]->info << ": "
					<< path[i]->dist - path[i]->path->dist << endl;
			cout << "You stop in the way to: " << path[i]->info
					<< " With Battery at: " << a->getBattery() << endl;
			a->setConsume(consume);
			return;
		}
		a->setConsume(consume);
	}
}

/**
 * Gets the nearby Station of the current Vertex that the vehicle a can go
 * After finding the nearby Station it's called the function getFullPath and calculated
 * the shortest path with the function dijkstraShortestPath. Next it calls the function
 * getInitialPath
 * @param s info of the destiny vertex
 * @param a vehicle to calculate the distance
 * @param r vector with all Refuel Stations
 */
template<class T>
void Graph<T>::getNearbyStation(const T &x, const T &s, Automovel* a,
		vector<RefuelStation> r, GraphViewer *gv) {
	Vertex<T>* dest = getVertex(s);
	Vertex<T>* start = getVertex(x);

	int distStation = INT_INFINITY;
	int b;
	int distEnd = INT_INFINITY;
	for (unsigned int i = 0; i < r.size(); i++) {
		if (this->getVertex(r[i].getId())->getDist() < distStation
				&& !r[i].getPassed()
				&& a->checkDist(this->getVertex(r[i].getId())->getDist())) {
			int y = this->getVertex(r[i].getId())->getDist();
			this->dijkstraShortestPath(r[i].getId(), a);
			if (dest->getDist() + y < distEnd) {
				distStation = y;
				distEnd = dest->getDist() + y;
				b = i;
			}
			this->dijkstraShortestPath(x, a);

		}
	}
	if (distStation == INT_INFINITY) {
		cout << "You can´t reach the end at: "
				<< calculateDist(start->getX(), start->getY(), dest->getX(),
						dest->getY()) << endl;
		this->getFullPath(dest->getInfo(), a, gv);
		return;
	}
	cout << "Pass by Refuel Station: " << r[b].getId()
			<< " You need to travel: " << distStation << endl;
	r[b].setPassed(true);
	this->getFullPath(r[b].getId(), a, gv);
	if (a->getBattery() <= 0)
		return;
	a->setBattery(100);
	this->getInitialPath(r[b].getId(), s, a, r,gv);

}

/**
 * For all Refuel Station changes the value of stationVelocity the correspondent Vertex
 * to 50 or 40 or 30 depending the value of the Station Rechargement Velocity
 * @param r vector with all the Refuel Stations
 */
template<class T>
void Graph<T>::checkIsPointAndRefuelStation(vector<RefuelStation> r) {
	for (unsigned int i = 0; i < r.size(); i++) {
		if (r[i].getVelocity() == 1)
			this->getVertex(r[i].getId())->stationVelocity = 50;
		if (r[i].getVelocity() == 2)
			this->getVertex(r[i].getId())->stationVelocity = 40;
		if (r[i].getVelocity() == 3)
			this->getVertex(r[i].getId())->stationVelocity = 30;

	}
}

/**
 * Calculates the consume depending the difference of the altitude of two Vertexs
 * @param s info of the destiny vertex
 * @param x info of the start vertex
 * @return 1.5 if the difference is positive or -1.5 if the difference is negative
 */
template<class T>
float Graph<T>::calculateConsume(const T &s, const T &x) {
	Vertex<T>* dest = getVertex(s);
	Vertex<T>* start = getVertex(x);

	int diff = calculateDif(dest->getZ(), start->getZ());
	if (diff > 0)
		return 1.5;
	else if (diff < 0)
		return -1.5;
	else
		return 1;
}

/**
 * Checks if a point as the info s
 * @param s the info to check
 * @return true if exists or false if doesn't exist
 */
template<class T>
bool Graph<T>::existsPoint(const T &s) {
	vector<Vertex<T>*> vs = this->getVertexSet();
	for (unsigned int i = 0; i < vs.size(); i++) {
		if (s == vs[i]->getInfo())
			return true;
	}
	return false;
}

/**
 * Checks if exists a edge between the points with info s and info x
 * @param s the info of vertex 1
 * @param x the info of vertex 2
 * @return true if exists or false if doesn't exist
 */
template<class T>
bool Graph<T>::existsEdge(const T &s, const T &x) {
	Vertex<T>* aux = getVertex(s);
	for (unsigned int i = 0; i < aux->adj.size(); i++) {
		if (x == aux->adj[i].dest->getInfo())
			return true;
	}
	return false;
}

#endif /* GRAPH_H_ */
