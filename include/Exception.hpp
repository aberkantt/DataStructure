/** 
* @file Exception.hpp
* @description Hata mesaji
* @course 2-A
* @assignment 1
* @date  11/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception{
	private:
		string message;
	public:
		Exception(const string &msg):message(msg){ }
		string Message()const;
};
#endif