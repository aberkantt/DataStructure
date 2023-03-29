/** 
* @file main.cpp
* @description mainde istenilenleri yerlestirdik
* @course 2-A
* @assignment 1
* @date  19/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#include "OkumaEkleme.hpp"
#include "Exception.hpp"
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "DisplayAtCmd.hpp"
#include <cstdlib>

using namespace std;

int main(int argc,char** argv){
	OkumaEkleme* readingFile = new OkumaEkleme("veriler.txt");
	YoneticiListesi *yoneticiListesi = readingFile->GetFillYoneticiListesi();
	DisplayAtCmd *cmd = new DisplayAtCmd(yoneticiListesi);
	yoneticiListesi->sortByAverage();
	string karakter = "";
	do{
		cmd->printYoneticiListesi();
		cin>>karakter;
		if(karakter == "c"){
			Yon yon = yukari;
			cmd->setState(yon);
		}
		else if(karakter == "z"){
			Yon yon = asagi;
			cmd->setState(yon);
		}
		else if(karakter == "k"){
			int randomIndex = 0;
			try{
				randomIndex = cmd->DisplayRandomSelectedNode();
			}catch(...){
				continue;
			}
			cin>>karakter;
			if(karakter == "k"){
				cmd->DeleteRandomSelectedNode(randomIndex);
				yoneticiListesi->sortByAverage();
			}
		}
		else if(karakter == "p"){
			cmd->DeleteYoneticiNode();
		}
		else if(karakter == "d"){
			cmd->SetPage(yukariSayfa);
		}
		else if(karakter == "a"){
			cmd->SetPage(asagiSayfa);
		}
	}while (karakter != "q");
	return 0;
}