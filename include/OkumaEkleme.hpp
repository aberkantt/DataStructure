/** 
* @file OkumaEkleme.hpp
* @description verileri okumak ve eklemek adina
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef OKUMAEKLEME_HPP
#define OKUMAEKLEME_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

class OkumaEkleme{
	private:
		string dosyaAdi;
		int lineCount();
		SatirListesi **lines;
		void readLine();
	public:
		OkumaEkleme(string);
		~OkumaEkleme();
		YoneticiListesi* GetFillYoneticiListesi();
};
#endif