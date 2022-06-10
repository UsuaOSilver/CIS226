#include <iostream>
using namespace std;

int main() {

    double money, cost;
    int choice, quantity;

    Coins Nickle(1.5, 30);
    Coins Dime(1.5, 15);
    Coins Quarter(2, 8);
 
    Product Cookies(Cookies, 1.35, 10);
    Product CandyBar(Candy Bar, 1.50, 15);
    Product Twinkies(Twinkies, 2.45, 5);

    Product Storage[3]; 
    Storage[0] = Cookies;
    Storage[1] = CandyBar;
    Storage[2] = Twinkies;

    DisplayMenu();

    cout << "Only quarter or dollar accepted.";
    cout << "Please insert money: ";
    cin  >> money;

    cout << "Enter product number: ";
    cin  >> choice;
    for(int i = 0; i < 3; i++){
        if(choice == i && Storage[i].GetQuantity() == 0) {
            cout << "Machine Broken";
            exit(1);
        }

    cout << "Please enter quantity: ";
    cin  >> quantity;

    cost = choice*quantity;
    cout << "Total cost: " << cost << endl;

    changeOut(money, cost);

    return 0;
}


// == DisplayMenu ==================================================================
//
// ===================================================================================
void DisplayMenu() {
    cout << "\n\n\n MENU \n";
    for (int i = 0; i < 3; i++) {
        cout << Storage[i].GetName() << " -- $" << Storage[i].GetPrice() 
                                     << " -- quantity: " << Storage[i].GetQuantity() << endl;
        if(Storage[i].GetQuantity() == 0) { cout << "Item number " << i << " is SOLD OUT!" << endl; }
    }
}

// == ChangeOut ==================================================================
//
// ===================================================================================
void ChangeOut(double money, double cost){

    int quarters = 0;
    int dimes = 0;
    int nickels = 0;

    double change = money - cost; //only consider the case where total amount larger than cost

    if (change > (Quarter.GetValue() + Dime.GetValue() + Nickel.GetValue())){
        cout << "Machine Broken";
        cout << "Your money is returned.";
    }
    else {
        while (change >= 25){
            quarters = quarters + 1;
            change = change - 25;
            Quarter.SetQuantity(Quarter.GetQuantity() - 1);
        }
        while (change >= 10){
            dimes = dimes + 1;
            change = change - 10;
            Dime.SetQuantity(Dime.GetQuantity() - 1);
        }
        while (change >= 5){
            nickels = nickels + 1;
            change = change - 5;
            Nickel.SetQuantity(Nickel.GetQuantity() - 1);
        }

        if (Quarter.GetQuantity() < 0 || Dime.GetQuantity() < 0 || Nickel.GetQuantity() < 0) {
            cout << "Machine Broken";
            cout << "Your money is returned.";
        }
        else {
            cout << "Here's your change:" <<  quarters << " quarters, " 
                                          << dimes << " dimes, " 
                                          << nickels << " nickels" 
                                          << endl;
        }
    }
}