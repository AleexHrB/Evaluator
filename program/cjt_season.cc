#include "season.hh"
#include "cjt_season.hh"
#include <map>
#include <iostream>
using namespace std;

cjt_season::cjt_season() {
  map<string, Season> m;
  m_season = m;
}

void cjt_season::add_season(const string& id_season, const Season& s) {

    m_season[id_season] = s;
}
/*
void cjt_season::list_season() {

}

*/
bool cjt_season::exist_season(const string& id_season) const{
    return m_season.find(id_season) != m_season.end();
}
int cjt_season::num_seasons() const {
    return m_season.size();
}

Season& cjt_season::return_season(const string& id_season) {

    return m_season.find(id_season) -> second;
}

void cjt_season::list_seasons() const {

    for (map<string, Season>::const_iterator it = m_season.begin(); it != m_season.end(); ++it) {
        it->second.write_season();

    }
}
