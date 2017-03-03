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

	for(unsigned int i = 0; i < vp.size(); i++){
		for(unsigned int j = 0; j < vp.size(); j++){
			if(i == j && i < vp.size() && j < vp.size()){
				j++;
				continue;
			}
			if (dist > sqrt((comparaPontos(vp[i],vp[j],X)*comparaPontos(vp[i],vp[j],X)) + (comparaPontos(vp[i],vp[j],Y)*comparaPontos(vp[i],vp[j],Y)))){
				dist = sqrt((comparaPontos(vp[i],vp[j],X)*comparaPontos(vp[i],vp[j],X)) + (comparaPontos(vp[i],vp[j],Y)*comparaPontos(vp[i],vp[j],Y)));
				if(vMP.size() == 0){
					vMP.push_back(vp[i]);
					vMP.push_back(vp[j]);
				}
				else {
					vMP[0] = vMP[i];
					vMP[1] = vMP[j];
				}
			}
		}
	}

	return dist;
}

double nearestPoints_DC(vector<Ponto> &vp, vector<Ponto> &vMP) {
//	cout << "INITIAL" << endl;
	double dist = 9999999.0;
	unsigned int j = 0;

//	cout << "SORT" << endl;

	quickSortX(vp);
//	cout << "CALCULATE" << endl;

	dist = calculateDist(vp);
//	cout << "END" << endl;

	for (j = 0; j < vp.size(); j++) {
		if (vp[j].x > (-dist / 2)) {
			break;
		}
	}

	while (vp[j].x < (dist / 2) && vp[j].x > (-dist / 2)
			&& vp[j + 1].x < (dist / 2) && vp[j + 1].x > (-dist / 2)) {
		if (dist > sqrt((comparaPontos(vp[j], vp[j + 1], X) * comparaPontos(vp[j], vp[j + 1], X)) + (comparaPontos(vp[j], vp[j + 1], Y) * comparaPontos(vp[j], vp[j + 1], Y))))
			dist = sqrt((comparaPontos(vp[j], vp[j + 1], X) * comparaPontos(vp[j], vp[j + 1], X)) + (comparaPontos(vp[j], vp[j + 1], Y) * comparaPontos(vp[j], vp[j + 1], Y)));
	}

	return dist;
}

double calculateDist(vector<Ponto> &vp){
	double dist = 999999.0, leftdist = 999999.0, rightdist = 999999.0;
	int j = 0;
	cout << "CALCULATE1" << endl;
	cout << vp.size() <<endl;
	if(vp.size() == 2){
		cout << "CALCULATE: VPSIZE==2" << endl;
		return sqrt((comparaPontos(vp[0],vp[1],X)*comparaPontos(vp[0],vp[1],X)) + (comparaPontos(vp[0],vp[1],Y)*comparaPontos(vp[0],vp[1],Y)));
	}
	else if(vp.size() == 3){
		cout << "CALCULATE: VPSIZE==3" << endl;
		dist = sqrt((comparaPontos(vp[0],vp[1],X)*comparaPontos(vp[0],vp[1],X)) + (comparaPontos(vp[0],vp[1],Y)*comparaPontos(vp[0],vp[1],Y)));
		if (dist > sqrt((comparaPontos(vp[2],vp[1],X)*comparaPontos(vp[2],vp[1],X)) + (comparaPontos(vp[2],vp[1],Y)*comparaPontos(vp[2],vp[1],Y))))
			dist = sqrt((comparaPontos(vp[2],vp[1],X)*comparaPontos(vp[2],vp[1],X)) + (comparaPontos(vp[2],vp[1],Y)*comparaPontos(vp[2],vp[1],Y)));
		if (dist > sqrt((comparaPontos(vp[2],vp[1],X)*comparaPontos(vp[2],vp[1],X)) + (comparaPontos(vp[2],vp[1],Y)*comparaPontos(vp[2],vp[1],Y))))
			dist = sqrt((comparaPontos(vp[2],vp[0],X)*comparaPontos(vp[2],vp[0],X)) + (comparaPontos(vp[2],vp[0],Y)*comparaPontos(vp[2],vp[0],Y)));
		return dist;
	}
	else{
//		cout << "CALCULATE: VPSIZE>3" << endl;


		vector<Ponto> left, right;
		for(unsigned int i = 0; i < vp.size()/2; i++){
//			cout << "CALCULATE: VPSIZE>3.0" << endl;

			left.push_back(vp[i]);
		}
		for(unsigned int i = vp.size()/2; i < vp.size(); i++){
//			cout << "CALCULATE: VPSIZE>3.1" << endl;

			right.push_back(vp[i]);
		}
//		cout << "CALCULATE: RECURSIVO" << endl;

		leftdist = calculateDist(left);
//		cout << "CALCULATE: RECURSIVO" << endl;

		rightdist = calculateDist(right);
//		cout << "CALCULATE: RECURSIVO FIM" << endl;

	}
	cout << leftdist<< " " << rightdist << " " <<dist <<endl;

	if(leftdist < rightdist)
		dist = leftdist;
	else
		dist = rightdist;
	cout << leftdist<< " " << rightdist << " " <<dist <<endl;
	return dist;
}
