#include "problem.hh"
#include <iostream>
using namespace std;


Problem::Problem() {
  
}

Problem::Problem(const string& id) {
  this->id = id;
}

string Problem::consult_id() const{
  return id;
}

int Problem::total_sends() const{
  return total;
}

int Problem::total_correct_sends() const{
  return total_correct;
}

void Problem::update_correct_problem() {
  ++total_correct;
  ++total;
}

void Problem::update_fail_problem() {
  ++total;
}

void Problem::write_problem() const{

  cout<<id<<"("<<total<<","<<total_correct<<","<<show_ratio()<<")"<<endl;
}

double Problem::show_ratio() const {

  return (1.0+total)/(1.0+total_correct);
}
