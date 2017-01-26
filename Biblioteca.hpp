/** @file Biblioteca.hpp
    @brief Especificacion de la clase Biblioteca
*/

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Esquema.hpp"
#include "Revista.hpp"

/*
* Clase Biblioteca
*/

/** @class  Biblioteca
    @brief Representa una coleccion de revistas. 

*/
class Biblioteca
{

private:
    
    /** @brief A1 es un struct que contiene por un lado una lista de revistas (L1) y por otro lado una lista de pairs de strings (L2) */
    struct A1 {
	/** @brief Lista de revistas.

	Ordenada por orden alfabetico segin el area tematica y, dentro de cada area, por titulo de revista, en el cual esta clasificada cada Revista segun el criterio de clasificacion 1. */
	list<Revista> L1;
	/** @brief Lista de pairs de strings.

	Ordenada por orden alfabetico segun el area tematica y, dentro de cada area, por titulo de revista, en el cual esta clasificada cada Revista segun el criterio de clasificacion 2. */
	list<pair<string, string> > L2;
    };
    
    /** @brief biblioteca es un vector de A1 */
    vector<A1> biblioteca;

public:
  /* Constructoras */

  /** @brief Creadora por defecto. 

      Se ejecuta automaticamente al declarar una Biblioteca.

      \pre cierto
      \post El resultado es una Biblioteca vacia de tamano N.
  */ 
  Biblioteca (int N);
  
  /* Destructoras */

  /** @brief Destructora por defecto.
  
  */ 
  ~Biblioteca ();
  
  /* Modificadoras */

  /** @brief Anade la Revista r a la Biblioteca.
      \pre La Revista no esta en la Biblioteca.
      \post La Revista r, con indice de calidad N, pasa a formar parte de la Biblioteca.
  */
  void alta_revista (Revista &r, int N);
  
  /** @brief Elimina la Revista que tiene por nombre s de la Biblioteca.
      \pre La Revista, que tiene por nombre s, esta en la biblioteca.
      \post La Revista, que tiene por nombre s, deja de formar parte de la Biblioteca.
  */
  void baja_revista (const string &s);

  /* Consultoras */
  
  /** @brief Consulta la informacion de la Revista que tiene por nombre s.
      \pre Cierto.
      \post El resultado indica si la revista con nombre s se encuentra o no en la Biblioteca. En caso afirmativo, devuelve toda la informacion que contiene una Revista junto su indice de calidad.
  */
  void consultar_revista(const string& s, Revista& r, int& i, bool& b) const;
  
  /* Lectura y escritura */
  
  /** @brief Operacion de escritura.
      \pre cierto
      \post Dependiendo del indice de calidad (N) y el criterio a seguir, se escribiran las revistas de indice N junto a su correspondiente area tematica segun el criterio a seguir, ordenadas en orden alfabetico de area y, dentro de cada area, por titulo de Revista, por el canal estandard de salida. 
  */
  void listar_revistas (int N, int criterio);
  
private:
    
  /** @brief Elimina la Revista que tiene por nombre s de la Biblioteca.
      \pre Cierto.
      \post La Revista, que tiene por nombre s, deja de formar parte de la Biblioteca si eliminada es true.
  */
void eliminar_revista(const string &s, bool &eliminada, int i); 
  
};

#endif
