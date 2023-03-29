/** 
* @file SatirListesi.hpp
* @description Satir listesi dugumu
* @course 2-A
* @assignment 1
* @date  11/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP
#include <iomanip>
#include "SatirListesiNode.hpp"
#include "NoSuchElement.hpp"

class SatirListesi{
	private:
		SatirListesiNode *head;
		int size;
		SatirListesiNode*FindPreviousByPosition(int index)throw (NoSuchElement);
	public:
		SatirListesi();
		int Count()const;
		bool isEmpty()const;
		void add(const int& item);
		void insert(int index,const int& item);
		const int& first()throw(NoSuchElement);
		const int& last()throw(NoSuchElement);
		int indexOf(const int& item)throw(NoSuchElement);
		void remove(const int& item);
		void removeAt(int index);
		bool find(const int& item);
		void reverse();
		const int& elementAt(int index)throw(NoSuchElement);
		void clear();
		friend ostream& operator<<(ostream& screen, SatirListesi& rgt);
		void printNodesFromPositionInReverseOrder(int index)throw (NoSuchElement);
		void printReverseOrder();
		void printSatirListesi(int x,int y);
		~SatirListesi();
};
#endif