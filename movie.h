#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"
#include "util.h"
//#include <sstream>
#include <string>
#include <iostream>

class Movie : public Product{
	public:

	Movie(std::string category, std::string name, double price, int qty, std::string genre, std::string rating);
    ~Movie();

	std::set<std::string> keywords() const;

	std::string displayString() const;

	void dump(std::ostream& os) const;

	private:
		std::string genre_;
		std::string rating_;

};
#endif