#include "user.hh"
#include <map>
using namespace std;
#ifndef CJT_USER_HH
#define CJT_USER_HH



class cjt_user {

    public:

    //Constructoras

    //Pre: Cierto
    //Post: Se crea el objeto cjt_user sin ninguna informacion
    cjt_user();

    /** @brief Añade un usuario al repositorio de usuarios de EVALUATOR
    \Pre: El usuario u contiene, al menos, su ID
    \Post: Se añade el usuario u al conjunto de usuarios del programa
    */
    void add_user(User& u, const string& id_user);

    /** @brief Borra a un usuario del repositorio de usuarios de EVALUATOR
    \Pre: El usuario u contiene, al menos, su ID
    \Post: Se borra al usuario u conjunto de usuarios del programa
    */
    void delete_user(const string& id_user);

    //Pre: Cierto
    //Post:
    void list_users() const;
    /** @brief Comprueba si existe el usuario U en el repositorio de EVALUATOR
    \Pre: El usuario u contiene, al menos, su ID
    \Post: Devuelve "true" si el usuario u está dentro del conjunto de usuarios del programa, "false" si no
    */
    bool exist_user(const string& id_user) const;

    int num_users() const;

    User& info(const string& id_user);



    void update(const User& u, const string& id_user);

    private:
        map<string, User> m_users;
};

#endif
