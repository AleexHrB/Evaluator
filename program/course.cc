#include "course.hh"
#include "cjt_season.hh"
#include "season.hh"
#include <iostream>
#include <set>
using namespace std;


Course::Course(){
 v_season = {};
}

Course::Course(int id) {
    this->id_course  = id;
    v_season = {};
}



int Course::num_users_completed_course() const {
    return num_users_completed;
}


void Course::read_seasons(int num_seasons, cjt_season& cjt_s) {

  v_season.resize(num_seasons);


  for (int i = 0; i<num_seasons; ++i) {

    string id_season;
    cin>>id_season;


    v_season[i] = cjt_s.return_season(id_season);
    int n = v_season[i].consult_num_problems();
    vector<string> v = v_season[i].get_problems();
    string id_problem = v_season[i].consult_id();

    for (int j = 0; j<n; ++j) {
      problem_season.insert(make_pair(v[j], id_problem));
    }
  }


}

int Course::num_users_registred() const {
    return num_users;
}

int Course::consult_num_seasons() const {
  return v_season.size();
}

void Course::write_course() const {

  cout<<id_course<<" "<<num_users_completed<<" "<<num_users<<" "<<v_season.size()<<" (";
  bool aux = false;
  for (vector<Season>::const_iterator it = v_season.begin(); it!= v_season.end(); ++it) {
      if (aux) cout<<" ";
      cout<<it->consult_id();
      aux = true;
  }

  cout<<")"<<endl;
}

void Course::update_num_users(int n) {
  num_users += n;
}

string Course::show_id_season_problem(const string& id_problem) const{

  map<string, string>::const_iterator it = problem_season.find(id_problem);
  if (it == problem_season.end()) return "-1";
  return it->second;
}

void Course::sign_out_course(const string& reason) {
  --num_users;
  if (reason != "baja") ++num_users_completed;

}

Season& Course::info_season(int n){
  return v_season[n-1];
}



int Course::consult_num_problems() const {
  return problem_season.size();
}

void Course::new_course(bool& success, cjt_season& cjt_s) {

  int num_seasons;
  cin>>num_seasons;
  v_season.resize(num_seasons);

  string id_season;
  cin>>id_season;
  Season s = cjt_s.return_season(id_season);

  vector<string> v = s.get_problems();
  int n = v.size();

  for (int i = 0; i<n; ++i) problem_season.insert(make_pair(v[i], id_season));

  v_season[0] = s;

  int i = 1;
  bool error = false;

  while (not error and i<num_seasons) {

    cin>>id_season;
    s = cjt_s.return_season(id_season);
    v = s.get_problems();
    int j = 0;
    int k = v.size();
    while (not error and j<k) {
      error = not problem_season.insert(make_pair(v[j], id_season)).second;
      ++j;
    }
    v_season[i] = s;
    ++i;
  }


  success = not error;
}
