#include "cjt_user.hh"
#include "course.hh"
#include "user.hh"
#include <map>
using namespace std;


/*
void cjt_user::list_users() const{

}
*/

cjt_user::cjt_user() {
  map<string, User>m;
  m_users = m;
}

bool cjt_user::exist_user(const string& id_user) const{
    return m_users.find(id_user) != m_users.end();
}

int cjt_user::num_users() const {
    return m_users.size();
}

User& cjt_user::info(const string& id_user) {

    return m_users.find(id_user) -> second;
}


void cjt_user::add_user(User& u, const string& id_user) {
    m_users.insert(make_pair(id_user, u));
}

void cjt_user::delete_user(const string& id_user) {
    m_users.erase(id_user);
}

void cjt_user::list_users() const{

    for (map<string, User>::const_iterator it = m_users.begin(); it != m_users.end(); ++it) {
        it->second.write_user();
    }
}

void cjt_user::update(const User& u, const string& id_user) {
    m_users.erase(id_user);
    m_users.insert(make_pair(id_user, u));
}
