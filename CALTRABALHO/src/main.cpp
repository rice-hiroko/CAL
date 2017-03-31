/*
 * main.cpp
 *
 *  Created on: 24/03/2017
 *      Author: João Tomé Saraiva
 */

#include "utils.h"
#include "Graph.h"
#include <sstream>
#include <iostream>
#include "Vehicle.h"

using namespace std;


Graph<int> CreateTestGraph()
{
	Graph<int> myGraph;

	myGraph.addVertex(1,1,1,1);
	myGraph.addVertex(2,1000,2453,1231);
	myGraph.addVertex(3,12038,231,353);
	myGraph.addVertex(4,1232,3243,876);
	myGraph.addVertex(5,3421,2356,012);
	myGraph.addVertex(6,132,1324,985);
	myGraph.addVertex(7,292,1324,812);
	myGraph.addVertex(8,6598,3716,921);
	myGraph.addVertex(9,143,987,687);
	myGraph.addVertex(10,8652,2343,543);


	// distancias em kms
	myGraph.addEdge(1, 2, calculateDist(myGraph.getVertex(1)->getX() - myGraph.getVertex(2)->getX(), myGraph.getVertex(1)->getY() - myGraph.getVertex(2)->getY()));
	myGraph.addEdge(1, 3, calculateDist(myGraph.getVertex(1)->getX() - myGraph.getVertex(3)->getX(), myGraph.getVertex(1)->getY() - myGraph.getVertex(3)->getY()));
	myGraph.addEdge(1, 7, calculateDist(myGraph.getVertex(1)->getX() - myGraph.getVertex(7)->getX(), myGraph.getVertex(1)->getY() - myGraph.getVertex(7)->getY()));
	myGraph.addEdge(2, 4, calculateDist(myGraph.getVertex(2)->getX() - myGraph.getVertex(4)->getX(), myGraph.getVertex(2)->getY() - myGraph.getVertex(4)->getY()));
	myGraph.addEdge(3, 8, calculateDist(myGraph.getVertex(3)->getX() - myGraph.getVertex(8)->getX(), myGraph.getVertex(3)->getY() - myGraph.getVertex(8)->getY()));
	myGraph.addEdge(4, 6, calculateDist(myGraph.getVertex(4)->getX() - myGraph.getVertex(6)->getX(), myGraph.getVertex(4)->getY() - myGraph.getVertex(6)->getY()));
	myGraph.addEdge(4, 5, calculateDist(myGraph.getVertex(4)->getX() - myGraph.getVertex(5)->getX(), myGraph.getVertex(4)->getY() - myGraph.getVertex(5)->getY()));
	myGraph.addEdge(5, 10, calculateDist(myGraph.getVertex(5)->getX() - myGraph.getVertex(10)->getX(), myGraph.getVertex(5)->getY() - myGraph.getVertex(10)->getY()));
	myGraph.addEdge(7, 6, calculateDist(myGraph.getVertex(7)->getX() - myGraph.getVertex(6)->getX(), myGraph.getVertex(7)->getY() - myGraph.getVertex(6)->getY()));
	myGraph.addEdge(8, 9, calculateDist(myGraph.getVertex(9)->getX() - myGraph.getVertex(8)->getX(), myGraph.getVertex(9)->getY() - myGraph.getVertex(8)->getY()));
	myGraph.addEdge(9, 5, calculateDist(myGraph.getVertex(9)->getX() - myGraph.getVertex(5)->getX(), myGraph.getVertex(9)->getY() - myGraph.getVertex(5)->getY()));
	myGraph.addEdge(2, 1, calculateDist(myGraph.getVertex(1)->getX() - myGraph.getVertex(2)->getX(), myGraph.getVertex(1)->getY() - myGraph.getVertex(2)->getY()));
	myGraph.addEdge(3, 1, calculateDist(myGraph.getVertex(1)->getX() - myGraph.getVertex(3)->getX(), myGraph.getVertex(1)->getY() - myGraph.getVertex(3)->getY()));
	myGraph.addEdge(7, 1, calculateDist(myGraph.getVertex(1)->getX() - myGraph.getVertex(7)->getX(), myGraph.getVertex(1)->getY() - myGraph.getVertex(7)->getY()));
	myGraph.addEdge(4, 2, calculateDist(myGraph.getVertex(2)->getX() - myGraph.getVertex(4)->getX(), myGraph.getVertex(2)->getY() - myGraph.getVertex(4)->getY()));
	myGraph.addEdge(8, 3, calculateDist(myGraph.getVertex(3)->getX() - myGraph.getVertex(8)->getX(), myGraph.getVertex(3)->getY() - myGraph.getVertex(8)->getY()));
	myGraph.addEdge(6, 4, calculateDist(myGraph.getVertex(4)->getX() - myGraph.getVertex(6)->getX(), myGraph.getVertex(4)->getY() - myGraph.getVertex(6)->getY()));
	myGraph.addEdge(5, 4, calculateDist(myGraph.getVertex(4)->getX() - myGraph.getVertex(5)->getX(), myGraph.getVertex(4)->getY() - myGraph.getVertex(5)->getY()));
	myGraph.addEdge(10, 5, calculateDist(myGraph.getVertex(5)->getX() - myGraph.getVertex(10)->getX(), myGraph.getVertex(5)->getY() - myGraph.getVertex(10)->getY()));
	myGraph.addEdge(6, 7, calculateDist(myGraph.getVertex(7)->getX() - myGraph.getVertex(6)->getX(), myGraph.getVertex(7)->getY() - myGraph.getVertex(6)->getY()));
	myGraph.addEdge(9, 8, calculateDist(myGraph.getVertex(9)->getX() - myGraph.getVertex(8)->getX(), myGraph.getVertex(9)->getY() - myGraph.getVertex(8)->getY()));
	myGraph.addEdge(5, 9, calculateDist(myGraph.getVertex(9)->getX() - myGraph.getVertex(5)->getX(), myGraph.getVertex(9)->getY() - myGraph.getVertex(5)->getY()));
	myGraph.addEdge(9, 10, calculateDist(myGraph.getVertex(9)->getX() - myGraph.getVertex(10)->getX(), myGraph.getVertex(9)->getY() - myGraph.getVertex(10)->getY()));


	return myGraph;
}

int main() {
	Graph<int> myGraph = CreateTestGraph();
	bool quit = false;
	int i = 0;
	vector<Automovel> a;
	vector<RefuelStation> r;
	while(!quit) {
		cout << "0 - quit | 1 - add Vehicle | 2 - Add Refuel Station | 3 - Add Point | 4 - Add Edge | 5 - Calculate Shortest Distance Between two points in vehicle A" << endl;
		cin >> i;
		if (i == 0) {
			quit = true;
		}
		else if (i == 1) {
			int id;
			float battery, consume;
			cout << "Id of the Vehicle %of the battery and %/km";
			cin >> id >> battery >> consume;
			a.push_back(*new Automovel(id,battery,consume));
			cout << a.back().getId() << " " << a.back().getConsume() << " " << a.back().getBattery() << endl;
		}
		else if (i == 2) {
			int id,velocidade,x,y,z;
			cout << "Id of the Refuel Station x y z Recharge Velocity";
			cin >> id >> x >> y >> z >> velocidade;
			r.push_back(*new RefuelStation(id,velocidade,x,y,z));
			cout << r.back().getId() << " " << r.back().getVelocity() << endl;
		}
		else if (i == 3) {
			int id,x,y,z;
			cout << "Id x and y and z" << endl;
			cin >> id >> x >> y >> z;
			myGraph.addVertex(id,x,y,z);
		}
		else if (i == 4) {
			int id,id2,dist;
			cout << "Id P1 Id P2 and distance" << endl;
			cin >> id >> id2 >> dist;
			myGraph.addEdge(id,id2,dist);
		}
		else if (i ==5) {
			if(a.size() == 0)
				cout << "No Vehicles avaiable" << endl;
			if(r.size() == 0)
				cout << "No Refuel Stations avaiable" << endl;
			else if (a.size() != 0) {
				int start, end, vehicleid;
				cout << "Start point and end point and vehicle id" << endl;
				cin >> start >> end >> vehicleid;
				unsigned int j;
				for (j = 0; j < a.size(); j++) {
					if (a[j].getId() == vehicleid)
						break;
				}
				if (a[j].getId() != vehicleid) {
					cout << "There is no vehicle with id = " << vehicleid
							<< endl;
				} else {
					vector<Vertex<int>*> vs = myGraph.getVertexSet();
					myGraph.checkIsPointAndRefuelStation(vs, r);
					myGraph.dijkstraShortestPath(start, &a[j]);
					vs = myGraph.getVertexSet();
					cout << a[j].getBattery() << endl;
					cout << myGraph.getVertex(end)->getDist() << endl;
					myGraph.getInitialPath(vs, end, &a[j],r);
					cout << a[j].getBattery() << endl;
				}
			}
		}
		else if(i == 6) {
			cout << "Print Vehicles" << endl;
		}
		else if(i == 7) {
			cout << "Print Refuel Stations" << endl;
		}
	}
}

