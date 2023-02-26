#include "cjt_season.hh"
#include <vector>
#include <map>
using namespace std;
#ifndef COURSE_HH
#define COURSE_HH



class Course {

    public:
    //Constructoras
    Course();

    Course(int id);

    int num_users_completed_course() const;

    int num_users_registred() const;

    int consult_num_seasons() const;

    void read_seasons(int num_seasons, cjt_season& cjt_s);

    void write_course() const;

    void update_num_users(int n);

    string show_id_season_problem(const string& id_probelm) const;

    void sign_out_course(const string& reason);

    Season& info_season(int n);

    int consult_num_problems() const;

    void new_course(bool& success, cjt_season& cjt_s);



    private:
    int id_course;
    int num_users_completed = 0;
    int num_users = 0;
    vector<Season> v_season;
    map<string, string> problem_season;





};

#endif
