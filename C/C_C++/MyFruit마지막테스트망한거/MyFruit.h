#pragma once

#include <iostream>
using namespace std;
#include "Fruit.h"
#include "MyString.h"

class MyFruit : public Fruit
{
   MyString origin;  // ������
 public:
   MyFruit();
   MyFruit(char *itemp, int quantity, int buyPrice, char * origin);
   MyFruit(const MyFruit &mr);

   void back(int n);  // ��ǰ ����Լ�, ��ǰ ���� ����
   char * getOrigin();
   void setQuantity(int n);
};