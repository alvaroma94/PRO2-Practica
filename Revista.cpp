#include "Revista.hpp"

Revista::Revista(){}
    
Revista::~Revista(){}
 
void Revista::fusionar_revista(Revista &r){
    list<string>::iterator it = r.palabrasclave.begin();
    while (it != r.palabrasclave.end()){
	list<string>::iterator it2 = palabrasclave.begin();
	if (palabrasclave.empty()){
	    it2 = palabrasclave.end();
	    palabrasclave.insert(it2,(*it));
	}
	else {
	    bool trobat = false;
	    while (it2 != palabrasclave.end() and not trobat){
		if ((*it) == (*it2)) trobat = true;
		else if ((*it) < (*it2)){
		    palabrasclave.insert(it2,(*it));
		    trobat = true;
		}
		else ++it2;
	    }
	    if (not trobat) palabrasclave.insert(it2,(*it));
	}
    ++it;
    }
} 
 
void Revista::mod_c1(const string &s){
    c1 = s;
}

void Revista::mod_c2(const string &s){
    c2 = s;
}

bool Revista::cons_palabrasclave(const string &s) const {
    bool trobat = false;
    list<string>::const_iterator it = palabrasclave.begin();
    while (it != palabrasclave.end() and not trobat){
        if ((*it) == s) trobat = true;
        else ++it;
    }
    return trobat;
}


int Revista::cons_numeropalabrasclave() const{
    return palabrasclave.size();
}

string Revista::cons_nombre() const {
    return nombre;
}
  
string Revista::cons_c1() const {
    return c1;
}
  
string Revista::cons_c2() const {
    return c2;
}

void Revista::leer_revista(){
    string s = readstring();
    nombre = s;
    string pclave = readstring();
    list<string>::iterator it = palabrasclave.begin();
    while (pclave != "."){
	palabrasclave.insert(it, pclave);
	pclave = readstring();
    }
}
  
void Revista::escribir_revista() const{
    cout << nombre << endl;
    list<string>::const_iterator it= palabrasclave.begin();
    cout << (*it);
    ++it;
    while (it != palabrasclave.end()){
	cout << " " << (*it);
	++it;
    }
    cout << endl;
    cout << c1 << " " << c2 << endl;
}