#include "problem.hh"
#ifndef NO_DIAGRAM
#include <map>
#endif
using namespace std;
#ifndef CJT_PROBLEM_HH
#define CJT_PROBLEM_HH




class cjt_problem {

    public:

    cjt_problem();
    //Modificadoras
    /** @brief Añade un problema al repositorio de problemas del programa
    \Pre: p contiene, al menos, un identificador
    \Post: Añade el problema al conjunto de problemas del programa
    */
    void add_problem(const string& id_problem);

    //Consultoras
    /** @brief Lista los problemas
    \Pre: Cierto
    \Post: se listan los problemas de la colección, indicando para cada
    problema el número t de envíos totales y el número e de envíos con éxito a dicho
    problema, en ambos casos de usuarios presentes o pasados. También se escribe el ratio (t + 1)/(e + 1), y los problemas se listan en orden creciente
    por dicho ratio. En caso de empate, se listaran por orden creciente de identificador.
    */
    void list_problems();

    /** @brief Comprueba si existe el problema P en el repositorio
    \Pre: El problema p contiene, al menos, su identificador
    \Post: Devuelve si existe el problema p en el conjunto de problemas del programa
    */
    bool exist_problem(string& id_problem) const;

    int num_problems() const;

    Problem& info(string& id_problem);

    void update(const string& id_problem, Problem& p);


  private:
    map<string, Problem> m_problems = map<string, Problem>();






};

#endif
