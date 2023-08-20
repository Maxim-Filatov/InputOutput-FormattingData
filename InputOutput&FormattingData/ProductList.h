#pragma once
#include "Product.h"
#include <string>

using namespace std;


class ProductList {
private:
	Product* products;
public:
	ProductList();

	void write(string filename);
	float countPurchaseSum();
};

