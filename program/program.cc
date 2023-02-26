#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
#include "user.hh"
#include "course.hh"
#include "season.hh"
#include "problem.hh"
#include "cjt_problem.hh"
#include "cjt_season.hh"
#include "cjt_user.hh"
#include "cjt_course.hh"
using namespace std;



void read_problems(cjt_problem& cjt_p, int num_problems) { //ok

    for (int i = 0; i<num_problems; ++i){
        string id;
        cin>>id;
        cjt_p.add_problem(id);

    }
}

void read_seasons(cjt_season& cjt_s, int num_seasons) { //ok


        for (int i = 0; i<num_seasons; ++i) {
            string id_season;
            cin>>id_season;
            Season s(id_season);
            s.add_problems();
            cjt_s.add_season(id_season, s);

        }
}

void read_courses(cjt_course& cjt_c, int num_courses, cjt_season& cjt_s) { //ok

        for (int i = 0; i<num_courses; ++i) {
            int num_seasons;
            cin>>num_seasons;
            Course c(i+1);
            c.read_seasons(num_seasons, cjt_s);
            cjt_c.add_course(c);

        }



}

void read_users(cjt_user& cjt_u, int num_users) { //ok

    for (int i = 0; i<num_users; ++i) {
        string ID_user;
        cin>>ID_user;
        User u(ID_user);
        cjt_u.add_user(u, ID_user);
    }

}

void menu (const string& option_selected, cjt_problem& cjt_p, cjt_season& cjt_s, cjt_course& cjt_c, cjt_user& cjt_u) {

        if (option_selected == "nuevo_problema" or option_selected == "np") { //REPIOLA

                string id_problem;
                cin>>id_problem;

                cout<<"#"<<option_selected<<" "<<id_problem<<endl;

            if (not cjt_p.exist_problem(id_problem)) {

                cjt_p.add_problem(id_problem);
                cout<<cjt_p.num_problems()<<endl;
            }

            else cout<<"error: el problema ya existe"<<endl;
        }


        else if (option_selected == "nueva_sesion" or option_selected == "ns") { //add season, volver
            string id_season;
            cin>>id_season;

            //leer datos de la sesion
            cout<<"#"<<option_selected<<" "<<id_season<<endl;
            if (cjt_s.exist_season(id_season)) {
                cout<<"error: la sesion ya existe"<<endl;

            }

            else {
                //leer bintree y actualizar conjunto
                Season s(id_season);
                s.add_problems();
                cjt_s.add_season(id_season, s);
                cout<<cjt_s.num_seasons()<<endl;
            }

        }


        else if (option_selected == "nuevo_curso" or option_selected == "nc") { //add course, volver


            cout<<"#"<<option_selected<<endl;
            Course c(cjt_c.consult_num_courses() + 1);
            bool success;
            c.new_course(success, cjt_s);

            if (success) {
              cjt_c.add_course(c);
              cout<<cjt_c.consult_num_courses()<<endl;
            }
            else cout<<"error: curso mal formado"<<endl;


        }


        else if (option_selected == "alta_usuario" or option_selected == "a") { //add user, OK
            string id_user;
            cin>>id_user;
            cout<<"#"<<option_selected<<" "<<id_user<<endl;

            if (not cjt_u.exist_user(id_user)) {
                User u(id_user);
                cjt_u.add_user(u, id_user);
                cout<<cjt_u.num_users()<<endl;
            }

            else cout<<"error: el usuario ya existe"<<endl;
        }

        else if (option_selected == "baja_usuario" or option_selected == "b") { //delete user, OK
            string id_user;
            cin>>id_user;

            cout<<"#"<<option_selected<<" "<<id_user<<endl;
            if (cjt_u.exist_user(id_user)) {

                User u = cjt_u.info(id_user);
                if(u.has_logged_one_course()) {
                    int id = u.id_actual_course();
                    Course& c = cjt_c.info(id);
                    c.sign_out_course("baja");

                }

                cjt_u.delete_user(id_user);
                cout<<cjt_u.num_users()<<endl;
            }
            else cout<<"error: el usuario no existe"<<endl;
        }

        else if (option_selected == "inscribir_curso" or option_selected == "i") { //OK

            string id_user;
            cin>>id_user;


            int id_course;
            cin>>id_course;

            cout<<"#"<<option_selected<<" "<<id_user<<" "<<id_course<<endl;


            if (not cjt_u.exist_user(id_user)) cout<<"error: el usuario no existe"<<endl;
            else if (not cjt_c.exist_course(id_course)) cout<<"error: el curso no existe"<<endl;
            else if (cjt_u.info(id_user).has_logged_one_course()) cout<<"error: usuario inscrito en otro curso"<<endl;

            else {
                User& u = cjt_u.info(id_user);
                Course& c = cjt_c.info(id_course);
                u.sign_up_course(id_course,c);
                c.update_num_users(1);
                cout<<cjt_c.info(id_course).num_users_registred()<<endl; //perfecto
            }
        }

        else if (option_selected == "curso_usuario" or option_selected == "cu") { //OK?

            string id_user;
            cin>>id_user;
            cout<<"#"<<option_selected<<" "<<id_user<<endl;


            if (not cjt_u.exist_user(id_user)) cout<<"error: el usuario no existe"<<endl;

            else {
                if (cjt_u.info(id_user).has_logged_one_course()) cout<<cjt_u.info(id_user).id_actual_course()<<endl;
                else cout<<"0"<<endl;
            }
        }

        else if (option_selected == "sesion_problema" or option_selected == "sp") {

            int id_course;
            cin>>id_course;
            string id_problem;
            cin>>id_problem;

            cout<<"#"<<option_selected<<" "<<id_course<<" "<<id_problem<<endl;
            if (not cjt_c.exist_course(id_course)) cout<<"error: el curso no existe"<<endl;

            else if (cjt_p.exist_problem(id_problem)) {

                string id = cjt_c.info(id_course).show_id_season_problem(id_problem);
                if (id == "-1") cout<<"error: el problema no pertenece al curso"<<endl;
                else cout<<id<<endl;
            }

            else cout<<"error: el problema no existe"<<endl;

        }

        else if (option_selected == "problemas_resueltos" or option_selected == "pr") {

            string id_user;
            cin>>id_user;
            cout<<"#"<<option_selected<<" "<<id_user<<endl;

            if (cjt_u.exist_user(id_user)) cjt_u.info(id_user).show_result_problems();

            else cout<<"error: el usuario no existe"<<endl;
        }

        else if (option_selected == "problemas_enviables" or option_selected == "pe") {

            string id_user;
            cin>>id_user;
            cout<<"#"<<option_selected<<" "<<id_user<<endl;
            if (cjt_u.exist_user(id_user)) {
                User u = cjt_u.info(id_user);
                if (u.has_logged_one_course()) u.show_avaible_problems();
                else cout<<"error: usuario no inscrito en ningun curso"<<endl;
            }

            else cout<<"error: el usuario no existe"<<endl;


        }

        else if (option_selected == "envio" or option_selected == "e") { //actualizar usuario si completa el curso
            string id_user;
            cin>>id_user;

            string id_problem;
            cin>>id_problem;

            Problem& p = cjt_p.info(id_problem);
            User& u = cjt_u.info(id_user);

            int result;
            cin>>result;
            cout<<"#"<<option_selected<<" "<<id_user<<" "<<id_problem<<" "<<result<<endl;

            int n = u.id_actual_course();

            u.send_problem(id_problem,result);

            if (result == 1) {
            Season& s = cjt_s.return_season(cjt_c.info(n).show_id_season_problem(id_problem));
            pair<string, string> p_problems = s.next_problems(id_problem);
            u.add_problem(p_problems.first, false, 0, s);
            u.add_problem(p_problems.second, false, 0, s);
            p.update_correct_problem();

            Course& c = cjt_c.info(n);
            if (u.has_completed_actual_course(c)) {
                u.log_out_course();
                c.sign_out_course("curso_completado");
            }

            }

            else {
                p.update_fail_problem();
            }




        }




        else if (option_selected == "listar_problemas" or option_selected == "lp") {
            cout<<"#"<<option_selected<<endl;
            cjt_p.list_problems();
        }

        else if (option_selected == "listar_sesiones" or option_selected == "ls") {
            cout<<"#"<<option_selected<<endl;
            cjt_s.list_seasons();
        }

        else if (option_selected == "listar_cursos" or option_selected == "lc") { //ok
        cout<<"#"<<option_selected<<endl;
            cjt_c.list_courses();
        }

        else if (option_selected == "listar_usuarios" or option_selected == "lu"){ //ok
        cout<<"#"<<option_selected<<endl;
            cjt_u.list_users();
        }

         else if (option_selected == "escribir_curso" or option_selected == "ec") {

            int id_course;
            cin>>id_course;
            cout<<"#"<<option_selected<<" "<<id_course<<endl;
            if (cjt_c.exist_course(id_course)) cjt_c.info(id_course).write_course();

            else cout<<"error: el curso no existe"<<endl;
        }

        else if (option_selected == "escribir_sesion" or option_selected == "es") {

            string id_season;
            cin>>id_season;
            cout<<"#"<<option_selected<<" "<<id_season<<endl;
            if(cjt_s.exist_season(id_season)) cjt_s.return_season(id_season).write_season();

            else cout<<"error: la sesion no existe"<<endl;
        }

        else if (option_selected == "escribir_problema" or option_selected == "ep") { //ok

            string id_problem;
            cin>>id_problem;
            cout<<"#"<<option_selected<<" "<<id_problem<<endl;
            if (cjt_p.exist_problem(id_problem)) cjt_p.info(id_problem).write_problem();

            else cout<<"error: el problema no existe"<<endl;
        }

        else if (option_selected == "escribir_usuario" or option_selected == "eu"){ //ok

            string id_user;
            cin>>id_user;
            cout<<"#"<<option_selected<<" "<<id_user<<endl;

            if (cjt_u.exist_user(id_user)) cjt_u.info(id_user).write_user();

            else cout<<"error: el usuario no existe"<<endl;
        }





}






int main () {
    //Lectura de problemas
    int num_initial_problems;
    cin>>num_initial_problems;
    cjt_problem cjt_p;
    read_problems(cjt_p, num_initial_problems);


    //Lectura de sesiones
    int num_initial_seasons;
    cin>>num_initial_seasons;
    cjt_season cjt_s;
    read_seasons(cjt_s, num_initial_seasons);


    //Lectura de cursos
    int num_initial_courses;
    cin>>num_initial_courses;
    cjt_course cjt_c;

    read_courses(cjt_c, num_initial_courses, cjt_s);


    //Lectura de usuarios
    int num_initial_users;
    cin>>num_initial_users;
    cjt_user cjt_u;

    read_users(cjt_u, num_initial_users);

    //Inicio del menu
    const string END_PROGRAM = "fin";
    string option;
    cin>>option;

    while (option != END_PROGRAM) {

        menu(option, cjt_p, cjt_s, cjt_c, cjt_u);
        cin>>option;
    }
}
