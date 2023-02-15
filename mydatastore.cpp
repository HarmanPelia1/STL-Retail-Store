#include "mydatastore.h"
#include <iostream>
using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){
	vector<Product*>::iterator it;
	for(it = product_list.begin(); it != product_list.end(); it++){
		delete *it;
	}
	
	vector<User*>::iterator it2;
	for(it2 = users.begin(); it2 != users.end(); it2++){
		delete *it2;
	}
}

void MyDataStore::addProduct(Product* p){
	product_list.push_back(p);
	set<string> keywords_ = p->keywords();

	for(set<string>::iterator it = keywords_.begin(); it != keywords_.end(); it++){
		
		if (keywords_list.find(*it) == keywords_list.end()) {
			set<Product*> secondary_;
			secondary_.insert(p);
			keywords_list.insert(make_pair(*it, secondary_));
			continue;
		}

		keywords_list.find(*it)->second.insert(p);
	}
}

void MyDataStore::addUser(User* u){
	users.push_back(u);

	vector<Product*> Producto;
	cart.insert(make_pair(u->getName(),Producto ));
}

std::vector<Product*> MyDataStore::search(vector<string>& terms, int type){
	vector<Product*> products_shipped;
	set<Product*> set1;
	set<Product*> set2;

	if(terms.size() == 1){
		//make set into vector
		if (keywords_list.find(terms[0]) == keywords_list.end())
			return vector<Product*>();
		
		set1 = keywords_list.find(terms[0])->second; 
		set<Product*>::iterator it;
	for(it = set1.begin(); it != set1.end(); it++){
		products_shipped.push_back(*it);
	}
	return products_shipped;
	}

	if (keywords_list.find(terms[0]) != keywords_list.end())
		set1 = keywords_list.find(terms[0])->second;
	
	for(int i = 0; i < terms.size(); i++){
		if (keywords_list.find(terms[i]) == keywords_list.end()) continue;
		set2 = keywords_list.find(terms[i])->second; 
			if(type == 0){
				set1 = setIntersection(set1, set2 );
	}
			if(type == 1){
				set1 = setUnion(set1, set2);
			}
	}
		//turn set into vector and send it up
		set<Product*>::iterator it;
	for(it = set1.begin(); it != set1.end(); it++){
		products_shipped.push_back(*it);
	}
	return products_shipped;
}

void MyDataStore::dump(ostream& ofile){

	ofile << "<products>" << endl;
	vector<Product*>::iterator it;
	for(it = product_list.begin(); it != product_list.end(); it++){
		(*it)->dump(ofile);
	}
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;

//check if this is right
	vector<User*>::iterator it2;
	for(it2 = users.begin(); it2 != users.end(); it2++){
		(*it2)->dump(ofile);
	}
	ofile << "</users>" << endl;

}

void MyDataStore::addToCart(string username, Product* p){
	int i = 0;

	while(users[i]->getName() != username){//check if username has a account
		if(i == users.size() - 1){
			cout<<"Invalid request"<<endl;
			return;
		}
		i++;
	}

	if(cart.find(username) != cart.end()){
		(cart.find(username)->second).push_back(p);
	}

}

void MyDataStore::viewCart(string username){
		int i = 0;

	while(users[i]->getName() != username){//check if username has a account
		if(i == users.size() - 1){
			cout<<"Invalid username"<<endl;
			return;
		}
		i++;
	}
	if((cart.find(username) == cart.end())){
		return;
	}
	else{
		std::vector<Product*> userCart = cart.find(username)->second;
		for(int i = 0; i < userCart.size(); i++ ){
			cout << "Item "<< (i+1) << endl << userCart[i]->displayString() << endl << endl;
		}	

	}
}

void MyDataStore::buyCart(std::string user){
			int i = 0;

	while(users[i]->getName() != user){//check if username has a account
		if(i == users.size() - 1){
			cout<<"Invalid username"<<endl;
			return;
		}
		i++;
	}

	User* our_user;
	for(int i = 0; i<users.size(); i++){
		if(users[i]->getName() == user){
			our_user = users[i];
		}
	}
	vector<Product*>& producto = cart.find(user)->second;

	for(int i = 0; i < producto.size(); i++){
		double price = producto[i]->getPrice();
		int quantity = producto[i]->getQty();
		if( (our_user->getBalance() >= price) && (quantity > 0)){
			our_user->deductAmount(price);
			producto[i]->subtractQty(1);
			producto.erase(producto.begin()+i);
			i--;
		}
	}
}