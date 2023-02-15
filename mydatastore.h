#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <deque>
#include "datastore.h"
#include "product.h"
#include "user.h"
#include "util.h"

class MyDataStore : public DataStore {
	public:
		MyDataStore();
		~MyDataStore();

		void addProduct(Product* p);
		void addUser(User* u);
		std::vector<Product*> search(std::vector<std::string>& terms, int type);
		void dump(std::ostream& ofile);
//other
		void addToCart(std::string username, Product* p); //add data structures
		void viewCart(std::string username);
		void buyCart(std::string username);

	private:
		std::vector<Product*> product_list;
		std::vector<User*> users;
		std::map<std::string, std::vector<Product*>> cart;
		std::map<std::string, std::set<Product*> > keywords_list; //string is keyword and product is all the products containing that

};
#endif