#include <bits/stdc++.h>
#include <cstring>
using namespace std;

// == Class Product ==================================================================
//
// ===================================================================================
class Product {
    private:
        string name;
        double price;
        int quantity;

    Product(){};
    Product(string nm, double pr, int qnt) {
        name = nm;
        price = pr;
        quantity = qnt;
    }

    public:
        string GetName() {return name;}
        double GetPrice() {return price;}
        int GetQuantity() {return quantity;}
};

// == DTOR ==================================================================
//
// ===================================================================================
Product::~Product(){};


// == Class Coins ==================================================================
//
// ===================================================================================
class Coins {
    private:
        double value;
        int quantity;

    Coins(){};
    Coins(double vl, int qnt) {
        value = vl;
        quantity = qnt;
    }

    public:
        int GetQuantity() {return quantity;}
        void SetQuantity(int qnt) {quantity = qnt;}
};

// == DTOR ==================================================================
//
// ===================================================================================
Coins::~Coins() {};
