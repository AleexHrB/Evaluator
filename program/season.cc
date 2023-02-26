#include "BinTree.hh"
#include "season.hh"
#include <iostream>
#include <vector>




Season::Season() {

}

Season::Season(const string& id_season) {
    this->ID = id_season;
}


void Season::add_problems() {
    i_add_problems(tree_problems, height, m_problems_season);

}

void Season::i_add_problems(BinTree<string>& T, int& height,   map<string, pair<string, string>>& m) {

    string id_problem;
    cin>>id_problem;

    if (id_problem != "0") {
        ++height;
        BinTree<string> left;
        i_add_problems(left,height, m);

        BinTree<string> right;
        i_add_problems(right,height, m);

        T = BinTree<string>(id_problem, left, right);

        string p_left = "-1";
        string p_right = "-1";
        if (not T.left().empty()) p_left = T.left().value();
        if (not T.right().empty()) p_right = T.right().value();
        m.insert(make_pair(id_problem, make_pair(p_left, p_right)));
    }
}


bool Season::has_problem(const string& id_problem) const {

    return i_has_problem(id_problem, m_problems_season);
}

bool Season::i_has_problem(const string& id_problem, const   map<string, pair<string, string>>& m) {
   return m.find(id_problem) != m.end();
}

string Season::consult_id() const {
    return ID;
}

void Season::show_problems(const BinTree<string>& T) {


    if (not T.empty()) {
        cout<<"(";
        show_problems(T.left());
        show_problems(T.right());
        cout<<T.value()<<")";
    }



}

void Season::write_season() const {
  cout<<ID<<" "<<height<<" ";
  show_problems(tree_problems);
  cout<<endl;
}

string Season::firts_problem() const {
    return tree_problems.value();
}

pair<string, string> Season::next_problems(const string& id_problem) const{

    return m_problems_season.find(id_problem) -> second;
}

int Season::consult_num_problems() const {
    return m_problems_season.size();
}

vector<string> Season::get_problems() const {

    vector<string> v(m_problems_season.size());
    int i = 0;
    for (map<string, pair<string, string>>::const_iterator it = m_problems_season.begin(); it != m_problems_season.end(); ++it) {
      v[i] = it->first;
      ++i;
    }

    return v;
}
