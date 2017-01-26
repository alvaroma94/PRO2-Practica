#include "Esquema.hpp"

Esquema::Esquema(){
}
  
Esquema::~Esquema(){
}
  
void Esquema::calcular_c1(Revista &r) const{
    Arbre<string> copia(a);
    list <string> lista;
    bool todas_encontradas;
    string area_tematica;
    int altura_inicial = 1;
    int altura_areatematica;
    auxcalcular_c1(r, copia, altura_inicial, altura_areatematica, lista, todas_encontradas, area_tematica);
    r.mod_c1(area_tematica);
}

void Esquema::auxcalcular_c1(Revista &r, Arbre<string>& a, int altura_inicial, int &altura_areatematica, list<string>& lista, bool &todas_encontradas, string &area_tematica){
    string raiz = a.arrel();
    todas_encontradas = false;
    Arbre<string> a1, a2;
    a.fills(a1, a2);
    if (a1.es_buit() and a2.es_buit()){
	if (r.cons_palabrasclave(raiz)){
	    list<string>::iterator it = lista.begin();
	    lista.insert(it, raiz);
	}
	if (lista.size() == r.cons_numeropalabrasclave()){
	    todas_encontradas = true;
	    area_tematica = raiz;
	    altura_areatematica = altura_inicial;
	}
    }
    else {
	bool todas_encontradas1, todas_encontradas2;
	string area_tematica1, area_tematica2;
	int altura_areatematica1, altura_areatematica2;
	list<string> lista1, lista2;
	if (a1.es_buit() and not a2.es_buit()){
	    auxcalcular_c1(r, a2, altura_inicial+1, altura_areatematica2, lista2, todas_encontradas2, area_tematica2); 
	    todas_encontradas1 = false;
	}
	else if (not a1.es_buit() and a2.es_buit()){
	    auxcalcular_c1(r, a1, altura_inicial+1, altura_areatematica1, lista1, todas_encontradas1, area_tematica1); 
	    todas_encontradas2 = false;
	}
	else if (not a1.es_buit() and not a2.es_buit()){
	    auxcalcular_c1(r, a2, altura_inicial+1, altura_areatematica2, lista2, todas_encontradas2, area_tematica2);
	    auxcalcular_c1(r, a1, altura_inicial+1, altura_areatematica1, lista1, todas_encontradas1, area_tematica1); 
	}
	if (not todas_encontradas1 and not todas_encontradas2) {
	    fusionar_listas(lista1, lista2);
	    lista = lista1;
	    if (lista.size() == r.cons_numeropalabrasclave()){  
		todas_encontradas = true;
		area_tematica = raiz;
		altura_areatematica = altura_inicial;
	    }
	    else todas_encontradas = false;
	}
	else if (not todas_encontradas1 and todas_encontradas2) {
	    todas_encontradas = true;
	    area_tematica = area_tematica2;
	    altura_areatematica = altura_areatematica2;
	}
	else if (todas_encontradas1 and not todas_encontradas2) {
	    todas_encontradas = true;
	    area_tematica = area_tematica1;
	    altura_areatematica = altura_areatematica1;
	}
	else {
	    if (altura_areatematica1 == altura_areatematica2) {
		if (area_tematica1 < area_tematica2) {
		    todas_encontradas = true;
		    area_tematica = area_tematica1;
		    altura_areatematica = altura_areatematica1;
		}
		else {
		    todas_encontradas = true;
		    area_tematica = area_tematica2;
		    altura_areatematica = altura_areatematica2;
		}
	    }
	    else if (altura_areatematica1 > altura_areatematica2) {
		todas_encontradas = true;
		area_tematica = area_tematica1;
		altura_areatematica = altura_areatematica1;
	    }
	    else {
		todas_encontradas = true;
		area_tematica = area_tematica2;
		altura_areatematica = altura_areatematica2;
	    }
	}
    }
}

void Esquema::fusionar_listas(list<string>& lista1, list<string>& lista2){
    list<string>::iterator it = lista2.begin();
    while (it != lista2.end()){
	list<string>::iterator it2 = lista1.begin();
	if (lista1.empty()) {
	    it2 = lista1.end();
	    lista1.insert(it2,(*it));
	}
	else {
	    bool trobat = false;
	    while (it2 != lista1.end() and not trobat){
		if ((*it) == (*it2)) trobat = true;
		else if ((*it) < (*it2)){
		    lista1.insert(it2,(*it));
		    trobat = true;
		}
		else ++it2;
	    }
	    if (not trobat) lista1.insert(it2,(*it));
	}
    ++it;
    }
}

void Esquema::calcular_c2(Revista &r) const{
    pair<bool, string> aux;
    Arbre<string> copia(a);
    aux = auxcalcular_c2(r, copia);
    r.mod_c2(aux.second);
}

pair<bool, string> Esquema::auxcalcular_c2(Revista &r, Arbre<string>& a){
    string raiz = a.arrel();
    pair<bool, string> aux, aux1, aux2;
    aux.first = false;
    Arbre<string> a1, a2;
    a.fills(a1, a2);
    if (a1.es_buit() and a2.es_buit()){
	if (r.cons_palabrasclave(raiz)){
	    aux.second = raiz;
	    aux.first = true;
	}
	else aux.first = false;
    }
    else {
	if (not a1.es_buit() and not a2.es_buit()){
	    aux1 = auxcalcular_c2(r, a1);
	    aux2 = auxcalcular_c2(r, a2);
	}
	else if (not a1.es_buit() and a2.es_buit()){
	    aux1 = auxcalcular_c2(r, a1);
	    aux2.first = false;
	}
	else if (a1.es_buit() and not a2.es_buit()){
	    aux2 = auxcalcular_c2(r, a2);
	    aux1.first = false;
	}
	if (not aux1.first and not aux2.first) aux.first = false;
	else if (aux1.first and not aux2.first) aux = aux1;
	else if (not aux1.first and aux2.first) aux = aux2;
	else {
	    aux.second = raiz;
	    aux.first = true;
	}
    }
    return aux;
}
 
void Esquema::leer_esquema2(Arbre<string>& a, string marca){
    Arbre<string> a1;
    Arbre<string> a2;
    string palabra;
    cin >> palabra;
    if (palabra != marca) {
	leer_esquema2(a1, marca);
	leer_esquema2(a2, marca);
	a.plantar(palabra,a1,a2);
    }
}
 
void Esquema::leer_esquema(){
   leer_esquema2(a, ".");
}