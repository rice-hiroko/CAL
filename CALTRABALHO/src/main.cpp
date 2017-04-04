/*
 * main.cpp
 *
 *  Created on: 24/03/2017
 *      Author: João Tomé Saraiva
 */

#include "utils.h"
#include "Graph.h"
#include "Vehicle.h"
#include <cstdio>
#include "graphviewer.h"

using namespace std;


Graph<int> CreateTestGraph()
{
	Graph<int> myGraph;

	myGraph.addVertex(1,1,1,0);
	myGraph.addVertex(2,1000,2453,0);
	myGraph.addVertex(3,12038,231,0);
	myGraph.addVertex(4,1232,3243,0);
	myGraph.addVertex(5,3421,2356,0);
	myGraph.addVertex(6,132,1324,0);
	myGraph.addVertex(7,292,1324,0);
	myGraph.addVertex(8,6598,3716,0);
	myGraph.addVertex(9,143,987,0);
	myGraph.addVertex(10,8652,2343,0);


	// distancias em kms
	myGraph.addEdge(1, 2);
	myGraph.addEdge(1, 3);
	myGraph.addEdge(1, 7);
	myGraph.addEdge(2, 4);
	myGraph.addEdge(3, 8);
	myGraph.addEdge(4, 6);
	myGraph.addEdge(4, 5);
	myGraph.addEdge(5, 10);
	myGraph.addEdge(7, 6);
	myGraph.addEdge(8, 9);
	myGraph.addEdge(9, 5);
	myGraph.addEdge(2, 1);
	myGraph.addEdge(3, 1);
	myGraph.addEdge(7, 1);
	myGraph.addEdge(4, 2);
	myGraph.addEdge(8, 3);
	myGraph.addEdge(6, 4);
	myGraph.addEdge(5, 4);
	myGraph.addEdge(10, 5);
	myGraph.addEdge(6, 7);
	myGraph.addEdge(9, 8);
	myGraph.addEdge(5, 9);
	myGraph.addEdge(9, 10);


	return myGraph;
}

//alterei
int main() {
	Graph<int> myGraph;

	if(myGraph.readPontos("Pontos.txt") == -1) {
		cout << "Error Reading Pontos.txt" << endl;
	}


	bool quit = false;
	int i = 0;
	vector<Automovel> a;
	vector<RefuelStation> r;
	while(!quit) {
		cout << "0 - quit | 1 - add Vehicle | 2 - Add Refuel Station | 3 - Add Point | 4 - Add Edge " << endl << " 5 - Calculate Shortest Distance Between two points in vehicle A | 6 - List Vehicle | 7 - List Refuel Stations | 8 - GraphViewer" << endl;
		cin >> i;
		if (i == 0) {
			quit = true;
		}
		else if (i == 1) {
			bool add = true;
			int id;
			float battery, consume;
			cout << "Id of the Vehicle %of the battery and %/km";
			cin >> id >> battery >> consume;
			for(unsigned int j = 0; j < a.size(); j++) {
				if (a[j].getId() == id) {
					cout << "Vehicle  already exists" << endl;
					add = false;
				}
			}
			if (battery > 100 || battery < 0) {
				cout << "Battery must be a value between 100 and 0" << endl;
				add =false;
			}
			if (consume < 0) {
				cout << "The consume of a vehicle must be positive" << endl;
				add = false;
			}
			if (add) {
				a.push_back(*new Automovel(id,battery,consume));
				cout << a.back().getId() << " " << a.back().getConsume() << " " << a.back().getBattery() << endl;
			}
		}
		else if (i == 2) {
			bool add = true;
			int id,velocity,z;
			cout << "Id of the Refuel Station Rechargement Velocity and Altitude";
			cin >> id >> velocity >> z;
			for(unsigned int j = 0; j < r.size(); j++) {
				if (r[j].getId() == id) {
					cout << "Refuel Station already exists" << endl;
					add = false;
				}
			}
			if (velocity != 1 && velocity != 2 && velocity != 3) {
				cout << "Velocity must be 1 2 or 3" << endl;
				add = false;
			}
			if (add) {
				r.push_back(*new RefuelStation(id,velocity));
				myGraph.getVertex(id)->setIsRefuelStation(true);
				myGraph.getVertex(id)->setZ(z);
				cout << r.back().getId() << " " << r.back().getVelocity() << endl;
			}
		}
		else if (i == 3) {
			int id,x,y,z;
			cout << "Id x and y and z" << endl;
			cin >> id >> x >> y >> z;
			if(myGraph.existsPoint(id)) {
				cout << "Point already exists" << endl;
			}
			else {
				myGraph.addVertex(id,x,y,z);
			}
		}
		else if (i == 4) {
			int id,id2;
			bool add = true;
			cout << "Id P1 Id P2" << endl;
			cin >> id >> id2;
			if(!myGraph.existsPoint(id) || !myGraph.existsPoint(id2)) {
				cout << "One Point doesn´t exist" << endl;
				add = false;
			}
			else if(myGraph.existsEdge(id,id2)) {
				cout << "Edge already exists" << endl;
				add = false;
			}
			if (add) {
				myGraph.addEdge(id,id2);
			}
		}
		else if (i ==5) {
			if(a.size() == 0)
				cout << "No Vehicles available" << endl;
			if(r.size() == 0)
				cout << "No Refuel Stations available" << endl;
			else if (a.size() != 0) {
				int start, end, vehicleid;
				cout << "Start point and end point and vehicle id" << endl;
				cin >> start >> end >> vehicleid;
				unsigned int j;
				for (j = 0; j < a.size(); j++) {
					if (a[j].getId() == vehicleid)
						break;
				}
				if (!myGraph.existsPoint(start))
					cout << "Doens't exists the point " << start << endl;
				if (!myGraph.existsPoint(end))
					cout << "Doens't exists the point " << end << endl;
				if (a[j].getId() != vehicleid) {
					cout << "There is no vehicle with id = " << vehicleid
							<< endl;
				} else if (myGraph.existsPoint(start) && myGraph.existsPoint(end)){
					myGraph.checkIsPointAndRefuelStation(r);


					myGraph.dijkstraShortestPath(start, &a[j]);
					cout << "Shortest Distance to arrive without Refueling: " << myGraph.getVertex(end)->getDist() << endl;
					myGraph.getInitialPath(end, &a[j],r);
					for(unsigned int k = 0; k < r.size(); k++) {
						r[k].setPassed(false);
					}
				}
			}
		}
		else if(i == 6) {
			if(a.size() == 0)
				cout << "No Vehicles available" << endl;
			else {
				cout << "Vehicle ID              BATTERY           CONSUME" << endl;
				for(unsigned int j = 0; j < a.size(); j++) {
					cout << a[j].getId() << "                       " << a[j].getBattery() << "               " << a[j].getConsume() << endl;
				}
			}
		}
		else if(i == 7) {
			if(r.size() == 0)
				cout << "No Refuel Stations available" << endl;
			else {
				cout << "Refuel Station ID         X               Y             Z              Velocity" << endl;
				for(unsigned int j = 0; j < r.size(); j++) {
					cout << r[j].getId() << "                         " << myGraph.getVertex(r[j].getId())->getX() << "               " << myGraph.getVertex(r[j].getId())->getY() << "             " << myGraph.getVertex(r[j].getId())->getZ() << "              " << r[j].getVelocity() << endl;
				}
			}
		}
		else if (i == 8) {
//			vector<Vertex<int>*> vs = myGraph.getVertexSet();
//			GraphViewer *gv = new GraphViewer(600, 600, false);
//			gv->createWindow(600, 600);
//			gv->defineVertexColor("blue");
//			gv->defineEdgeColor("black");
//			for(unsigned int j = 0; j < vs.size(); j++) {
//				gv->addNode(vs[j]->getInfo(),vs[j]->getX(),vs[j]->getY());
//			}
//			for(unsigned int j = 0; j < vs.size(); j++) {
//				for(unsigned int k = 0; k < vs[j]->getAdj().size(); k++) {
//					gv->addEdge(vs[j]->getInfo(),vs[j]->getAdj()[k].getDest()->getInfo(),vs[j]->getAdj()[k].getDest()->getDist(),EdgeType::UNDIRECTED);
//				}
//			}
		}
	}
}

