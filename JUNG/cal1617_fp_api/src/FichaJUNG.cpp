#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
	GraphViewer *gv = new GraphViewer(600, 600, true); gv->createWindow(600, 600);
	gv->setBackground("background.jpg");
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	gv->addNode(0);
	gv->rearrange();
	gv->addNode(1);
	gv->rearrange();
	gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
	gv->rearrange();
	gv->removeNode(1);
	gv->rearrange();

	gv->addNode(2);
	gv->addEdge(1,0,2, EdgeType::DIRECTED);
	gv->setVertexLabel(2, "Isto e um no");
	gv->setEdgeLabel(1, "Isto e uma aresta");
	gv->setVertexColor(2, "green");
	gv->setEdgeColor(1, "yellow");

}

void exercicio2()
{

}

void exercicio3()
{

}


int main() {
	exercicio1();
	//exercicio2();
	//exercicio3();
	getchar();
	return 0;
}
