#pragma once

// #ifndef QUICKSORT_QS_H
#define QUICKSORT_QS_H
#include "QSInterface.h"
#include <iostream>
#include <string>

class QS : public QSInterface {
private:
  int *array;
  int arrayPosition = 0;
  int CAPACITY;

public:
  QS();
  ~QS();

  void sortAll();

  void swapFunction(int left, int right);

  int medianOfThree(int left, int right);

  int partition(int left, int right, int pivotIndex);

  string getArray() const;

  int getSize() const;

  bool addToArray(int value);

  bool createArray(int capacity);

  virtual void clear();

protected:
};