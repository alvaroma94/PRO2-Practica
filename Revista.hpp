/** @file Revista.hpp
    @brief Especificacion de la clase Revista
*/

#ifndef REVISTA_HPP
#define REVISTA_HPP

#include "Arbre.hpp"
#include "utils.PRO2"
#include <vector>
#include <list>
#include <string>

/*
* Clase Revista
*/

/** @class Revista
    @brief Representa el cojunto de caracteristicas y operaciones de las revistas. 

*/
class Revista
{

private:
    
	/** @brief Identificador que indica el nombre de una Revista */
	string nombre;
	/** @brief Lista de palabras clave de una Revista.

	Ordenada por orden alfabetico */
	list<string> palabrasclave;
	/** @brief Identificador que indica el area tematica segun el criterio 1 de una Revista */
	string c1;
	/** @brief Identificador que indica el area tematica segun el criterio 2 de una Revista */
	string c2;
    
public:
  /* Constructoras */

  /** @brief Creadora por defecto. 

      Se ejecuta automaticamente al declarar una Revista.

      \pre cierto
      \post El resultado es una Revista vacia.
  */ 
  Revista ();
  
  /* Destructoras */

  /** @brief Destructora por defecto.
  
  */ 
  ~Revista ();
  
  /* Modificadoras */
  
  /** @brief Anade las palabras clave de la Revista r al parametro implicito.
      \pre El parametro implicito y la Revista r son diferentes, las palabras clave de r y del parametro implicito estan ordenadas alfabeticamente.
      \post El parametro implicito pasa a tener como palabras clave las que ya tenia mas las de la Revista r sin repetir ninguna.
  */
  void fusionar_revista (Revista &r);

  /** @brief Modifica el area tematica segun el criterio de clasificacion 1 de una Revista.
      \pre cierto.
      \post El parametro implicito pasa a tener s como nueva area tematica asignada segun el criterio de clasificacion 1.
  */
  void mod_c1 (const string &s);
  
  /** @brief Modifica el area tematica segun el criterio de clasificacion 2 de una Revista.
      \pre cierto.
      \post El parametro implicito pasa a tener s como nueva area tematica asignada segun el criterio de clasificacion 2.
  */
  void mod_c2 (const string &s);
  
  /* Consultoras */
  
  /** @brief Consultora que indica si s es palabra clave del parametro implicito o no.
      \pre cierto.
      \post El resultado indica si s es palabra clave del parametro implicito o no.
  */
  bool cons_palabrasclave(const string &s) const;
  
  /** @brief Consultora que indica el numero de palabras clave que tiene parametro implicito.
      \pre cierto.
      \post Devuelve el numero de palabras clave que tiene parametro implicito.
  */
  int cons_numeropalabrasclave () const;
  
  /** @brief Consultora que indica el nombre de una Revista.
      \pre cierto.
      \post Devuelve el nombre de una Revista.
  */
  string cons_nombre () const;
  
  /** @brief Consultora que indica el area tematica en la que se encuentra el parametro implicito segun el criterio de clasificacion 1.
      \pre cierto.
      \post Devuelve el area tematica en la que se encuentra el parametro implicito segun el criterio de clasificacion 1.
  */
  string cons_c1 () const;
  
  /** @brief Consultora que indica el area tematica en la que se encuentra el parametro implicito segun el criterio de clasificacion 2.
      \pre cierto.
      \post Devuelve el area tematica en la que se encuentra el parametro implicito segun el criterio de clasificacion 2.
  */
  string cons_c2 () const;
  
  /* Lectura y escritura */
  
  /** @brief Operacion de lectura
      \pre cierto
      \post El parametro implicito pasa a tener un nombre y una lista de palabras clave ordenada alfabeticamente, leidos del canal de entrada estandard. 
  */
  void leer_revista ();
  
  /** @brief Operacion de escritura
      \pre cierto
      \post Se ha escrito el nombre del parametro implicito, junto a sus palabras clave y sus dos areas tematicas, por el canal de salida estandard.
  */
  void escribir_revista () const;
  
};

#endif
