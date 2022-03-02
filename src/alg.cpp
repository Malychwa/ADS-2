// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;}
  if (n == 1) {
    return value;}
  return value*pown(value,n-1);
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
    return n;}
  return n*fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x,n)/fact(n);
}

double expn(double x, uint16_t count) {
  double e = 0;
  for (int n = 0; n < count; n++) {
    e += calcItem(x,n);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double s = 0;
  for (int n = 1; n <= count; n++) {
    s += pown(-1,n-1)*calcItem(x,2n-1);
  }
  return s;
}

double cosn(double x, uint16_t count) {
  double c = 0;
  for (int n = 1; n <= count; n++) {
    c += pown(-1,n-1)*calcItem(x,2n-2);
  }
  return c;
}
