/** 
* @file DisplayAtCmd.cpp
* @description Konsol ekraninda hareket silme vb..
* @course 2-A
* @assignment 1
* @date  12/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#include "DisplayAtCmd.hpp"

DisplayAtCmd::DisplayAtCmd(YoneticiListesi* yonetici){
	this->yonetici = yonetici;
	if(this->yonetici->Count() < DisplayerOnePage){
		this->finishOffset = this->yonetici->Count();
	}
	else{
		this->finishOffset = DisplayerOnePage;
	}
	this->beginOffset = BeginOffset;
}
void DisplayAtCmd::setOffsets(){
	int page = state / DisplayerOnePage;
	this->beginOffset = DisplayerOnePage *page;
	this->finishOffset = DisplayerOnePage * (page+1);
	if(this->finishOffset >= this->yonetici->Count()){
		this->finishOffset = this->yonetici->Count();
	}
}
void DisplayAtCmd::setState(Yon yn){
	if(yn == yukari){
		if(state >= this->yonetici->Count()-1){
			return;
		}
		++state;
		setOffsets();
	}
	else if(yn == asagi){
		if(state <= 0){
			return;
		}
		--state;
		setOffsets();
	}
	else if(yn == yenile){
		setOffsets();
	}
}
void DisplayAtCmd::SetPage(SayfaYon syn){
	if(syn == asagiSayfa){
		for(int i=0; i < DisplayerOnePage; ++i){
			this->setState(asagi);
		}
	}
	else if(syn == yukariSayfa){
		for(int i = 0; i < DisplayerOnePage; ++i){
			this->setState(yukari);
		}
	}
}
void DisplayAtCmd::printYoneticiListesi(){
	int count = yonetici->Count();
	system("CLS");
	if(count == 0){
		cout<<"Yonetici Listesi Yok<\n";
		exit(1);
		return;
	}
	CmdPos.gotoxy(0,0);
	if(this->beginOffset == 0){
		cout<<"<-ilk-";
	}
	else{
		cout<<"<-geri-";
	}
	int dugumGoster = this->finishOffset - this->beginOffset;
	dugumGoster *=13;
	
	CmdPos.gotoxy(dugumGoster,0);
	
	if(this->finishOffset == yonetici->Count()){
		cout<<"-Son->";
	}
	else{
		cout<<"-ileri->";
	}
	for(int i = this->beginOffset; i < this->finishOffset;++i){
		int mod = i %DisplayerOnePage;
		//bu for da sorun yok
		this->yonetici->printIndex(i,15 *mod,1);
	}
	this->printSelectedSatirListesi((this->state % DisplayerOnePage)*15,9);
}
void DisplayAtCmd::printSelectedSatirListesi(int x,int y){
	this->yonetici->elementAt(this->state)->printSatirListesi(x, y);
}
int DisplayAtCmd::DisplayRandomSelectedNode()throw(IndexOutOfBounds, NoSuchElement){
	int randomSelected = this->yonetici->randomGenerator(this->state);
	int xKonum = ((this->state % DisplayerOnePage)+1)*15;
	int yKonum = (randomSelected)*6;
	yKonum +=12;
	CmdPos.gotoxy(xKonum,yKonum);
	cout<<"<-sil->";
	yKonum = this->yonetici->elementAt(this->state)->Count()*6+12;
	
	CmdPos.gotoxy(0,yKonum -1);
	
	return randomSelected;
}
void DisplayAtCmd::DeleteYoneticiNode(){
	this->yonetici->removeAt(this->state);
	this->setState(yenile);
	
	if(this->state==this->finishOffset){
		this->state--;
	}
	this->setState(yenile);
}
void DisplayAtCmd::DeleteRandomSelectedNode(int randomIndex)throw(IndexOutOfBounds,NoSuchElement){
	this->yonetici->randomRemoveAtSatirListesi(this->state, randomIndex);
}