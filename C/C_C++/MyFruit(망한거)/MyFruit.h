#pragma once

#include <iostream>
using namespace std;
#include "Fruit.h"
#include "MyString.h"

class MyFruit : public Fruit
{
   MyString origin;  // 원산지
 public:
   MyFruit();
   MyFruit(char *itemp, int quantity, int buyPrice, char * origin);
   MyFruit(const MyFruit &mr);

   void back(int n);  // 반품 멤버함수, 반품 수량 전달
   char * getOrigin();
   void setQuantity(int n);
};