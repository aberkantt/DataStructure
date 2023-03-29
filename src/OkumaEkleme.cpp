/** 
* @file OkumaEkleme.cpp
* @description hpp deki fonksiyonlarin govdesi
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#include "OkumaEkleme.hpp"

YoneticiListesi* OkumaEkleme::GetFillYoneticiListesi(){
	readLine();
	YoneticiListesi* tmp = new YoneticiListesi();
	int count = lineCount();
	for(int i = 0;i < count;i++){
		tmp->add(this->lines[i]);
	}
	return tmp;
}
OkumaEkleme::OkumaEkleme(string dosyaAdi){
	this->dosyaAdi = dosyaAdi;
	
	int sayisira = lineCount();
	this->lines = new SatirListesi*[sayisira];
	for(int i = 0; i < sayisira;i++){
		this->lines[i] = new SatirListesi();
	}
}
int OkumaEkleme::lineCount(){
	int sayac = 0;
	ifstream file(this->dosyaAdi);
	string unused;
	while(getline(file,unused))
		sayac++;
	file.close();
	return sayac;
}
void OkumaEkleme::readLine(){
	string sign;
	ifstream file(this->dosyaAdi);
	string str;
	int index = 0;
	while(getline(file,sign)){
		istringstream ss(sign);
		while(getline(ss,str,' ')){
			this->lines[index]->add(stoi(str));
		}
		index++;
	}
	file.close();
}
OkumaEkleme::~OkumaEkleme(){
	if(lines != 0){
		int count = lineCount();
		for(int i = 0;i < count;i++){
			if(lines[i] != 0)delete lines[i];
		}
		delete[] lines;
	}
}