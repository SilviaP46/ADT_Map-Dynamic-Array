#include "Map.h"
#include "MapIterator.h"
#include<iostream>
using namespace std;

Map::Map() {
	len = 0;
	cap = 1;
	map = new TElem[1];
}

Map::~Map() {
	delete[] map;
}

void Map::print() {
	for (int i = 0; i < len; i++)
		cout << map[i].first << " " << map[i].second << endl;
}

void Map::resize() {
	cap = cap * 2;
	
	TElem *auxArray = new TElem[cap];
	for (int i = 0;i < len;i++) {
		auxArray[i] = map[i];
	}
	
	delete[] map;
	map = auxArray;

}

TValue Map::add(TKey c, TValue v){
	if (len == cap)
		resize();

	
	for (int i = 0;i < len;i++) {
		if (map[i].first == c) {
			TValue old = map[i].second;
			map[i].second = v;
			return old;
		}

	}

	len++;
	TElem pairToAdd;
	pairToAdd.first = c;
	pairToAdd.second = v;
	map[len-1] = pairToAdd;
	
	return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
	if(isEmpty())
		return NULL_TVALUE;

	for (int i = 0;i < len;i++) {
		if (map[i].first == c)
			return map[i].second;
	}

	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
	if (isEmpty())
		return NULL_TVALUE;
	
	int i = 0;
	while (map[i].first != c && i < len) {
		i++;
	}

	if (i < len) {
		len--;
		TValue old = map[i].second;
		for (int j = i;j < len;j++) {
			map[j] = map[j + 1];
		}

		return old;
	}

	return NULL_TVALUE;
}


int Map::size() const {
	return len;
}

bool Map::isEmpty() const{
	if (len == 0)
		return true;
	return false;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}



