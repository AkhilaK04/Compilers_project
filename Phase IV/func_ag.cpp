#include <bits/stdc++.h>
using namespace std;

class mass{
public:

    int mass;
    pair<double,double> position;
    pair<double,double> velocity;
    pair<double,double> acceleration;

};

// Related to Magnitude

double mag(pair<double,double> vec){
    double vecx = vec.first;
    double vecy = vec.second;
    double magnitude = sqrt(vecx * vecx + vecy * vecy);
    return magnitude;
}

// Related to Position

pair<double,double> setr(mass* m, pair<double,double> r){
    m->position = r;
}

pair<double,double> addr(mass* m, pair<double,double> r){
    m->position.first = m->position.first + r.first;
    m->position.second = m->position.second + r.second;
}

pair<double,double> r_after(mass* m, double t){
    m->position.first = m->position.first + m->velocity.first*t + 0.5*m->acceleration.first*t*t;
    m->position.second = m->position.second + m->velocity.second*t + 0.5*m->acceleration.second*t*t;
}

// Related to velocity

pair<double,double> setv(mass* m, pair<double,double> vec){
    m->velocity = vec;
}

pair<double,double> addv(mass* m, pair<double,double> v){
    m->velocity.first = m->velocity.first + v.first;
    m->velocity.second = m->velocity.second + v.second;
}

pair<double,double> v_after(mass* m, double t){
    m->velocity.first = m->velocity.first + m->acceleration.first*t;
    m->velocity.second = m->velocity.second + m->acceleration.second*t;
}

pair<double,double> v_after(mass* m,  pair<double,double> r){
    m->velocity.first = sqrt(pow(m->velocity.first, 2) + 2 * m->acceleration.first * r.first);
    m->velocity.second = sqrt(pow(m->velocity.second, 2) + 2 * m->acceleration.second * r.second);
}

// Related to accerlation

pair<double,double> seta(mass* m, pair<double,double> vec){
    m->acceleration = vec;
}

pair<double,double> adda(mass* m, pair<double,double> a){
    m->acceleration.first = m->acceleration.first + a.first;
    m->acceleration.second = m->acceleration.second + a.second;
}