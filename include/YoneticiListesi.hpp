/** 
* @file YoneticiListesi.hpp
* @description Yonetici dugumu ve kullanilacak fonksiyonlar
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP
#include <iostream>
#include "SatirListesi.hpp"
#include "YoneticiNode.hpp"
#include "IndexOutOfBounds.hpp"
#include "CmdPos.hpp"
#include <stdlib.h>
#include <time.h>

class YoneticiListesi{
	private:
		YoneticiNode *head;
		int size;
		YoneticiNode *FindPreviousByPosition(int index) throw(NoSuchElement);
		YoneticiNode *FindPosition(int index) throw(NoSuchElement);
	public:
		YoneticiListesi();
		bool isEmpty()const;
		int Count()const;
		void add(SatirListesi*& item);
		void insert(int index, SatirListesi*& item);
		SatirListesi*& first()throw(NoSuchElement);
		SatirListesi*& last()throw(NoSuchElement);
		int indexOf(SatirListesi*& item)throw(NoSuchElement);
		void remove(SatirListesi*& item);
		void removeAt(int index);
		void hesaplaAverage(int index);
		void randomRemoveAtSatirListesi(int index, int inlineIndex)throw(IndexOutOfBounds, NoSuchElement);
		int randomGenerator(int index)throw(IndexOutOfBounds,NoSuchElement);
		void moveNode(int from, int to)throw(IndexOutOfBounds);
		bool find(SatirListesi*& item);
		void reverse();
		void sortByAverage();
		SatirListesi*& elementAt(int index)throw (NoSuchElement);
		void clear();
		void printIndex(int index,int x,int y);
		~YoneticiListesi();
};
#endif