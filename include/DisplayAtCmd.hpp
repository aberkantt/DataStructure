/** 
* @file DisplayAtCmd.hpp
* @description Konsolda hareket
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef DISPLAYATCMD_HPP
#define DISPLAYATCMD_HPP
#include "YoneticiListesi.hpp"
#include "CmdPos.hpp"
#define DisplayerOnePage 8
#define BeginOffset 0

enum Yon{
	yukari = 0,
	asagi = 1,
	yenile = 2,
};
enum SayfaYon{
	yukariSayfa = 0,
	asagiSayfa = 1,
};
class DisplayAtCmd{
	private:
		YoneticiListesi *yonetici;
		int state;
		int beginOffset;
		int finishOffset;
		void setOffsets();
	public:
		void setState(Yon yn);
		void SetPage(SayfaYon syn);
		DisplayAtCmd(YoneticiListesi* yonetici);
		void printYoneticiListesi();
		void printSelectedSatirListesi(int x, int y);
		int DisplayRandomSelectedNode()throw (IndexOutOfBounds, NoSuchElement);
		void DeleteYoneticiNode();
		void DeleteRandomSelectedNode(int randomIndex) throw(IndexOutOfBounds, NoSuchElement);
};
#endif