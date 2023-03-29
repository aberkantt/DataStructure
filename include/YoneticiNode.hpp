/** 
* @file YoneticiNode.hpp
* @description Yonetici dugumune isaret ediyoruz
* @course 2-A
* @assignment 1
* @date  11/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef YONETICINODE_HPP
#define YONETICINODE_HPP
#include "SatirListesi.hpp"

class YoneticiNode{
	public:
		SatirListesi *data;
		YoneticiNode *prev;
		YoneticiNode *next;
		double average;
		YoneticiNode(SatirListesi* data, YoneticiNode * next, YoneticiNode *prev);
		YoneticiNode(SatirListesi* data,YoneticiNode *next);
		YoneticiNode(SatirListesi *data);
		double hesaplaAverage();
};
#endif