#include "clothing.h"
#include "product.h"
#include "util.h"
#include "iomanip"
using namespace std;

Clothing::Clothing(string category, string name, double price, int qty, string size, string brand):
    Product::Product(category, name, price, qty),
    size_(size),
    brand_(brand){
    }

Clothing::~Clothing(){
}

set<string> Clothing::keywords() const{

	set<string> da_brand = parseStringToWords(brand_+","+name_);

	return da_brand;
}

string Clothing::displayString() const
{
	string clothing_display = "";

	clothing_display += (Product::getName() + "\n");

	clothing_display += "Size: " + size_ + " Brand: " + brand_ + "\n";

	clothing_display += to_string(price_);

	clothing_display += " ";

	clothing_display += to_string(qty_);

	clothing_display += " left.";

	return clothing_display;

}

void Clothing::dump(ostream& os) const
{
	os << category_ << endl << name_ << endl << fixed << setprecision(2) << price_ << endl << qty_ << endl << size_ << endl << brand_ << endl;
}