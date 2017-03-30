/*
 * main.cpp
 *
 *  Created on: 30/03/2017
 *      Author: João Tomé Saraiva
 */

#include <iostream>
#include "Graph.h"
#include "Bus.h"

Graph<int> CreateTestGraph()
{
	Graph<int> myGraph;

	myGraph.addVertex(1,100,1);
	myGraph.addVertex(1,321,213);
	myGraph.addVertex(1,232,542);
	myGraph.addVertex(1,150,643);
	myGraph.addVertex(1,200,450);
	myGraph.addVertex(1,300,200);
	myGraph.addVertex(7,500,100);

	myGraph.addEdge(1, 2, 20);
	myGraph.addEdge(1, 4, 70);
	myGraph.addEdge(2, 4, 30);
	myGraph.addEdge(2, 5, 50);
	myGraph.addEdge(3, 1, 20);
	myGraph.addEdge(3, 6, 50);
	myGraph.addEdge(4, 3, 10);
	myGraph.addEdge(4, 5, 10);
	myGraph.addEdge(4, 6, 60);
	myGraph.addEdge(4, 7, 40);
	myGraph.addEdge(5, 7, 20);
	myGraph.addEdge(6, 4, 30);
	myGraph.addEdge(7, 6, 40);

	return myGraph;
}


int main() {
	Graph<int> myGraph = CreateTestGraph();
	cout << "Id automovel %battery consume %/km?" << endl;
	int id,battery,consume;
	vector<Automovel> a;
	cin >> id >> battery >> consume;
	a.push_back(*new Automovel(id,battery,consume));
	cout << a[0].getBattery() << " " << a[0].getId() << " " << a[0].getConsume()<<endl;
	cout << "Ponto inicial e Ponto final?" << endl;
	int pf,pi;
	cin >> pi >> pf;
	myGraph.dijkstraShortestPath(pi);
	myGraph.getPath(pi,pf,a[0]);
	return 0;
}
