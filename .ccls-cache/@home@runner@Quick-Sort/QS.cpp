#include "QS.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

QS::QS() {
	array = nullptr;
}
QS::~QS() {
	clear();
}

void QS::sortAll() {
	swapFunction(0, arrayPosition - 1); 
	}

void QS::swapFunction(int left, int right) {
	int index = medianOfThree(left, right);
	
	if (index == -1) {
		return;
	}
	
	int newIndex = partition(left, right, index);
	swapFunction(left, newIndex - 1);
	swapFunction(newIndex + 1, right);
}

int QS::medianOfThree(int left, int right) {
	if (arrayPosition == 0 || left < 0 || right >= arrayPosition || left >= right) {
		return -1;
	}
	
	int middle = ((left + right) / 2);
	
	if (array[left] > array[middle]) {
		swap(array[left], array[middle]);
		}
	
	if (array[middle] > array[right]) {
		swap(array[middle], array[right]);
		}
	
	if (array[left] > array[middle]) {
		swap(array[left], array[middle]);
		}

	return middle;
}

int QS::partition(int left, int right, int pivotIndex) {
	if (array == nullptr || right >= arrayPosition || left >= right || pivotIndex < left || pivotIndex > right || left < 0) {
		return -1;
	}

	int temp;
	const int COMPVAL = array[pivotIndex];
	temp = array[pivotIndex];
	array[pivotIndex] = array[left];
	array[left] = temp;

	int up = left + 1;
	int down = right;

	do {
		while (array[up] <= COMPVAL && up < right) {
			up++;
		}

		while (array[down] > COMPVAL && down > left) {
			down--;
		}

		if (up < down) {
			temp = array[up];
			array[up] = array[down];
			array[down] = temp;
		}
	}
		while (up < down);

	temp = array[left];
	array[left] = array[down];
	array[down] = temp;

	return down;
}

string QS::getArray() const {
  stringstream ss;

	if(arrayPosition > 0 && array != nullptr) {
		for (int i = 0; i < arrayPosition; i++) {
			ss << array[i];
			if (i != (arrayPosition - 1)) {
				ss << ",";
			}
		}
		return ss.str();
	}
	else {
		return "";
	}
}

int QS::getSize() const {
  return arrayPosition;
}


bool QS::addToArray(int value) {
  if (arrayPosition <= CAPACITY -1) {
	  bool addedToArray = true;
	  array[arrayPosition] = value;
	  arrayPosition++;
	  return true;
	}
	else {
		return false;
	}
}

bool QS::createArray(int capacity) {
	CAPACITY = capacity;
	arrayPosition = 0;
	bool isArray = true;

	if (array != nullptr) {
		delete [] array;
		array = nullptr;
	}

	if (capacity < 0) {
		return false;
	}

	array = new int[capacity];
	return true;
}

void QS::clear() {
	delete [] array;
	array = nullptr;
	arrayPosition = 0;
}