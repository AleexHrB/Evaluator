#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <vector>
#include "BinTree.hh"
#endif
using namespace std;
#ifndef SEASON_HH
#define SEASON_HH


class Season {

    public:
    //Constructoras

    //Pre: Cierto
    //Post: Crea un objeto "season" sin ninguna informacion
    Season();

    //Pre: el string no está indefinido
    //Post: Crea un objeto "season" con un ID
    Season (const string& id_season);

    string consult_id() const;

    /** @brief Consulta si la sesión S tiene el problema P
    \Pre Problema P contiene su identificador definido
    \Post Devuelve si el problema está dentro de la sesión S
    */
    bool has_problem(const string& id_problem) const;

    void add_problems();

    void write_season() const;

    string firts_problem() const;

    pair<string, string> next_problems(const string& id_problem) const;

    int consult_num_problems() const;

    vector<string> get_problems() const;



    private:
    string ID;
    BinTree<string> tree_problems;
    map<string, pair<string, string>> m_problems_season;
    int height = 0;
    static void i_add_problems(BinTree<string>& T, int &height, map<string, pair<string, string>>& m);
    static bool i_has_problem(const string& id_problem, const  map<string, pair<string, string>>& m);
    static void show_problems(const BinTree<string>& T);


};

#endif
