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
Graph<int> CreateShortGraph() {
	Graph<int> myGraph;

	myGraph.addVertex(1, 1, 1);
	myGraph.addVertex(2, 658, 453);
	myGraph.addVertex(3, 128, 231);
	myGraph.addVertex(4, 232, 323);
	myGraph.addVertex(5, 342, 256);
	myGraph.addVertex(6, 132, 124);
	myGraph.addVertex(7, 292, 131);
	myGraph.addVertex(8, 659, 116);
	myGraph.addVertex(9, 143, 387);
	myGraph.addVertex(10, 680, 243);

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
Graph<int> CreateMediumGraph() {
	Graph<int> myGraph;

	myGraph.addVertex(1, 1, 1);
	myGraph.addVertex(2, 658, 453);
	myGraph.addVertex(3, 128, 231);
	myGraph.addVertex(4, 232, 323);
	myGraph.addVertex(5, 342, 256);
	myGraph.addVertex(6, 132, 124);
	myGraph.addVertex(7, 292, 131);
	myGraph.addVertex(8, 659, 116);
	myGraph.addVertex(9, 143, 387);
	myGraph.addVertex(10, 680, 243);

	myGraph.addVertex(11, 9, 330);
	myGraph.addVertex(12, 132, 433);
	myGraph.addVertex(13, 243, 540);
	myGraph.addVertex(14, 734, 23);
	myGraph.addVertex(15, 314, 16);
	myGraph.addVertex(16, 432, 543);
	myGraph.addVertex(17, 672, 623);
	myGraph.addVertex(18, 687, 544);
	myGraph.addVertex(19, 465, 687);
	myGraph.addVertex(20, 536, 234);
	myGraph.addVertex(21, 753, 243);
	myGraph.addVertex(22, 633, 243);
	myGraph.addVertex(23, 143, 642);
	myGraph.addVertex(24, 432, 243);
	myGraph.addVertex(25, 257, 243);

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

/**
 * Creates a Graph with 50 Vertexs
 * @return the created graph
 */
Graph<int> CreateLargeGraph() {
	Graph<int> myGraph;

	myGraph.addVertex(1, 1, 1);
	myGraph.addVertex(2, 658, 453);
	myGraph.addVertex(3, 128, 231);
	myGraph.addVertex(4, 232, 323);
	myGraph.addVertex(5, 342, 256);
	myGraph.addVertex(6, 132, 124);
	myGraph.addVertex(7, 292, 131);
	myGraph.addVertex(8, 659, 116);
	myGraph.addVertex(9, 143, 387);
	myGraph.addVertex(10, 680, 243);

	myGraph.addVertex(11, 9, 330);
	myGraph.addVertex(12, 132, 433);
	myGraph.addVertex(13, 243, 540);
	myGraph.addVertex(14, 734, 23);
	myGraph.addVertex(15, 314, 16);
	myGraph.addVertex(16, 432, 543);
	myGraph.addVertex(17, 672, 623);
	myGraph.addVertex(18, 687, 544);
	myGraph.addVertex(19, 465, 687);
	myGraph.addVertex(20, 536, 234);

	myGraph.addVertex(21, 721, 701);
	myGraph.addVertex(22, 43, 76);
	myGraph.addVertex(23, 643, 244);
	myGraph.addVertex(24, 75, 653);
	myGraph.addVertex(25, 263, 687);
	myGraph.addVertex(26, 723, 132);
	myGraph.addVertex(27, 362, 523);
	myGraph.addVertex(28, 143, 322);
	myGraph.addVertex(29, 313, 421);
	myGraph.addVertex(30, 523, 652);

	myGraph.addVertex(31, 462, 423);
	myGraph.addVertex(32, 462, 323);
	myGraph.addVertex(33, 362, 323);
	myGraph.addVertex(34, 462, 523);
	myGraph.addVertex(35, 621, 523);
	myGraph.addVertex(36, 462, 123);
	myGraph.addVertex(37, 562, 23);
	myGraph.addVertex(38, 413, 234);
	myGraph.addVertex(39, 684, 145);
	myGraph.addVertex(40, 567, 89);

	myGraph.addVertex(41, 314, 83);
	myGraph.addVertex(42, 462, 85);
	myGraph.addVertex(43, 223, 123);
	myGraph.addVertex(44, 486, 234);
	myGraph.addVertex(45, 521, 133);
	myGraph.addVertex(46, 52, 283);
	myGraph.addVertex(47, 85, 462);
	myGraph.addVertex(48, 123, 23);
	myGraph.addVertex(49, 234, 486);
	myGraph.addVertex(50, 133, 521);

	myGraph.addEdge(1, 48);
	myGraph.addEdge(1, 22);
	myGraph.addEdge(1, 11);
	myGraph.addEdge(22, 1);
	myGraph.addEdge(48, 1);
	myGraph.addEdge(11, 1);
	myGraph.addEdge(22, 48);
	myGraph.addEdge(22, 6);
	myGraph.addEdge(22, 46);
	myGraph.addEdge(22, 11);
	myGraph.addEdge(48, 22);
	myGraph.addEdge(6, 22);
	myGraph.addEdge(46, 22);
	myGraph.addEdge(11, 22);
	myGraph.addEdge(48, 6);
	myGraph.addEdge(48, 15);
	myGraph.addEdge(48, 43);
	myGraph.addEdge(48, 41);
	myGraph.addEdge(6, 48);
	myGraph.addEdge(15, 48);
	myGraph.addEdge(43, 48);
	myGraph.addEdge(41, 48);
	myGraph.addEdge(6, 43);
	myGraph.addEdge(6, 3);
	myGraph.addEdge(6, 5);
	myGraph.addEdge(43, 6);
	myGraph.addEdge(3, 6);
	myGraph.addEdge(5, 6);
	myGraph.addEdge(43, 7);
	myGraph.addEdge(43, 15);
	myGraph.addEdge(43, 3);
	myGraph.addEdge(43, 4);
	myGraph.addEdge(43, 15);
	myGraph.addEdge(7, 43);
	myGraph.addEdge(15, 43);
	myGraph.addEdge(3, 43);
	myGraph.addEdge(4, 43);
	myGraph.addEdge(15, 43);
	myGraph.addEdge(3, 46);
	myGraph.addEdge(3, 28);
	myGraph.addEdge(3, 5);
	myGraph.addEdge(3, 4);
	myGraph.addEdge(5, 3);
	myGraph.addEdge(4, 3);
	myGraph.addEdge(28, 3);
	myGraph.addEdge(46, 3);

	myGraph.addEdge(28, 9);
	myGraph.addEdge(9, 28);
	myGraph.addEdge(28, 4);
	myGraph.addEdge(4, 28);
	myGraph.addEdge(4, 9);
	myGraph.addEdge(9, 4);
	myGraph.addEdge(33, 4);
	myGraph.addEdge(4, 33);
	myGraph.addEdge(4, 5);
	myGraph.addEdge(5, 4);
	myGraph.addEdge(7, 5);
	myGraph.addEdge(5, 7);
	myGraph.addEdge(7, 41);
	myGraph.addEdge(41, 7);
	myGraph.addEdge(41, 15);
	myGraph.addEdge(15, 41);
	myGraph.addEdge(15, 37);
	myGraph.addEdge(37, 15);
	myGraph.addEdge(15, 42);
	myGraph.addEdge(42, 15);
	myGraph.addEdge(41, 42);
	myGraph.addEdge(42, 41);
	myGraph.addEdge(36, 41);
	myGraph.addEdge(41, 36);
	myGraph.addEdge(7, 36);
	myGraph.addEdge(36, 7);
	myGraph.addEdge(36, 42);
	myGraph.addEdge(42, 36);
	myGraph.addEdge(5, 38);
	myGraph.addEdge(38, 5);
	myGraph.addEdge(33, 38);
	myGraph.addEdge(38, 33);
	myGraph.addEdge(33, 32);
	myGraph.addEdge(32, 33);
	myGraph.addEdge(38, 32);
	myGraph.addEdge(32, 38);
	myGraph.addEdge(38, 7);
	myGraph.addEdge(7, 38);
	myGraph.addEdge(38, 36);
	myGraph.addEdge(36, 38);
	myGraph.addEdge(38, 44);
	myGraph.addEdge(44, 38);
	myGraph.addEdge(44, 20);
	myGraph.addEdge(20, 44);
	myGraph.addEdge(38, 45);
	myGraph.addEdge(45, 38);
	myGraph.addEdge(45, 36);
	myGraph.addEdge(36, 45);
	myGraph.addEdge(45, 42);
	myGraph.addEdge(42, 45);
	myGraph.addEdge(40, 42);
	myGraph.addEdge(42, 40);
	myGraph.addEdge(40, 37);
	myGraph.addEdge(37, 40);
	myGraph.addEdge(37, 42);
	myGraph.addEdge(42, 37);
	myGraph.addEdge(37, 14);
	myGraph.addEdge(14, 37);
	myGraph.addEdge(8, 14);
	myGraph.addEdge(14, 8);
	myGraph.addEdge(26, 14);
	myGraph.addEdge(14, 26);
	myGraph.addEdge(40, 8);
	myGraph.addEdge(8, 40);
	myGraph.addEdge(45, 8);
	myGraph.addEdge(8, 45);
	myGraph.addEdge(39, 8);
	myGraph.addEdge(8, 39);
	myGraph.addEdge(26, 8);
	myGraph.addEdge(8, 26);
	myGraph.addEdge(39, 8);
	myGraph.addEdge(8, 39);
	myGraph.addEdge(39, 26);
	myGraph.addEdge(26, 39);
	myGraph.addEdge(45, 40);
	myGraph.addEdge(40, 45);
	myGraph.addEdge(14, 40);
	myGraph.addEdge(40, 14);
	myGraph.addEdge(45, 44);
	myGraph.addEdge(44, 45);
	myGraph.addEdge(45, 20);
	myGraph.addEdge(20, 45);
	myGraph.addEdge(45, 23);
	myGraph.addEdge(23, 45);
	myGraph.addEdge(39, 23);
	myGraph.addEdge(23, 39);
	myGraph.addEdge(23, 8);
	myGraph.addEdge(8, 23);
	myGraph.addEdge(39, 10);
	myGraph.addEdge(10, 39);
	myGraph.addEdge(10, 26);
	myGraph.addEdge(26, 10);
	myGraph.addEdge(10, 23);
	myGraph.addEdge(23, 10);
	myGraph.addEdge(20, 23);
	myGraph.addEdge(23, 20);
	myGraph.addEdge(40, 23);
	myGraph.addEdge(23, 40);
	myGraph.addEdge(46, 6);
	myGraph.addEdge(6, 46);
	myGraph.addEdge(33, 5);
	myGraph.addEdge(5, 33);
	myGraph.addEdge(32, 5);
	myGraph.addEdge(5, 32);
	myGraph.addEdge(7, 4);
	myGraph.addEdge(4, 7);
	myGraph.addEdge(32, 44);
	myGraph.addEdge(44, 32);
	myGraph.addEdge(32, 20);
	myGraph.addEdge(20, 32);
	myGraph.addEdge(32, 23);
	myGraph.addEdge(23, 32);
	myGraph.addEdge(11, 46);
	myGraph.addEdge(46, 11);
	myGraph.addEdge(11, 9);
	myGraph.addEdge(9, 11);
	myGraph.addEdge(11, 28);
	myGraph.addEdge(28, 11);
	myGraph.addEdge(11, 47);
	myGraph.addEdge(47, 11);
	myGraph.addEdge(11, 12);
	myGraph.addEdge(12, 11);
	myGraph.addEdge(9, 12);
	myGraph.addEdge(12, 9);
	myGraph.addEdge(47, 12);
	myGraph.addEdge(12, 47);
	myGraph.addEdge(49, 12);
	myGraph.addEdge(12, 49);
	myGraph.addEdge(29, 12);
	myGraph.addEdge(12, 29);
	myGraph.addEdge(9, 49);
	myGraph.addEdge(49, 9);
	myGraph.addEdge(29, 9);
	myGraph.addEdge(9, 29);
	myGraph.addEdge(4, 49);
	myGraph.addEdge(49, 4);
	myGraph.addEdge(29, 4);
	myGraph.addEdge(4, 29);
	myGraph.addEdge(29, 33);
	myGraph.addEdge(33, 29);
	myGraph.addEdge(29, 32);
	myGraph.addEdge(32, 29);
	myGraph.addEdge(31, 33);
	myGraph.addEdge(33, 31);
	myGraph.addEdge(31, 32);
	myGraph.addEdge(32, 31);
	myGraph.addEdge(31, 23);
	myGraph.addEdge(23, 31);
	myGraph.addEdge(2, 23);
	myGraph.addEdge(23, 2);
	myGraph.addEdge(2, 10);
	myGraph.addEdge(10, 2);
	myGraph.addEdge(2, 20);
	myGraph.addEdge(20, 2);
	myGraph.addEdge(31, 29);
	myGraph.addEdge(29, 31);
	myGraph.addEdge(31, 2);
	myGraph.addEdge(2, 31);
	myGraph.addEdge(49, 29);
	myGraph.addEdge(29, 49);
	myGraph.addEdge(49, 47);
	myGraph.addEdge(47, 49);
	myGraph.addEdge(50, 47);
	myGraph.addEdge(47, 50);
	myGraph.addEdge(50, 12);
	myGraph.addEdge(12, 50);
	myGraph.addEdge(50, 49);
	myGraph.addEdge(49, 50);
	myGraph.addEdge(50, 13);
	myGraph.addEdge(13, 50);
	myGraph.addEdge(49, 13);
	myGraph.addEdge(13, 49);
	myGraph.addEdge(24, 11);
	myGraph.addEdge(11, 24);
	myGraph.addEdge(24, 47);
	myGraph.addEdge(47, 24);
	myGraph.addEdge(24, 50);
	myGraph.addEdge(50, 24);
	myGraph.addEdge(24, 13);
	myGraph.addEdge(13, 24);
	myGraph.addEdge(24, 25);
	myGraph.addEdge(25, 24);
	myGraph.addEdge(13, 25);
	myGraph.addEdge(25, 13);
	myGraph.addEdge(27, 25);
	myGraph.addEdge(25, 27);
	myGraph.addEdge(19, 25);
	myGraph.addEdge(25, 19);
	myGraph.addEdge(16, 25);
	myGraph.addEdge(25, 16);
	myGraph.addEdge(27, 13);
	myGraph.addEdge(13, 27);
	myGraph.addEdge(16, 27);
	myGraph.addEdge(27, 16);
	myGraph.addEdge(27, 29);
	myGraph.addEdge(29, 27);
	myGraph.addEdge(27, 49);
	myGraph.addEdge(49, 27);
	myGraph.addEdge(28, 46);
	myGraph.addEdge(46, 28);
	myGraph.addEdge(2, 32);
	myGraph.addEdge(32, 2);
	myGraph.addEdge(16, 34);
	myGraph.addEdge(34, 16);
	myGraph.addEdge(29, 34);
	myGraph.addEdge(34, 29);
	myGraph.addEdge(31, 34);
	myGraph.addEdge(34, 31);
	myGraph.addEdge(16, 19);
	myGraph.addEdge(19, 16);
	myGraph.addEdge(16, 30);
	myGraph.addEdge(30, 16);
	myGraph.addEdge(30, 34);
	myGraph.addEdge(34, 30);
	myGraph.addEdge(30, 19);
	myGraph.addEdge(19, 30);
	myGraph.addEdge(31, 35);
	myGraph.addEdge(35, 31);
	myGraph.addEdge(2, 35);
	myGraph.addEdge(35, 2);
	myGraph.addEdge(18, 35);
	myGraph.addEdge(35, 18);
	myGraph.addEdge(2, 18);
	myGraph.addEdge(18, 2);
	myGraph.addEdge(17, 18);
	myGraph.addEdge(18, 17);
	myGraph.addEdge(17, 35);
	myGraph.addEdge(35, 17);
	myGraph.addEdge(17, 21);
	myGraph.addEdge(21, 17);
	myGraph.addEdge(30, 21);
	myGraph.addEdge(21, 30);
	myGraph.addEdge(17, 30);
	myGraph.addEdge(30, 17);
	myGraph.addEdge(50, 25);
	myGraph.addEdge(25, 50);
	myGraph.addEdge(34, 35);
	myGraph.addEdge(35, 34);
	myGraph.addEdge(34, 17);
	myGraph.addEdge(17, 34);
	myGraph.addEdge(30, 35);
	myGraph.addEdge(35, 30);
	return myGraph;
}

Graph<int> CreateVeryLargeGraph() {
	Graph<int> myGraph;

	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("Points.txt");

	if (!inFile) {
		cerr << "Unable to open file pontos.txt";
		exit(1);   // call system to stop
	}

	std::string line;

	if (inFile.is_open()) {
		while (inFile.good()) {
			int id;
			double latitude, longitude;
			string id_s, lat_s, lon_s;

			getline(inFile, id_s, ';');
			getline(inFile, lat_s, ';');
			getline(inFile, lon_s, ';');
			inFile.ignore(1000, '\n');

			//converts from string to int/double
			id = atoi(id_s.c_str());
			latitude = atof(lat_s.c_str());
			longitude = atof(lon_s.c_str());

			if (id == 0)
				break;
			myGraph.addVertex(id, calculateX(longitude,800), calculateY(latitude,800,700));
		}
	}
	inFile.close();

	//Ler o ficheiro arestas.txt
	inFile.open("Edges.txt");

	if (!inFile) {
		cerr << "Unable to open file arestas.txt";
		exit(1);   // call system to stop
	}


	if (inFile.is_open()) {
		while (inFile.good()) {
			int sourc_id, dest_id;
			string r_s, s_s, d_s; //road_string, sourc_string, dest_string
			//bool found = false;

			getline(inFile, r_s, ';');
			getline(inFile, s_s, ';');
			getline(inFile, d_s, ';');
			inFile.ignore(10, '\n');

			//converts from string to double
			sourc_id = atoi(s_s.c_str());
			dest_id = atof(d_s.c_str());

			if (sourc_id == 0)
				break;

			myGraph.addEdge(sourc_id, dest_id);
		}
	}

	inFile.close();

	return myGraph;
}

int main() {
	Graph<int> myGraph;
	int i = 0;
	while (i != 1 && i != 2 && i != 3 && i != 4) {
		cout
				<< "Shortest Graph - 1 | Medium Graph - 2 | Large Graph - 3 | Very Large Graph - 4"
				<< endl;
		cin >> i;
	}
	if (i == 1)
		myGraph = CreateShortGraph();
	if (i == 2)
		myGraph = CreateMediumGraph();
	if (i == 3)
		myGraph = CreateLargeGraph();
	if (i == 4)
		myGraph = CreateVeryLargeGraph();

	bool quit = false;
	i = 0;
	vector<Automovel> a;
	vector<RefuelStation> r;
	while (!quit) {
		cout
				<< "0 - quit | 1 - add Vehicle | 2 - Add Refuel Station | 3 - Change Vehicle | 4 - Change Refuel Station | 5 - Remove Vehicle | 6 - Remove Refuel Station"
				<< endl
				<< "7 - List Vehicle | 8 - List Refuel Stations | 9 - GraphViewer (NOT WORKING) | 10 - Change Graph | 11 - Calculate Shortest Distance Between two points in vehicle A "
				<< endl;
		cin >> i;
		if (i == 0) {
			quit = true;
		} else if (i == 1) {
			bool add = true;
			int id;
			float battery, consume;
			cout << "Id of the Vehicle %of the battery and %/km";
			cin >> id >> battery >> consume;
			for (unsigned int j = 0; j < a.size(); j++) {
				if (a[j].getId() == id) {
					cout << "Vehicle  already exists" << endl;
					add = false;
				}
			}
			if (battery > 100 || battery < 0) {
				cout << "Battery must be a value between 100 and 0" << endl;
				add = false;
			}
			if (consume < 0) {
				cout << "The consume of a vehicle must be positive" << endl;
				add = false;
			}
			if (add) {
				a.push_back(*new Automovel(id, battery, consume));
				cout << a.back().getId() << " " << a.back().getConsume() << " "
						<< a.back().getBattery() << endl;
			}
		} else if (i == 2) {
			bool add = true;
			int id, velocity, z;
			cout
					<< "Id of the Refuel Station Rechargement Velocity and Altitude";
			cin >> id >> velocity >> z;
			for (unsigned int j = 0; j < r.size(); j++) {
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
				r.push_back(*new RefuelStation(id, velocity));
				myGraph.getVertex(id)->setIsRefuelStation(true);
				myGraph.getVertex(id)->setZ(z);
				cout << r.back().getId() << " " << r.back().getVelocity()
						<< endl;
			}
		}
		if (i == 3) {
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
					add = false;
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
		if (i == 4) {
			int id;
			cout << "Id of Refuel Station to Change" << endl;
			cin >> id;
			unsigned int j;
			for (j = 0; j < r.size(); j++) {
				if (r[j].getId() == id)
					break;
			}
			if (id != r[j].getId())
				cout << "Refuel Station with id: " << id << " doesn´t exist"
						<< endl;
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
		} else if (i == 5) {
			int id;
			cout << "Id of Vehicle to Remove" << endl;
			cin >> id;
			unsigned int j;
			for (j = 0; j < a.size(); j++) {
				if (a[j].getId() == id)
					break;
			}
			if (id != a[j].getId())
				cout << "Vehicle with id: " << id << " doesn´t exist" << endl;
			else {
				a.erase(a.begin() + j);
			}
		}
		if (i == 6) {
			int id;
			cout << "Id of Refuel Station to Remove" << endl;
			cin >> id;
			unsigned int j;
			for (j = 0; j < r.size(); j++) {
				if (r[j].getId() == id)
					break;
			}
			if (id != r[j].getId())
				cout << "Refuel Station with id: " << id << " doesn´t exist"
						<< endl;
			else {
				r.erase(r.begin() + j);
				myGraph.getVertex(id)->setIsRefuelStation(false);
			}
		} else if (i == 7) {
			if (a.size() == 0)
				cout << "No Vehicles available" << endl;
			else {
				cout << "Vehicle ID              BATTERY           CONSUME"
						<< endl;
				for (unsigned int j = 0; j < a.size(); j++) {
					cout << a[j].getId() << "                       "
							<< a[j].getBattery() << "               "
							<< a[j].getConsume() << endl;
				}
			}
		} else if (i == 8) {
			if (r.size() == 0)
				cout << "No Refuel Stations available" << endl;
			else {
				cout
						<< "Refuel Station ID         X               Y             Z              Velocity"
						<< endl;
				for (unsigned int j = 0; j < r.size(); j++) {
					cout << r[j].getId() << "                         "
							<< myGraph.getVertex(r[j].getId())->getX()
							<< "               "
							<< myGraph.getVertex(r[j].getId())->getY()
							<< "             "
							<< myGraph.getVertex(r[j].getId())->getZ()
							<< "              " << r[j].getVelocity() << endl;
				}
			}
		} else if (i == 9) {
			vector<Vertex<int>*> vs = myGraph.getVertexSet();
			GraphViewer *gv = new GraphViewer(800, 700, false);
			gv->defineEdgeCurved(false);
			gv->createWindow(800, 700);
			gv->defineVertexColor("blue");
			gv->defineEdgeColor("black");
			for (unsigned int j = 0; j < vs.size(); j++) {
				gv->addNode(vs[j]->getInfo(), vs[j]->getX(), vs[j]->getY());
				if (vs[j]->getIsRefuelStation()) {
					gv->setVertexColor(vs[j]->getInfo(), "red");
				}
			}
			int a = 1;
			for (unsigned int j = 0; j < vs.size(); j++) {
				vs[j]->setVisited(false);
			}

			for (unsigned int j = 0; j < vs.size(); j++) {
				vs[j]->setVisited(true);
				for (unsigned int k = 0; k < vs[j]->getAdj().size(); k++) {
					if (myGraph.existsEdge(
							vs[j]->getAdj()[k].getDest()->getInfo(),
							vs[j]->getInfo())
							&& !vs[j]->getAdj()[k].getDest()->getVisited())
						gv->addEdge(a, vs[j]->getInfo(),
								vs[j]->getAdj()[k].getDest()->getInfo(),
								EdgeType::UNDIRECTED);
					else if (!vs[j]->getAdj()[k].getDest()->getVisited())
						gv->addEdge(a, vs[j]->getInfo(),
								vs[j]->getAdj()[k].getDest()->getInfo(),
								EdgeType::DIRECTED);
					a++;
				}
			}
		} else if (i == 10) {
			int j = 0;
			cout << "Shortest Graph - 1 | Medium Graph - 2 | Large Graph - 3 | Very Large Graph - 4"
					<< endl;
			cin >> j;
			if (j == 1) {
				myGraph = CreateShortGraph();
			} else if (j == 2) {
				myGraph = CreateMediumGraph();
			} else if (j == 3) {
				myGraph = CreateLargeGraph();
			} else if (j == 4) {
				myGraph = CreateVeryLargeGraph();
			} else
				cout << "Invalid Number" << endl;
		} else if (i == 11) {
			bool add = true;
			if (a.size() == 0)
				cout << "No Vehicles available" << endl;
			if (r.size() == 0)
				cout << "No Refuel Stations available" << endl;
			else if (a.size() != 0) {
				int start, end, vehicleid;
				cout << "Start point and end point and vehicle id" << endl;
				cin >> start >> end >> vehicleid;
				unsigned int x;
				for (x = 0; x < a.size(); x++) {
					if (a[x].getId() == vehicleid)
						break;
				}
				if (!myGraph.existsPoint(start)) {
					cout << "Doens't exists the point " << start << endl;
					add = false;
				}
				if (!myGraph.existsPoint(end)) {
					cout << "Doens't exists the point " << end << endl;
					add = false;
				}
				if (a[x].getId() != vehicleid) {
					cout << "There is no vehicle with id = " << vehicleid
							<< endl;
					add = false;
				}
				if (add) {
					vector<Vertex<int>*> vs = myGraph.getVertexSet();
					GraphViewer *gv = new GraphViewer(800, 700, false);
					gv->defineEdgeCurved(false);
					gv->createWindow(800, 700);
					gv->defineVertexColor("blue");
					gv->defineEdgeColor("black");
					for (unsigned int k = 0; k < vs.size(); k++) {
						gv->addNode(vs[k]->getInfo(), vs[k]->getX(), vs[k]->getY());
						if(vs[k]->getIsRefuelStation()) {
							gv->setVertexColor(vs[k]->getInfo(),"red");
						}
					}
					int b = 1;
					for (unsigned int j = 0; j < vs.size(); j++) {
						vs[j]->setVisited(false);
					}

					for (unsigned int j = 0; j < vs.size(); j++) {
						vs[j]->setVisited(true);
						for (unsigned int k = 0; k < vs[j]->getAdj().size(); k++) {
							if (myGraph.existsEdge(
									vs[j]->getAdj()[k].getDest()->getInfo(),
									vs[j]->getInfo())
									&& !vs[j]->getAdj()[k].getDest()->getVisited()) {
								gv->addEdge(b, vs[j]->getInfo(),
										vs[j]->getAdj()[k].getDest()->getInfo(),
										EdgeType::UNDIRECTED);
							}
							else if (!vs[j]->getAdj()[k].getDest()->getVisited()) {
								gv->addEdge(b, vs[j]->getInfo(),
										vs[j]->getAdj()[k].getDest()->getInfo(),
										EdgeType::DIRECTED);
							}
							b++;
						}
					}
					int nTimeStart = GetMilliCount();
					myGraph.getInitialPath(start, end, &a[x], r);
					cout << "Time Elapsed To Calculate: "
							<< GetMilliSpan(nTimeStart) << endl;
					for (unsigned int k = 0; k < r.size(); k++) {
						r[k].setPassed(false);
					}
				}
			}
		}
	}
}

