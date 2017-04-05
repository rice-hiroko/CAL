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
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Creates a Graph with 10 Vertexs
 * @return the created graph
 */
Graph<int> CreateShortGraph()
{
	Graph<int> myGraph;

	myGraph.addVertex(1,1,1);
	myGraph.addVertex(2,658,453);
	myGraph.addVertex(3,128,231);
	myGraph.addVertex(4,232,323);
	myGraph.addVertex(5,342,256);
	myGraph.addVertex(6,132,124);
	myGraph.addVertex(7,292,131);
	myGraph.addVertex(8,659,116);
	myGraph.addVertex(9,143,387);
	myGraph.addVertex(10,680,243);

	myGraph.addEdge(1, 3);
	myGraph.addEdge(1, 6);
	myGraph.addEdge(1, 7);
	myGraph.addEdge(1, 8);
	myGraph.addEdge(6, 3);
	myGraph.addEdge(6, 7);
	myGraph.addEdge(6, 4);
	myGraph.addEdge(6, 5);
	myGraph.addEdge(3, 1);
	myGraph.addEdge(3, 6);
	myGraph.addEdge(6, 1);
	myGraph.addEdge(3, 4);
	myGraph.addEdge(3, 5);
	myGraph.addEdge(3, 9);
	myGraph.addEdge(7, 1);
	myGraph.addEdge(7, 6);
	myGraph.addEdge(7, 5);
	myGraph.addEdge(7, 8);
	myGraph.addEdge(7, 4);
	myGraph.addEdge(9, 3);
	myGraph.addEdge(9, 4);
	myGraph.addEdge(4, 9);
	myGraph.addEdge(4, 6);
	myGraph.addEdge(4, 3);
	myGraph.addEdge(4, 7);
	myGraph.addEdge(4, 5);
	myGraph.addEdge(5, 4);
	myGraph.addEdge(5, 3);
	myGraph.addEdge(5, 6);
	myGraph.addEdge(5, 8);
	myGraph.addEdge(5, 7);
	myGraph.addEdge(5, 10);
	myGraph.addEdge(8, 7);
	myGraph.addEdge(8, 10);
	myGraph.addEdge(8, 5);
	myGraph.addEdge(4, 2);
	myGraph.addEdge(5, 2);
	myGraph.addEdge(9, 2);
	myGraph.addEdge(10, 2);
	myGraph.addEdge(10, 8);
	myGraph.addEdge(10, 5);
	myGraph.addEdge(2, 4);
	myGraph.addEdge(2, 5);
	myGraph.addEdge(2, 10);

	return myGraph;
}

/**
 * Creates a Graph with 25 Vertexs
 * @return the created graph
 */
Graph<int> CreateMediumGraph()
{
	Graph<int> myGraph;

	myGraph.addVertex(1,1,1);
	myGraph.addVertex(2,658,453);
	myGraph.addVertex(3,128,231);
	myGraph.addVertex(4,232,323);
	myGraph.addVertex(5,342,256);
	myGraph.addVertex(6,132,124);
	myGraph.addVertex(7,292,131);
	myGraph.addVertex(8,659,116);
	myGraph.addVertex(9,143,387);
	myGraph.addVertex(10,680,243);

	myGraph.addVertex(11,9,330);
	myGraph.addVertex(12,132,433);
	myGraph.addVertex(13,243,540);
	myGraph.addVertex(14,734,23);
	myGraph.addVertex(15,314,16);
	myGraph.addVertex(16,432,543);
	myGraph.addVertex(17,672,623);
	myGraph.addVertex(18,687,544);
	myGraph.addVertex(19,465,687);
	myGraph.addVertex(20,536,234);
	myGraph.addVertex(21,753,243);
	myGraph.addVertex(22,633,243);
	myGraph.addVertex(23,143,642);
	myGraph.addVertex(24,432,243);
	myGraph.addVertex(25,257,243);


	myGraph.addEdge(1, 3);
	myGraph.addEdge(1, 6);
	myGraph.addEdge(1, 7);
	myGraph.addEdge(6, 3);
	myGraph.addEdge(6, 7);
	myGraph.addEdge(3, 1);
	myGraph.addEdge(3, 6);
	myGraph.addEdge(6, 1);
	myGraph.addEdge(3, 4);
	myGraph.addEdge(3, 9);
	myGraph.addEdge(7, 1);
	myGraph.addEdge(7, 6);
	myGraph.addEdge(7, 5);
	myGraph.addEdge(7, 8);
	myGraph.addEdge(7, 25);
	myGraph.addEdge(5, 25);
	myGraph.addEdge(25, 5);
	myGraph.addEdge(9, 3);
	myGraph.addEdge(9, 4);
	myGraph.addEdge(4, 9);
	myGraph.addEdge(25, 4);
	myGraph.addEdge(25, 7);
	myGraph.addEdge(4, 3);
	myGraph.addEdge(4, 25);
	myGraph.addEdge(4, 5);
	myGraph.addEdge(5, 4);
	myGraph.addEdge(25, 3);
	myGraph.addEdge(3, 25);
	myGraph.addEdge(25, 6);
	myGraph.addEdge(6, 25);

	myGraph.addEdge(20, 22);
	myGraph.addEdge(20, 2);
	myGraph.addEdge(2, 20);
	myGraph.addEdge(22, 8);
	myGraph.addEdge(8, 22);
	myGraph.addEdge(22, 20);
	myGraph.addEdge(20, 24);
	myGraph.addEdge(24, 20);
	myGraph.addEdge(5, 7);
	myGraph.addEdge(5, 24);
	myGraph.addEdge(24, 5);
	myGraph.addEdge(8, 7);
	myGraph.addEdge(8, 10);
	myGraph.addEdge(8, 20);
	myGraph.addEdge(20, 8);
	myGraph.addEdge(4, 2);
	myGraph.addEdge(24, 2);
	myGraph.addEdge(9, 2);
	myGraph.addEdge(10, 2);
	myGraph.addEdge(10, 8);
	myGraph.addEdge(10, 22);
	myGraph.addEdge(22, 10);
	myGraph.addEdge(2, 4);
	myGraph.addEdge(2, 24);
	myGraph.addEdge(2, 10);
	myGraph.addEdge(1, 11);
	myGraph.addEdge(3, 11);
	myGraph.addEdge(9, 11);
	myGraph.addEdge(12, 11);
	myGraph.addEdge(11, 1);
	myGraph.addEdge(11, 3);
	myGraph.addEdge(11, 9);
	myGraph.addEdge(11, 12);
	myGraph.addEdge(12, 9);
	myGraph.addEdge(9, 12);
	myGraph.addEdge(12, 13);
	myGraph.addEdge(13, 12);
	myGraph.addEdge(9, 13);
	myGraph.addEdge(13, 9);
	myGraph.addEdge(4, 13);
	myGraph.addEdge(13, 4);
	myGraph.addEdge(21, 10);
	myGraph.addEdge(10, 21);
	myGraph.addEdge(21, 8);
	myGraph.addEdge(8, 21);
	myGraph.addEdge(21, 2);
	myGraph.addEdge(2, 21);
	myGraph.addEdge(21, 18);
	myGraph.addEdge(18, 2);
	myGraph.addEdge(2, 18);
	myGraph.addEdge(18, 17);
	myGraph.addEdge(17, 18);
	myGraph.addEdge(18, 16);
	myGraph.addEdge(16, 18);
	myGraph.addEdge(19, 17);
	myGraph.addEdge(17, 19);
	myGraph.addEdge(19, 16);
	myGraph.addEdge(16, 19);
	myGraph.addEdge(4, 16);
	myGraph.addEdge(16, 4);
	myGraph.addEdge(5, 16);
	myGraph.addEdge(16, 5);
	myGraph.addEdge(24, 16);
	myGraph.addEdge(16, 24);
	myGraph.addEdge(13, 16);
	myGraph.addEdge(16, 13);
	myGraph.addEdge(13, 23);
	myGraph.addEdge(23, 13);
	myGraph.addEdge(19, 23);
	myGraph.addEdge(23, 19);
	myGraph.addEdge(13, 5);
	myGraph.addEdge(5, 13);
	myGraph.addEdge(12, 23);
	myGraph.addEdge(23, 12);
	myGraph.addEdge(11, 23);
	myGraph.addEdge(23, 11);
	myGraph.addEdge(16, 23);
	myGraph.addEdge(23, 16);
	myGraph.addEdge(16, 17);
	myGraph.addEdge(17, 16);
	myGraph.addEdge(19, 18);
	myGraph.addEdge(18, 19);
	myGraph.addEdge(19, 2);
	myGraph.addEdge(2, 19);
	myGraph.addEdge(22, 2);
	myGraph.addEdge(2, 22);
	myGraph.addEdge(24, 7);
	myGraph.addEdge(7, 24);
	myGraph.addEdge(20, 7);
	myGraph.addEdge(7, 20);
	myGraph.addEdge(15, 1);
	myGraph.addEdge(1, 15);
	myGraph.addEdge(15, 6);
	myGraph.addEdge(6, 15);
	myGraph.addEdge(15, 7);
	myGraph.addEdge(7, 15);
	myGraph.addEdge(15, 24);
	myGraph.addEdge(24, 15);
	myGraph.addEdge(15, 20);
	myGraph.addEdge(20, 15);
	myGraph.addEdge(15, 8);
	myGraph.addEdge(8, 15);
	myGraph.addEdge(15, 14);
	myGraph.addEdge(14, 15);
	myGraph.addEdge(8, 14);
	myGraph.addEdge(14, 8);
	myGraph.addEdge(21, 14);
	myGraph.addEdge(14, 21);
	myGraph.addEdge(16, 2);
	myGraph.addEdge(2, 16);
	myGraph.addEdge(16, 20);
	myGraph.addEdge(20, 16);

	return myGraph;
}

Graph<int> CreateLargeGraph()
{
	Graph<int> myGraph;

	myGraph.addVertex(1,1,1);
	myGraph.addVertex(2,658,453);
	myGraph.addVertex(3,128,231);
	myGraph.addVertex(4,232,323);
	myGraph.addVertex(5,342,256);
	myGraph.addVertex(6,132,124);
	myGraph.addVertex(7,292,131);
	myGraph.addVertex(8,659,116);
	myGraph.addVertex(9,143,387);
	myGraph.addVertex(10,680,243);

	myGraph.addVertex(11,9,330);
	myGraph.addVertex(12,132,433);
	myGraph.addVertex(13,243,540);
	myGraph.addVertex(14,734,23);
	myGraph.addVertex(15,314,16);
	myGraph.addVertex(16,432,543);
	myGraph.addVertex(17,672,623);
	myGraph.addVertex(18,687,544);
	myGraph.addVertex(19,465,687);
	myGraph.addVertex(20,536,234);
	myGraph.addVertex(21,753,243);
	myGraph.addVertex(22,633,243);
	myGraph.addVertex(23,143,642);
	myGraph.addVertex(24,432,243);
	myGraph.addVertex(25,257,243);


	myGraph.addEdge(1, 3);
	myGraph.addEdge(1, 6);
	myGraph.addEdge(1, 7);
	myGraph.addEdge(6, 3);
	myGraph.addEdge(6, 7);
	myGraph.addEdge(3, 1);
	myGraph.addEdge(3, 6);
	myGraph.addEdge(6, 1);
	myGraph.addEdge(3, 4);
	myGraph.addEdge(3, 9);
	myGraph.addEdge(7, 1);
	myGraph.addEdge(7, 6);
	myGraph.addEdge(7, 5);
	myGraph.addEdge(7, 8);
	myGraph.addEdge(7, 25);
	myGraph.addEdge(5, 25);
	myGraph.addEdge(25, 5);
	myGraph.addEdge(9, 3);
	myGraph.addEdge(9, 4);
	myGraph.addEdge(4, 9);
	myGraph.addEdge(25, 4);
	myGraph.addEdge(25, 7);
	myGraph.addEdge(4, 3);
	myGraph.addEdge(4, 25);
	myGraph.addEdge(4, 5);
	myGraph.addEdge(5, 4);
	myGraph.addEdge(25, 3);
	myGraph.addEdge(3, 25);
	myGraph.addEdge(25, 6);
	myGraph.addEdge(6, 25);

	myGraph.addEdge(20, 22);
	myGraph.addEdge(20, 2);
	myGraph.addEdge(2, 20);
	myGraph.addEdge(22, 8);
	myGraph.addEdge(8, 22);
	myGraph.addEdge(22, 20);
	myGraph.addEdge(20, 24);
	myGraph.addEdge(24, 20);
	myGraph.addEdge(5, 7);
	myGraph.addEdge(5, 24);
	myGraph.addEdge(24, 5);
	myGraph.addEdge(8, 7);
	myGraph.addEdge(8, 10);
	myGraph.addEdge(8, 20);
	myGraph.addEdge(20, 8);
	myGraph.addEdge(4, 2);
	myGraph.addEdge(24, 2);
	myGraph.addEdge(9, 2);
	myGraph.addEdge(10, 2);
	myGraph.addEdge(10, 8);
	myGraph.addEdge(10, 22);
	myGraph.addEdge(22, 10);
	myGraph.addEdge(2, 4);
	myGraph.addEdge(2, 24);
	myGraph.addEdge(2, 10);
	myGraph.addEdge(1, 11);
	myGraph.addEdge(3, 11);
	myGraph.addEdge(9, 11);
	myGraph.addEdge(12, 11);
	myGraph.addEdge(11, 1);
	myGraph.addEdge(11, 3);
	myGraph.addEdge(11, 9);
	myGraph.addEdge(11, 12);
	myGraph.addEdge(12, 9);
	myGraph.addEdge(9, 12);
	myGraph.addEdge(12, 13);
	myGraph.addEdge(13, 12);
	myGraph.addEdge(9, 13);
	myGraph.addEdge(13, 9);
	myGraph.addEdge(4, 13);
	myGraph.addEdge(13, 4);
	myGraph.addEdge(21, 10);
	myGraph.addEdge(10, 21);
	myGraph.addEdge(21, 8);
	myGraph.addEdge(8, 21);
	myGraph.addEdge(21, 2);
	myGraph.addEdge(2, 21);
	myGraph.addEdge(21, 18);
	myGraph.addEdge(18, 2);
	myGraph.addEdge(2, 18);
	myGraph.addEdge(18, 17);
	myGraph.addEdge(17, 18);
	myGraph.addEdge(18, 16);
	myGraph.addEdge(16, 18);
	myGraph.addEdge(19, 17);
	myGraph.addEdge(17, 19);
	myGraph.addEdge(19, 16);
	myGraph.addEdge(16, 19);
	myGraph.addEdge(4, 16);
	myGraph.addEdge(16, 4);
	myGraph.addEdge(5, 16);
	myGraph.addEdge(16, 5);
	myGraph.addEdge(24, 16);
	myGraph.addEdge(16, 24);
	myGraph.addEdge(13, 16);
	myGraph.addEdge(16, 13);
	myGraph.addEdge(13, 23);
	myGraph.addEdge(23, 13);
	myGraph.addEdge(19, 23);
	myGraph.addEdge(23, 19);
	myGraph.addEdge(13, 5);
	myGraph.addEdge(5, 13);
	myGraph.addEdge(12, 23);
	myGraph.addEdge(23, 12);
	myGraph.addEdge(11, 23);
	myGraph.addEdge(23, 11);
	myGraph.addEdge(16, 23);
	myGraph.addEdge(23, 16);
	myGraph.addEdge(16, 17);
	myGraph.addEdge(17, 16);
	myGraph.addEdge(19, 18);
	myGraph.addEdge(18, 19);
	myGraph.addEdge(19, 2);
	myGraph.addEdge(2, 19);
	myGraph.addEdge(22, 2);
	myGraph.addEdge(2, 22);
	myGraph.addEdge(24, 7);
	myGraph.addEdge(7, 24);
	myGraph.addEdge(20, 7);
	myGraph.addEdge(7, 20);
	myGraph.addEdge(15, 1);
	myGraph.addEdge(1, 15);
	myGraph.addEdge(15, 6);
	myGraph.addEdge(6, 15);
	myGraph.addEdge(15, 7);
	myGraph.addEdge(7, 15);
	myGraph.addEdge(15, 24);
	myGraph.addEdge(24, 15);
	myGraph.addEdge(15, 20);
	myGraph.addEdge(20, 15);
	myGraph.addEdge(15, 8);
	myGraph.addEdge(8, 15);
	myGraph.addEdge(15, 14);
	myGraph.addEdge(14, 15);
	myGraph.addEdge(8, 14);
	myGraph.addEdge(14, 8);
	myGraph.addEdge(21, 14);
	myGraph.addEdge(14, 21);
	myGraph.addEdge(16, 2);
	myGraph.addEdge(2, 16);
	myGraph.addEdge(16, 20);
	myGraph.addEdge(20, 16);


	return myGraph;
}

//alterei
int main() {
	Graph<int> myGraph;
	int i = 0;
	while(i != 1 && i != 2 && i != 3) {
		cout << "Shortest Graph - 1 | Medium Graph - 2 | Large Graph - 3" << endl;
		cin >> i;
	}
	if(i == 1)
		myGraph = CreateShortGraph();
	if(i == 2)
		myGraph = CreateMediumGraph();
	if(i == 3)
		myGraph = CreateLargeGraph();

	bool quit = false;
	i = 0;
	vector<Automovel> a;
	vector<RefuelStation> r;
	while(!quit) {
		cout << "0 - quit | 1 - add Vehicle | 2 - Add Refuel Station | 3 - Add Point | 4 - Add Edge | 5 - Calculate Shortest Distance Between two points in vehicle A " << endl <<
				"6 - List Vehicle | 7 - List Refuel Stations | 8 - GraphViewer | 9 - Change Graph | 10 - Remove Vehicle | 11 - Remove Refuel Station | 12 - Change Vehicle | 13 - Change Refuel Station" << endl;
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
			int id,x,y;
			cout << "Id x and y" << endl;
			cin >> id >> x >> y;
			if(myGraph.existsPoint(id)) {
				cout << "Point already exists" << endl;
			}
			else {
				myGraph.addVertex(id,x,y);
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
					if(myGraph.getVertex(end)->getDist() == INT_MAX)
						cout << "Impossible to arrive to the end" << endl;
					else	{
						cout << "Shortest Distance to arrive without Refueling: " << myGraph.getVertex(end)->getDist() << endl;
						myGraph.getInitialPath(end, &a[j],r);
						for(unsigned int k = 0; k < r.size(); k++) {
							r[k].setPassed(false);
						}
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
			vector<Vertex<int>*> vs = myGraph.getVertexSet();
			GraphViewer *gv = new GraphViewer(800, 700, false);
			gv->defineEdgeCurved(false);
			gv->createWindow(800, 700);
			gv->defineVertexColor("blue");
			gv->defineEdgeColor("black");
			for(unsigned int j = 0; j < vs.size(); j++) {
				gv->addNode(vs[j]->getInfo(),vs[j]->getX(),vs[j]->getY());
			}
			int a = 1;
			for(unsigned int j = 0; j < vs.size(); j++) {
				vs[j]->setVisited(false);
			}

			for(unsigned int j = 0; j < vs.size(); j++) {
				vs[j]->setVisited(true);
				for(unsigned int k = 0; k < vs[j]->getAdj().size(); k++) {
					if(myGraph.existsEdge(vs[j]->getAdj()[k].getDest()->getInfo(),vs[j]->getInfo()) && !vs[j]->getAdj()[k].getDest()->getVisited())
						gv->addEdge(a,vs[j]->getInfo(),vs[j]->getAdj()[k].getDest()->getInfo(),EdgeType::UNDIRECTED);
					else if (!vs[j]->getAdj()[k].getDest()->getVisited())
						gv->addEdge(a,vs[j]->getInfo(),vs[j]->getAdj()[k].getDest()->getInfo(),EdgeType::DIRECTED);
					a++;
				}
			}
		}
		if(i == 9) {
			int j = 0;
			cout << "Shortest Graph - 1 | Medium Graph - 2 | Large Graph - 3" << endl;
			cin >> j;
			if(j == 1)
				myGraph = CreateShortGraph();
			else if(j == 2)
				myGraph = CreateMediumGraph();
			else if(j == 3)
				myGraph = CreateLargeGraph();
			else
				cout << "Invalid Number" << endl;
		}
		if (i == 10) {
			int id;
			cout << "Id of Vehicle to Remove" << endl;
			cin >> id;
			unsigned int j;
			for(j = 0; j < a.size(); j++) {
				if(a[j].getId() == id)
					break;
			}
			if(id != a[j].getId())
				cout << "Vehicle with id: " << id << " doesn´t exist" << endl;
			else {
				a.erase(a.begin() + j);
			}
		}
		if (i == 11) {
			int id;
			cout << "Id of Refuel Station to Remove" << endl;
			cin >> id;
			unsigned int j;
			for(j = 0; j < r.size(); j++) {
				if(r[j].getId() == id)
					break;
			}
			if(id != r[j].getId())
				cout << "Refuel Station with id: " << id << " doesn´t exist" << endl;
			else {
				r.erase(r.begin() + j);
				myGraph.getVertex(id)->setIsRefuelStation(false);
			}
		}
		if (i == 12) {
			int id;
			cout << "Id of Vehicle to Change" << endl;
			cin >> id;
			unsigned int j;
			for (j = 0; j < a.size(); j++) {
				if (a[j].getId() == id)
					break;
			}
			if (id != a[j].getId())
				cout << "Vehicle with id: " << id << " doesn´t exist" << endl;
			else {
				float battery, consume;
				bool add = true;
				cout << "Battery and consume %/km" << endl;
				cin >> battery >> consume;
				if (battery > 100 || battery < 0) {
					cout << "Battery must be a value between 100 and 0" << endl;
					add =false;
				}
				if (consume < 0) {
					cout << "The consume of a vehicle must be positive" << endl;
					add = false;
				}
				if (add) {
					a[j].setBattery(battery);
					a[j].setConsume(consume);
				}
			}
		}
		if (i == 13) {
			int id;
			cout << "Id of Refuel Station to Change" << endl;
			cin >> id;
			unsigned int j;
			for (j = 0; j < r.size(); j++) {
				if (r[j].getId() == id)
					break;
			}
			if (id != r[j].getId())
				cout << "Refuel Station with id: " << id << " doesn´t exist" << endl;
			else {
				int velocity;
				bool add = true;
				cout << "Rechargement Velocity" << endl;
				cin >> velocity;
				if (velocity != 1 && velocity != 2 && velocity != 3) {
					cout << "Rechargement Velocity must be 1, 2 or 3" << endl;
					add = false;
				}

				if (add) {
					r[j].setVelocity(velocity);
				}
			}
		}
	}
}

