#include "Biblioteca.hpp"

int main(){
    int N = readint();
    Biblioteca b (N);
    Esquema e;
    e.leer_esquema();
    
    int op;  //Código de operación
    op = readint();
    while (op != -6){
	if (op == -1){
	    Revista r;
	    r.leer_revista();
	    int calidad = readint();
	    e.calcular_c1(r);
	    e.calcular_c2(r);
	    b.alta_revista(r, calidad);
	}
	else if (op == -2){
	    string s = readstring();
	    b.baja_revista(s);
	}
	else if (op == -3){
	    string s1 = readstring();
	    string s2 = readstring();
	    Revista r1, r2;
	    int i1 = 0;
	    int i2 = 0;
	    bool b1 = false;
	    bool b2 = false;
	    b.consultar_revista(s1, r1, i1, b1);
	    b.consultar_revista(s2, r2, i2, b2);
	    b.baja_revista(s1);
	    b.baja_revista(s2);
	    r1.fusionar_revista(r2);
	    e.calcular_c1(r1);
	    e.calcular_c2(r1);
	    b.alta_revista(r1, i1);
	}
	else if (op == -4){
	    int calidad = readint();
	    int criterio = readint();
	    cout << "Revistas de calidad " << calidad << " por criterio " << criterio << endl;
	    b.listar_revistas(calidad, criterio);
	    cout << endl;
	}
	else if (op == -5){
	    cout << "Consulta de revista por titulo" << endl;
	    string s = readstring();
	    Revista r;
	    bool b1 = false;
	    int i = 0;
	    b.consultar_revista(s, r, i, b1);
	    if (b1){
		r.escribir_revista();
		cout << i << endl;
	    }
	    else cout << "La revista " << s << " no existe" << endl; 
	    cout << endl;
	}
	op = readint();
    }
}