#include "cjt_course.hh"
#include "course.hh"
#include <vector>
#include <iostream>
using namespace std;



cjt_course::cjt_course() {
    v_course = vector<Course>(0);
}

void cjt_course::add_course(const Course& c) {

    v_course.push_back(c);

}

int cjt_course::consult_num_courses() const {
    return v_course.size();
}

Course& cjt_course::info(int id_course) {
    return v_course[id_course-1];

}


bool cjt_course::exist_course(int id_course) const {
    id_course -= 1;
    return id_course < v_course.size() and id_course >= 0;
}

void cjt_course::list_courses() const {
    int n = v_course.size();

    for (int i = 0; i<n; ++i) {
        v_course[i].write_course();
    }
}

void cjt_course::update(Course& c, int id_course) {
    v_course[id_course-1] = c;
}
