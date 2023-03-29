/** 
* @file SatirListesiNode.cpp
* @description 
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#include "SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev){
	this->data = data;
	this->next = next;
	this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data,SatirListesiNode *next){
	this->data = data;
	this->next = next;
	this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data){
	this->data = data;
	this->next = next;
	this->prev = prev;
}