/* Design a structure that describes the characteristics of items.
Create an array of 5 structured variables and write them into a file.
Determine a purchase amount. */
#include "ProductList.h"
#include "Product.h"
#include <iostream>
#include <fstream>

using namespace std;

// Constructor
ProductList::ProductList() {
	products = new Product[5] {
		{ 1, "Goods1", "GoodsManufacturer1", true, 210.2f },
		{ 2, "Goods2", "GoodsManufacturer1", true,  51.1f },
		{ 3, "Goods3", "GoodsManufacturer3", false, 0.99f },
		{ 4, "Goods4", "GoodsManufacturer4", true, 899.9f },
		{ 5, "Goods5", "GoodsManufacturer5", false, 33.3f }
	};
}

// Write goods to a file
void ProductList::write(string filename) {
	ofstream in;
	in.open(filename);
	if (!in.is_open()) {
		cout << "Error of file opening." << endl;
	}
	else {
		for (int i = 0; i < 5; i++) {
			in << products[i].id << ' ' << products[i].name << ' ' << products[i].manufacturer
				<< ' ' << products[i].presence << ' ' << products[i].price << endl;
		}
		in.close();
		cout << "The list of goods has been written into a file." << endl;
	}
}

// Check if the entered value is appropriate
void validateId() {
	int ignoreValue = 1024;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(ignoreValue, '\n');
	}
}

float ProductList::countPurchaseSum() {
	bool loop = true;
	int id;
	float sum = 0;
	while (loop) {
		cout << "Enter the ID number (1-5) of a product to add it to a cart or press 0 to end the operation:" << endl;
		cin >> id;
		validateId();
		switch (id) {
			case 0:
				loop = false;
				cout << "Total sum: " << sum << endl;
			break;
			case 1:
				sum += products[0].price;
				cout << "Current sum: " << sum << endl;
			break;
			case 2:
				sum += products[1].price;
				cout << "Current sum: " << sum << endl;
			break;
			case 3:
				cout << "These goods are unavailable." << endl;
			break;
			case 4:
				sum += products[3].price;
				cout << "Current sum: " << sum << endl;
			break;
			case 5:
				cout << "These goods are unavailable." << endl;
			break;
			default:
				cout << "Invalid input. Enter only numbers from 0 to 5." << endl;
			break;
		}
	}
	return sum;
}

