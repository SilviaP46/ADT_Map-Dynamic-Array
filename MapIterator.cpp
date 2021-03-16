#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	currentIndex = 0;
}


void MapIterator::first() {
	currentIndex = 0;
}


void MapIterator::next() {
	if (valid()) {
		currentIndex++;
	}
	else
		throw std::exception();

}


TElem MapIterator::getCurrent(){
	if (valid())
		return map.map[currentIndex];
	else {
		throw std::exception();
	}
}


bool MapIterator::valid() const {
	if (currentIndex < map.len)
		return true;
	return false;
}



