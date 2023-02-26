#include "cjt_problem.hh"
#include <map>
#include <set>
#include <string>
#include <iostream>
#include "problem.hh"
using namespace std;

cjt_problem::cjt_problem() {
  map<string, Problem> m;
  m_problems = m;
}

void cjt_problem::add_problem(const string& id_problem) {
  Problem p(id_problem);
  m_problems.insert(make_pair(id_problem, p));

}


void cjt_problem::list_problems() {

  auto lamb = [](const Problem& p1, const Problem& p2)->bool {

    double ratio1 = p1.show_ratio();
    double ratio2 = p2.show_ratio();

    if (ratio1 != ratio2) return ratio1 < ratio2;

    else return p1.consult_id() < p2.consult_id();
  };


  set<Problem, decltype(lamb)> auxiliar(lamb);

  for (map<string, Problem>::iterator it = m_problems.begin(); it != m_problems.end(); ++it) auxiliar.insert(it->second);

  for (decltype(auxiliar)::const_iterator it = auxiliar.begin(); it!= auxiliar.end(); ++it) it->write_problem();
  }

bool cjt_problem::exist_problem(string& id_problem) const{
  return m_problems.find(id_problem) != m_problems.end();
}

int cjt_problem::num_problems() const{
  return m_problems.size();
}

Problem& cjt_problem::info(string& id_problem){
  return m_problems.find(id_problem) -> second;
}

void cjt_problem::update(const string& id_problem, Problem& p) {
  m_problems.erase(id_problem);
  m_problems.insert(make_pair(id_problem, p));
}
