#include <bits/stdc++.h>
#include "func_ag.cpp"

// Related to energy

double keafter(mass* m,double time){
    pair<double,double> vel = v_after(m,time);
    double mag_value = mag(vel);

    return 0.5*m->mass*mag_value*mag_value;
}   

double peafter(mass* m,double time){
    pair<double,double> pos = r_after(m,time);
    pair<double,double> acc = geta(m);
    return m->mass*acc.second*pos.second + m->mass*acc.first*pos.first;
}

double teafter(mass* m,double time){
    return keafter(m,time) + peafter(m,time);
}

// Related to angle

double angleafter(mass* m,double time){
    pair<double,double> vel = v_after(m,time);
    if(vel.first == 0){
        return 0;
    }
    else{
        return atan2(vel.second,vel.first);
    }
}

// Related to momentum

pair<double,double> setp(mass* m ,pair<double,double> p){
    m->velocity.first = p.first / m->mass;
    m->velocity.second = p.second / m->mass;
}