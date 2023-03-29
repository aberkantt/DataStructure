/** 
* @file SatirListesiNode.hpp
* @description Dugumden onceki ve sonraki gosterimi
* @course 2-A
* @assignment 1
* @date  11/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef SATIRLISTESINODE_HPP
#define SATIRLISTESINODE_HPP
#include <iostream>
using namespace std;

class SatirListesiNode{
	public:
		int data;
		SatirListesiNode *next;
		SatirListesiNode *prev;
		
		SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev);
		SatirListesiNode(const int data, SatirListesiNode *next);
		SatirListesiNode(const int data);
};
#endif