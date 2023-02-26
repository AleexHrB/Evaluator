#include "course.hh"
#include <vector>
using namespace std;
#ifndef CJT_COURSE_HH
#define CJT_COURSE_HH






class cjt_course{

    public:
    //Constructoras

    //Pre: Cierto
    //Post: Crea un objeto sin ninguna informacion
    cjt_course();



    //Modificadora

    /** @brief Añade un curso al repositorio de cursos de EVALUATOR
    \Pre: El curso no es vacio
    \Post: Añade el curso C al conjunto de cursos del programa
    */
    void add_course(const Course& c);

    //Consultora

    /** @brief Lista el conjunto de cursos
    \Pre: Cierto
    \Post: se listan los cursos actuales de la plataforma, ordenados crecientemente por su identificador y mostrando, para cada curso, el número de usuarios
    actuales o pasados que lo han completado, el número de usuarios inscritos actualmente, el número de sesiones que lo forman y los identificadores de dichas
    sesiones, en el mismo orden en el que se leyeron cuando se creó el curso
    */
    void list_courses() const;


    /** @brief Comprueba si existe el curso en el repositorio
    \Pre: El curso C no es vacío
    \Post: Devuelve si el curso C pertenece al conjunto de cursos del programa
    */
    bool exist_course(int id_course) const;

    Course& info(int id_course);




    int consult_num_courses() const;

    void update(Course& c, int id);


    private:
        vector<Course> v_course;

};

#endif
