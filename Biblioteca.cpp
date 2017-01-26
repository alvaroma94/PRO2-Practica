#include "Biblioteca.hpp"

Biblioteca::Biblioteca(int N){
    biblioteca = vector<A1> (N);
}
  
Biblioteca::~Biblioteca (){
}
  
void Biblioteca::alta_revista (Revista &r, int N){
    list<Revista>::iterator it = biblioteca[N-1].L1.begin();
    if (biblioteca[N-1].L1.empty()) biblioteca[N-1].L1.insert(it,r);
    else{
	bool anadida = false;
	while (it != biblioteca[N-1].L1.end() and not anadida){
	    if (r.cons_c1() == (*it).cons_c1()){
		if (r.cons_nombre() < (*it).cons_nombre()){
		    biblioteca[N-1].L1.insert(it,r);
		    anadida = true;
		}
		else ++it;
	    }
	    else if (r.cons_c1() < (*it).cons_c1()){
		biblioteca[N-1].L1.insert(it,r);
		anadida = true;
	    }
	    else ++it;
	}
	if (not anadida) biblioteca[N-1].L1.insert(it,r);
    }
    list<pair<string, string> >::iterator it2 = biblioteca[N-1].L2.begin();
    pair<string, string> aux;
    aux.first = r.cons_nombre();
    aux.second = r.cons_c2();
    if (biblioteca[N-1].L2.empty()) biblioteca[N-1].L2.insert(it2,aux);
    else{
	bool anadida2 = false;
	while (it2 != biblioteca[N-1].L2.end() and not anadida2){
	    if (r.cons_c2() == (*it2).second){
		if (r.cons_nombre() < (*it2).first){
		    biblioteca[N-1].L2.insert(it2,aux);
		    anadida2 = true;
		}
		else ++it2;
	    }
	    else if (r.cons_c2() < (*it2).second){
		biblioteca[N-1].L2.insert(it2,aux);
		anadida2 = true;
	    }
	    else ++it2;
	}
	if (not anadida2) biblioteca[N-1].L2.insert(biblioteca[N-1].L2.end(),aux); 
    }
}
  
void Biblioteca::baja_revista (const string &s){
    bool eliminada = false;
    int i = 0;
    while (i < biblioteca.size() and not eliminada){
	eliminar_revista(s, eliminada, i);
	if (not eliminada) ++i;
    }
    bool eliminada2 = false;
    list<pair<string, string> >::iterator it2 = biblioteca[i].L2.begin();
    while (it2 != biblioteca[i].L2.end() and not eliminada2){
	if ((*it2).first == s){
	    it2 = biblioteca[i].L2.erase(it2);	    
	    eliminada2 = true;
	}
	else ++it2;
    }
}

void Biblioteca::eliminar_revista(const string &s, bool& eliminada, int i) {
    list<Revista>::iterator it = biblioteca[i].L1.begin();
    while (it != biblioteca[i].L1.end() and not eliminada){
	if ((*it).cons_nombre() == s){
	    it = biblioteca[i].L1.erase(it);
	    eliminada = true;
	}
	else ++it;
    }
}

void Biblioteca::consultar_revista(const string &s, Revista& r, int& i, bool& existe) const {
    Revista aux;
    while (i < biblioteca.size() and not existe){
        list<Revista>::const_iterator it = biblioteca[i].L1.begin();
	while (it != biblioteca[i].L1.end() and not existe){
            if((*it).cons_nombre() == s){
		aux = (*it);
		existe = true;
	    }
	    else ++it;
	}
	++i;
   }
   r = aux;
}
  
void Biblioteca::listar_revistas (int N, int criterio){
    if (criterio == 1){
	list<Revista>::const_iterator it = biblioteca[N-1].L1.begin();
	while (it != biblioteca[N-1].L1.end()){
	    cout << (*it).cons_c1() << " " << (*it).cons_nombre() << endl;
	    ++it;
	}
    }
    else {
	list<pair<string, string> >::const_iterator it = biblioteca[N-1].L2.begin();
	while (it != biblioteca[N-1].L2.end()){
	    cout << (*it).second << " " << (*it).first << endl;
	    ++it;
	}
    }
}