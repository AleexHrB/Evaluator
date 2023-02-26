#include "season.hh"
#include <map>
using namespace std;
#ifndef CJT_SEASON_HH
#define CJT_SEASON_HH




class cjt_season{

    public:

    //Constructoras

    //Pre: Cierto
    //Post: Devuelve el objeto cjt_season vacio
    cjt_season();


    //Modificadoras:
    /** @brief Añade una sesion al repositorio de sesiones del programa
    \Pre: La sesion no está vacía
    \Post: Añade la sesion s al conjunto de sesiones del programa
    */
    void add_season(const string& id_season, const Season& s);

    /** @brief Lista las sesiones
    \Pre: Cierto
    \Post: ordena
    crecientemente las sesiones por su identificador y mostrando, para cada sesión, el número de
    problemas que la forman y los identificadores de dichos problemas, siguiendo su
    estructura de prerequisitos en postorden
    */
    void list_seasons() const;

    /** @brief Comprueba si existe la sesion S en el repositorio de EVALUATOR
    \Pre: La sesion s al menos contiene su identificador
    \Post: Devuelve si la sesion s ya se habia guardado previamente en el programa
    */
    bool exist_season(const string& id_season) const;

    int num_seasons() const;

    Season& return_season(const string& id_season);

    private:
    map<string, Season>m_season;






};

#endif
