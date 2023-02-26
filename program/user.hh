#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include "course.hh"
#include "problem.hh"
#include <map>
#endif
using namespace std;
#ifndef USER_HH
#define USER_HH



class User {

    public:
    //Constructoras
    //Nota: Todas las constructoras inicializan el número de problemas enviados a 0

    //Pre: El string name no es indeterminado
    //Post: Crea un objeto "user" con su nombre
    User(string name);

    //Pre:Cierto
    //Post: Crea un usuario sin informacion
    User();


    //Modificadoras
    /** @brief Registra al usuario en el curso C
    \Pre: El curso C es válido y el usuario no está inscrito a ningun curso
    \Post: Registra al usuario al curso C
    */
    void sign_up_course(int id_course, Course& c);

    /** @brief Lista los problemas resueltos por el usuario
    \Pre: Cierto
    \Post
    */
    void show_result_problems() const;
    /** @brief Lista los problemas a los que el usuario puede acceder
    \Pre: Cierto
    \Post:
    */
    void show_avaible_problems() const;
    /** @brief Envia un problema
    \Pre: El problema contiene, al menos, su ID. Result = 1 o Result = 0
    \Post: Hace el envío del problema p con Result = 1 o Result = 0;
    */
    void send_problem(const string& id_problem, int result);

    //Consultoras
    /** @brief Comprueba si el usuario ha completado el curso al que está inscrito
    \Pre: El usuario está inscrito en un curso
    \Post: Devuelve si el usuario ha completado su curso
    */
    bool has_completed_actual_course(const Course& c) const;
    /** @brief Comprueba si el usuario está inscrito en algún curso
    \Pre: Cierto
    \Post: Devuelve si el usuario está inscrito en algún curso
    */
    bool has_logged_one_course() const;
    /** @brief Consulta el string del curso al que está inscrito
    \Pre: El usuario está inscrito en un Curso
    \Post: Devuelve el ID del curso inscrito
    */
    int id_actual_course() const;

    void write_user() const;

    void add_problem(const string& id_problem, bool correct, int num_sends, const Season& s);

    void log_out_course();

  private:
    string id;
    int actual_course;
    int total_correct_sends = 0;
    int total_sends = 0;
    int trys_problem = 0;
    int num_result_problems_this_course = 0;
    bool has_logged = false;
    map<string, pair<int,bool>> problems_user;



};

#endif
