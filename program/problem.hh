#ifndef NO_DIAGRAM
#include <string>
#endif
using namespace std;
#ifndef PROBLEM_HH
#define PROBLEM_HH


class Problem {

    public:
    //Constructoras
    //Nota: Todas las constructoras inicializaran las variables que llevan el recuento del problema enviado a EVALUATOR y de los envios correctos de este a 0

    Problem();
    //Pre: El string id está definido
    //Post: Crea un objeto "problema" con un ID
    Problem(const string& id);


    string consult_id() const;

    /** @brief Consulta cuántas veces se ha enviado este problema por todos los usuarios
    \Pre: Cierto
    \Post: Devuelve el numero total de envios que se ha hecho sobre este problema de todos los usuarios
    */
    int total_sends() const;
    /** @brief Consulta cuántas veces se ha enviado con éxito este problema
    \Pre: Cierto
    \Post: Devuelve el numero total de envios que se ha hecho sobre este problema de todos los usuarios y han sido correctos
    */
    int total_correct_sends() const;

    void update_fail_problem();

    void update_correct_problem();

    void write_problem() const;

    double show_ratio() const;

  private:
    int total_correct = 0;
    int total = 0;
    string id;
    



};

#endif
