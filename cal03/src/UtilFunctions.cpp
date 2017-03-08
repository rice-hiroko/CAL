/*
 * UtilFunctions.cpp
 */

#include "Ponto.h"
#include "Util.h"
#include <time.h>
#include <sys/timeb.h>
#include <cmath>
#include <iostream>

using namespace std;
/**
 * function to fill list 'lp' with 'Ponto' objects read from 'is'
 */
void lerPontos(istream &is, vector<Ponto> &vp){
	double x, y;
	if (!is)
		return;
	while (!is.eof()) {
		is >> x >> y;
		Ponto p(x,y);
		vp.push_back(p);
	}
}
//---------------------------------------------------------------------------

/**
 * function to compare 'Ponto' based on 'X' or 'Y'
 */
double comparaPontos(Ponto p1, Ponto p2, int type) {
    if (type == X)
        return p1.x - p2.x;
    return p1.y - p2.y;
}
//---------------------------------------------------------------------------
/**
 * quickSort algorithm for 'std::vector<bestHistory>' by ascending X coordinate
 */
void quickSortX(vector<Ponto> &vp)
{
    quickSort(vp, 0, vp.size()-1, X);
}
//---------------------------------------------------------------------------

/**
 * quickSort algorithm for 'std::vector<bestHistory>' by ascending Y coordinate
 */
void quickSortY(vector<Ponto> &vp)
{
    quickSort(vp, 0, vp.size()-1, Y);
}
//---------------------------------------------------------------------------

void quickSort(vector<Ponto> &v, int left, int right, int type)
{
    if (right - left <= 50)    // if small vector
        insertionSort(v, left, right, type);
    else {
        Ponto p = median3(v, left, right, type);  // x is pivot
        int i = left; int j = right-1;            // partition step
        double comp;
        for(; ; ) {

            comp = -1;
            while (comp < 0) {
                comp = comparaPontos(v[++i], p, type);
            }

            comp = -1;
            while (comp < 0) {
                comp = comparaPontos(p, v[--j], type);
            }
            if (i < j)
                swap(v[i], v[j]);
            else break;
        }
        swap(v[i], v[right-1]);  // reset pivot
        quickSort(v, left, i-1, type);
        quickSort(v, i+1, right, type);
    }
}
//---------------------------------------------------------------------------

/**
 * choose pivot as the median of three values:
 * extremes and central value of vector
 */
Ponto & median3(vector<Ponto> &v, int left, int right, int type)
{
    int center = (left+right) /2;
    if (comparaPontos(v[center], v[left], type) < 0)
        swap(v[left], v[center]);

    if (comparaPontos(v[right], v[left], type) < 0)
        swap(v[left], v[right]);

    if (comparaPontos(v[right], v[center], type) < 0)
        swap(v[center], v[right]);

    swap(v[center], v[right-1]);     // put pivot in position 'right-1'
    return v[right-1];
}
//---------------------------------------------------------------------------

/**
 * for small vectors use a simple method - insertion sort
 */
void insertionSort(vector<Ponto> &v, int left, int right, int type)
{
    for (int i = left+1; i < right+1; i++)
    {
        Ponto tmp = v[i];
        int j;
        for (j = i; j > left && comparaPontos(tmp, v[j-1], type) < 0; j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}
//---------------------------------------------------------------------------

/*
 * Print time
 */
// Something like GetTickCount but portable
// It rolls over every ~ 12.1 days (0x100000/24/60/60)
// Use GetMilliSpan to correct for rollover

int GetMilliCount()
{
  timeb tb;
  ftime( &tb );
  int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
  return nCount;
}
//---------------------------------------------------------------------------

int GetMilliSpan(int nTimeStart)
{
  int nSpan = GetMilliCount() - nTimeStart;
  if (nSpan < 0)
	  nSpan += 0x100000 * 1000;
  return nSpan;
}
//---------------------------------------------------------------------------

double nearestPoints_BF(vector<Ponto> &vp, vector<Ponto> &vMP){
	double dist = 999999.0;
	Ponto p1,p2;
	for(unsigned int i = 0; i < vp.size(); i++){
		for(unsigned int j = 0; j < vp.size(); j++){
			if(i == j && i < vp.size() && j < vp.size()){
				j++;
				continue;
			}
			if (dist > sqrt((comparaPontos(vp[i],vp[j],X)*comparaPontos(vp[i],vp[j],X)) + (comparaPontos(vp[i],vp[j],Y)*comparaPontos(vp[i],vp[j],Y)))){
				dist = sqrt((comparaPontos(vp[i],vp[j],X)*comparaPontos(vp[i],vp[j],X)) + (comparaPontos(vp[i],vp[j],Y)*comparaPontos(vp[i],vp[j],Y)));
				p1 = vp[i];
				p2 = vp[j];
			}
		}
	}
	vMP.push_back(p1);
	vMP.push_back(p2);
	return dist;
}

double nearestPoints_DC(vector<Ponto> &vp, vector<Ponto> &vMP) {
	// TODO code must be placed here
	quickSort(vp, 0, vp.size() -1, X);		// vp ordered by X coordinate

	// call divide and conquer algorithm for 'vp' vector of Ponto's
	Ponto p1, p2;
	double dist = calculateDist(vp, p1, p2);

	vMP.push_back(p1);		// save point 1
	vMP.push_back(p2);		// save point 2
	return dist;			// return minimum distance
}

double calculateDist(vector<Ponto> &vp, Ponto &pLeft, Ponto &pRight) {
	double dist = 999999.0, leftdist = 999999.0, rightdist = 999999.0;
	int j = 0, middle =  vp.size() / 2;
	vector<Ponto> vpl,vpr;
	Ponto p1l,p2l,p1r,p2r;

	if(vp.size() == 2){
		pLeft = vp[0];
		pRight = vp[1];
		return sqrt((comparaPontos(vp[0],vp[1],X)*comparaPontos(vp[0],vp[1],X)) + (comparaPontos(vp[0],vp[1],Y)*comparaPontos(vp[0],vp[1],Y)));
	}
	else if(vp.size() == 3){
		dist = sqrt((comparaPontos(vp[0],vp[1],X)*comparaPontos(vp[0],vp[1],X)) + (comparaPontos(vp[0],vp[1],Y)*comparaPontos(vp[0],vp[1],Y)));
		pLeft = vp[0];
		pRight = vp[1];
		if (dist > sqrt((comparaPontos(vp[2],vp[1],X)*comparaPontos(vp[2],vp[1],X)) + (comparaPontos(vp[2],vp[1],Y)*comparaPontos(vp[2],vp[1],Y)))){
			dist = sqrt((comparaPontos(vp[2],vp[1],X)*comparaPontos(vp[2],vp[1],X)) + (comparaPontos(vp[2],vp[1],Y)*comparaPontos(vp[2],vp[1],Y)));
			pLeft = vp[0];
			pRight = vp[1];
		}
		if (dist > sqrt((comparaPontos(vp[2],vp[0],X)*comparaPontos(vp[2],vp[0],X)) + (comparaPontos(vp[2],vp[0],Y)*comparaPontos(vp[2],vp[0],Y)))){
			dist = sqrt((comparaPontos(vp[2],vp[0],X)*comparaPontos(vp[2],vp[0],X)) + (comparaPontos(vp[2],vp[0],Y)*comparaPontos(vp[2],vp[0],Y)));
			pLeft = vp[0];
			pRight = vp[1];
		}
		return dist;
	}
	else{
		for(int i = 0; i < middle; i++){
			vpl.push_back(vp[i]);
		}
		for(int i = middle; i < vp.size(); i++){
			vpr.push_back(vp[i]);
		}
		leftdist = calculateDist(vpl,p1l,p2l);
		rightdist = calculateDist(vpr,p1r,p2r);
	}
	if(leftdist < rightdist){
		dist = leftdist;
		pLeft = p1l;
		pRight = p2l;
	}
	else{
		dist = rightdist;
		pLeft = p2r;
		pRight = p1r;
	}
	int indLeft = middle - 1;
	int indRight = middle + 1;
	while ((indLeft > 0) && (vp[middle].x - vp[indLeft].x < dist)){

		indLeft--;
	}
	while ((indRight < (int) vp.size() - 1) && (vp[indRight].x - vp[middle].x < dist)) {
		indRight++;
	}
	// strip area around middle point defined
	quickSort(vp, indLeft, indRight, Y);// strip values ordered by Y coordinate

	for (int i = indLeft; i < indRight; i++) {
		for (int j = i + 1; j <= indRight; j++) {
			if (vp[j].y - vp[i].y > dist)
				break;
			else {
				double d = vp[i].distancia(vp[j]);
				if (d < dist) {
					pLeft = vp[i];		// save one point
					pRight = vp[j];		// save the other point
					dist = d;			// save minimum distance
				}
			}
		}
	}
	quickSort(vp, indLeft, indRight, X);		// strip values reordered by X coordinate
	return dist;
}

