/** 
* @file IndexOutOfBounds.hpp
* @description Yetersiz eleman uyari mesaji
* @course 2-A
* @assignment 1
* @date  11/11/22
* @author Berkant Ontemel/berkant.ontemel@ogr.sakarya.edu.tr
*/
#ifndef INDEXOUTOFBOUNDS_HPP
#define INDEXOUTOFBOUNDS_HPP

#include "Exception.hpp"

class IndexOutOfBounds : public Exception{
	public:
		IndexOutOfBounds(const string &msg) : Exception(msg){ }
};
#endif