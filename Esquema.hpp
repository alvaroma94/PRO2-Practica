/** @file Esquema.hpp
    @brief Especificacion de la clase Esquema. 
*/

#ifndef ESQUEMA_HPP
#define ESQUEMA_HPP

#include "Revista.hpp"

/*
* Clase Esquema
*/

/** @class Esquema
    @brief Representa la organizacion de la coleccion de revistas. 
*/
class Esquema
{

private:
    
  /** @brief Estructura de areas tematicas de la biblioteca */
  Arbre<string> a;
    
public:
    
  /* Constructoras */

  /** @brief Creadora por defecto. 

      Se ejecuta automaticamente al declarar un Esquema.

      \pre cierto
      \post El resultado es un esquema vacio.
  */ 
  Esquema ();
  
  /* Destructoras */

  /** @brief Destructora por defecto.
  
  */ 
  ~Esquema ();
  
  /* Modificadoras*/

  /** @brief Calcula el area tematica en el cual esta clasificada la Revista r segun el criterio de clasificacion 1.
      \pre Todas las palabras clave de la Revista r deben estar en Esquema.
      \post Calcula y asigna el area tematica en el cual esta clasificada la Revista r segun el criterio de clasificacion 1.
  */
  void calcular_c1 (Revista &r)const;
  
  /** @brief Calcula el area tematica en el cual esta clasificada la Revista r segun el criterio de clasificacion 2.
      \pre Todas las palabras clave de la Revista r deben estar en Esquema.
      \post Calcula y asigna el area tematica en el cual esta clasificada la Revista r segun el criterio de clasificacion 2.
  */
  void calcular_c2 (Revista &r)const;
  
  /* Lectura y escritura */
  
  /** @brief Operacion de lectura 
      \pre Cierto
      \post a contiene el esquema leido por el canal estandard de entrada.
  */
  void leer_esquema();
  
private:
    
  /** @brief Añade los elementos de la lista2 a la lista1.
      \pre cierto. 
      \post La lista1 pasa a tener los elementos que ya tenia mas los de la lista2 sin repetir ninguno. 
  */
static void fusionar_listas(list<string>& lista1, list<string>& lista2);
  /** @brief Calcula el area tematica en el cual esta clasificada la Revista r segun el criterio de clasificacion 1.
      \pre lista1 y lista2 son listas ordenadas alfabeticamente. 
      \post El string area_tematica pasa a tener el valor de el area tematica en el cual esta clasificada la Revista r segun el criterio de clasificacion 1. 
  */
static void auxcalcular_c1(Revista &r, Arbre<string>& a, int altura_inicial, int &altura_areatematica, list<string>& lista, bool &todas_encontradas, string &area_tematica);
  /** @brief Calcula el area tematica en el cual esta clasificada la Revista r segun el criterio de clasificacion 2.
      \pre cierto.
      \post El primer componente del resultado indica si hemos encontrado una palabra clave de r; el segundo es el nombre de la area tematica en el cual esta clasificada la revista r segun el criterio de clasificacion 2.
  */
static pair<bool, string> auxcalcular_c2 (Revista &r, Arbre<string>& a);
  /** @brief Operacion de lectura de un arbol de strings.
      \pre  a es vacio; el canal estandard de entrada contiene el recorrido en preorden de un arbol binario A de strings marcado con una "marca".
      \post a = A;
  */
static void leer_esquema2(Arbre<string>& a, string marca);
  
};

#endif
