/** 
* @file YoneticiNode.cpp
* @description 
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#include "YoneticiNode.hpp"

YoneticiNode::YoneticiNode(SatirListesi *data,YoneticiNode *next, YoneticiNode *prev){
	this->data = data;
	this->next = next;
	this->prev = prev;
	this->average = hesaplaAverage();
}
YoneticiNode::YoneticiNode(SatirListesi *data, YoneticiNode *next){
	this->data = data;
	this->next = next;
	this->prev = prev;
	this->average = hesaplaAverage();
}
YoneticiNode::YoneticiNode(SatirListesi *data){
	this->data = data;
	this->next = next;
	this->prev = prev;
	this->average = hesaplaAverage();
}
double YoneticiNode::hesaplaAverage(){
	double sonuc = 0;
	if(this->data->isEmpty())
		return sonuc;
	int count = this->data->Count();
	for(int i = 0; i < count;++i){
		sonuc += this->data->elementAt(i);
	}
	return sonuc / count;
}