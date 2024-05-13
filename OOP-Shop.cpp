#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
class Item{
    string *itemName;
    float price;
public:
    Item(){}
    Item(string name, float price){
        this->itemName = new string(name);
        this->price = price;
    }
    void setName(string name){
        this->itemName = new string(name);
    }
    void setPrice(float p){price = p;}
    string getName(){return *itemName;}
    float getPrice(){return price;}

    void print(){
        cout << "Item: " << *itemName << " Price: " << price << endl;
    }


};
class shopper{
    string* shopper_name;
    Item* pur_items;
    int size;
    static int numShoppers;
    static int numItems;
public:
    shopper(){
        shopper_name = new string;
        pur_items = new Item;
        size = 0;
        numShoppers++;
    }
    shopper(string na, int pur){
        shopper_name = new string(na);
        pur_items = new Item[pur];
    }
    static int getNumShoppers(){
        return numShoppers;
    }
    void buyItem (Item a){
        if (numItems < size){
            pur_items[numItems] = a;
            numItems++;
        }
        else{
            cout << "You have reached your limit of items" << endl;
        }
    }
    static int getNumItems(){
        return numItems;
    }
    //copy constructor
    shopper (const shopper &a) {
        shopper_name = new string(*a.shopper_name);
        pur_items = new Item[a.size];
        size = a.size;
        for (int i = 0; i < size; i++){
            pur_items[i] = a.pur_items[i];
        }
    }
    //operator decrement
    shopper operator-- (){
        shopper temp = *this;
        temp.size--;
        return temp;

    }
    shopper operator-- (int){
        shopper temp = *this;
        size--;
        return temp;
    }

    void print(){
        cout << "Customer Name: " << *shopper_name << endl;
        cout << "Customer purchased items: " << pur_items << endl;
    }
    //destructor
    ~shopper(){
        delete [] pur_items;
    }
};
int shopper :: numShoppers = 0;
int shopper :: numItems = 0;
int main() {
    shopper s1("Aziz",5), s2("Amr",3);
    Item i1 , i2;
    i1.setName("Banana");
    i1.setPrice(10.50);
    i2.setName("Apple");
    i2.setPrice(5.50);
    s1.buyItem(i1);
    s1.buyItem(i2);
    s2.buyItem(i1);
    s2.buyItem(i2);
    s1.print();
    i1.print();
    s2.print();
    i2.print();

    cout << "#of shoppers is = " << shopper::getNumShoppers << endl;
    cout << "#of items is = " << shopper::getNumItems << endl;
    return 0;
}