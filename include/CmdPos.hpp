/** 
* @file CmdPos.hpp
* @description Konsolda düzen
* @course 2-A
* @assignment 1
* @date  11/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef CMDPOS_HPP
#define CMDPOS_HPP
#include <stdio.h>
#include <windows.h>

static class CmdPos{
public:
	static void gotoxy(int x,int y){
		COORD c;
		c.X=x;
		c.Y=y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	}
}CmdPos;
#endif