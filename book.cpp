#include "book.h"
#include "product.h"
#include "util.h"
#include "iomanip"
using namespace std;

Book::Book(string category,string name, double price, int qty, string isbn, string author):
    Product::Product(category, name, price, qty),
    isbn_(isbn),
    author_(author)
    {
    }

	Book::~Book()
{
}

set<string> Book::keywords() const{

	set<string> da_author = parseStringToWords(author_+","+name_);

	da_author.insert(isbn_);

	return da_author;
}


string Book::displayString() const{
	string book_display = "";
	book_display += (Product::getName() + "\n");

	book_display += "Author: " + author_ + " ISBN: " + isbn_ + "\n";

	book_display += to_string(price_);

	book_display += " ";

	book_display += to_string(qty_);

	book_display += " left.";

	return book_display;

}
void Book::dump(ostream& os) const
{
	os << category_ << endl << name_ << endl << fixed << setprecision(2) << price_ << endl << qty_ << endl << isbn_ << endl << author_ << endl;
}