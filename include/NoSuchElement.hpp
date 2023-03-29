/** 
* @file NoSuchElement.hpp
* @description Yetersiz eleman uyari mesaji
* @course 2-A
* @assignment 1
* @date  11/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef NOSUCHELEMENT_HPP
#define NOSUCHELEMENT_HPP
#include "Exception.hpp"

class NoSuchElement : public Exception{
	public:
		NoSuchElement(const string &msg) : Exception(msg){ }
};
#endif