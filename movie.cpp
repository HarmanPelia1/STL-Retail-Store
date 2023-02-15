#include "movie.h"
#include "product.h"
#include "util.h"
#include "iomanip"
using namespace std;

Movie::Movie(string category, string name, double price, int qty, string genre, string rating):
    Product::Product(category, name, price, qty),
    genre_(genre),
    rating_(rating){
    }

Movie::~Movie(){
}

//check with CP's
set<string> Movie::keywords() const
{
	set<string> da_movie = parseStringToWords(name_);

	da_movie.insert(convToLower(genre_));

	return da_movie;
}

string Movie::displayString() const
{
	string movie_display = "";

	movie_display += (Product::getName() + "\n");

	movie_display += "Genre: " + genre_ + " Rating: " + rating_ + "\n";

	movie_display += to_string(price_);

	movie_display += " ";

	movie_display += to_string(qty_);

	movie_display += " left.";

	return movie_display;

}

void Movie::dump(ostream& os) const{
	os << category_ << endl << name_ << endl << fixed << setprecision(2) << price_ << endl << qty_ << endl << genre_ << endl << rating_ << endl;
}	