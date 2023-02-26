#include <map>
#include "user.hh"
#include "course.hh"
#include <iostream>
using namespace std;




User::User() {

}

User::User(string id) {
  this->id = id;
}

void User::sign_up_course(int id_course, Course& c) {
  actual_course = id_course;
  has_logged =  true;
  int n = c.consult_num_seasons();
  for (int i = 0; i<n; ++i) {
    Season& s = c.info_season(i+1);
    string id_problem = s.firts_problem();

    add_problem(id_problem, false, 0, s);
  }

  }



bool User::has_completed_actual_course(const Course& c) const {
  return num_result_problems_this_course == c.consult_num_problems();
}

bool User::has_logged_one_course() const {
  return has_logged;
}

int User::id_actual_course() const {
  return actual_course;
}

void User::write_user() const {
  cout<<id<<"("<<total_sends<<","<<total_correct_sends<<","<<trys_problem;
  cout<<",";
  if (has_logged) cout<<actual_course;
  else cout<<"0";

  cout<<")"<<endl;
}

void User::show_result_problems() const{

  for (map<string,pair<int, bool>>::const_iterator it = problems_user.begin(); it != problems_user.end(); ++it) {
    if (it->second.second) cout<<it->first<<"("<<it->second.first<<")"<<endl;
  }
}
//bool = ha resuelto el problema
void User::show_avaible_problems() const{

  for (map<string,pair<int, bool>>::const_iterator it = problems_user.begin(); it != problems_user.end(); ++it) {

    if (not it->second.second) cout<<it->first<<"("<<it->second.first<<")"<<endl;
  }

}

void User::send_problem(const string& id_problem, int result) {

  map<string, pair<int, bool>>::iterator it = problems_user.find(id_problem);
  ++total_sends;
  it->second.first++;

  if (it->second.first == 1) ++trys_problem;

  if (result == 1) {
    it->second.second = true;
    ++total_correct_sends;
    ++num_result_problems_this_course;
  }


}

void User::add_problem(const string& id_problem, bool result, int num_sends, const Season& s) {



  if (id_problem != "-1") {

  map<string, pair<int, bool>>::iterator it = problems_user.find(id_problem);

  if (it == problems_user.end()) problems_user.insert(make_pair(id_problem, make_pair(num_sends, result)));

  else if (it->second.second){
    ++num_result_problems_this_course;
    pair<string, string> p = s.next_problems(id_problem);
    add_problem(p.first, false, 0, s);
    add_problem(p.second, false, 0, s);
  }

  }
}

void User::log_out_course() {
  num_result_problems_this_course = 0;
  actual_course = 0;
  has_logged = false;
}
