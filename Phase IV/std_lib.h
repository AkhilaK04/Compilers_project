#include <bits/stdc++.h>
using namespace std; 

class Mass{
public:
	double mass;
	pair<double,double> position;
	pair<double,double> velocity;
	pair<double,double> acceleration;

	Mass(int initialMass = 1) {
		mass = initialMass;
		position.first = 0.0;
		position.second = 0.0;
		velocity.first = 0.0;
		velocity.second = 0.0;
		acceleration.first = 0.0;
		acceleration.second = 0.0;
	}
};


bool equal_double(double val1,double val2){
	if(abs(val1 - val2) < 0.01) return true;
	return false;
}

double check_r(double r,double s,double v,double acc){
	double time;

	// r = s + v*t + 0.5*acc*t*t;
	// Calculate the coefficients for the quadratic equation
	double a = 0.5*acc;
	double b = v;
	double c = s;

	
	if(a == 0 && v != 0 ){
		return (r-s)/v;
	}else if(a == 0){
		if(v==0 && (equal_double(r,s))) return 0;
		return -1;
	}
	// Calculate the discriminant
	double discriminant = b*b - 4*a*c;
	if(discriminant < 0){
		cout << "Error: Mass cannot reach the specified position." << endl;
	return -1;
	} 

	// Calculate the time using the quadratic formula
	double t1 = (-b + sqrt(discriminant)) / (2 * a);
	double t2 = (-b - sqrt(discriminant)) / (2 * a);

	// Choose the positive time (ignore negative time)
	double time_to_reach = (t2 > 0) ? t2 : t1;
	if(time_to_reach < 0) return -1;
	return time_to_reach;
}

void setm(Mass* m, double r){
	m->mass = r;
}

double getm(Mass* m){
	return m->mass;
}

// Related to Magnitude

double mag(pair<double,double> vec){
	double vecx = vec.first;
	double vecy = vec.second;
	double magnitude = sqrt(vecx * vecx + vecy * vecy);
	return magnitude;
}


// Related to Position

void setr(Mass* m, pair<double,double> r){
	m->position = r;
}

void addr(Mass* m, pair<double,double> r){
	m->position.first = m->position.first + r.first;
	m->position.second = m->position.second + r.second;
}
pair<double,double> r_after(Mass* m, double t){
	pair<double,double> temp;
	temp.first = m->position.first + m->velocity.first*t + 0.5*m->acceleration.first*t*t;
	temp.second = m->position.second + m->velocity.second*t + 0.5*m->acceleration.second*t*t;
	return temp;
}

pair<double,double> getr(Mass* m){
	return m->position;
}


// Related to velocity

void setv(Mass* m, pair<double,double> vec){
	m->velocity = vec;
}

void addv(Mass* m, pair<double,double> v){
	m->velocity.first = m->velocity.first + v.first;
	m->velocity.second = m->velocity.second + v.second;
}

pair<double,double> v_after(Mass* m, double t){
	pair<double,double> temp;
	temp.first = m->velocity.first + m->acceleration.first*t;
	temp.second = m->velocity.second + m->acceleration.second*t;
	return temp;
}

pair<double,double> v_after(Mass* m,  pair<double,double> r){
	pair<double,double> temp;
	temp.first = sqrt(pow(m->velocity.first, 2) + 2 * m->acceleration.first * r.first);
	temp.second = sqrt(pow(m->velocity.second, 2) + 2 * m->acceleration.second * r.second);
	return temp;
}

pair<double,double> getv(Mass* m){
	return m->velocity;
}


// Related to accerlation

void seta(Mass* m, pair<double,double> vec){
	m->acceleration = vec;
}

void adda(Mass* m, pair<double,double> a){
	m->acceleration.first = m->acceleration.first + a.first;
	m->acceleration.second = m->acceleration.second + a.second;
}

pair<double,double> geta(Mass* m){
	return m->acceleration;
}


// Related to energy

double keafter(Mass* m,double time){
	pair<double,double> vel = v_after(m,time);
	double mag_value = mag(vel);
	return 0.5*m->mass*mag_value*mag_value;
}   

double peafter(Mass* m,double time){
	pair<double,double> pos = r_after(m,time);
	pair<double,double> acc = geta(m);
	return m->mass*acc.second*pos.second + m->mass*acc.first*pos.first;
}


double teafter(Mass* m,double time){
	return keafter(m,time) + peafter(m,time);
}



// Related to angle

double angleafter(Mass* m,double time){
	pair<double,double> vel = v_after(m,time);
	if(vel.first == 0){
		return 0;
	}
	else{
		return atan2(vel.second,vel.first);
	}
}


// Related to momentum

void setp(Mass* m ,pair<double,double> p){
	m->velocity.first = p.first / m->mass;
	m->velocity.second = p.second / m->mass;
}


// Related to Collision

double collide(Mass* m1, Mass* m2, double e) {
	// Check if positions are the same
	if (equal_double(m1->position.first,m2->position.first) && equal_double(m1->position.second,m2->position.second)) {
		// Calculate relative velocity
		double v_rel_x = m2->velocity.first - m1->velocity.first;
		double v_rel_y = m2->velocity.second - m1->velocity.second;

		// Calculate final velocities using coefficient of restitution
		double v1_final_x = (m1->mass * m1->velocity.first + m2->mass * m2->velocity.first + e * m2->mass * v_rel_x) / (m1->mass + m2->mass);
		double v1_final_y = (m1->mass * m1->velocity.second + m2->mass * m2->velocity.second + e * m2->mass * v_rel_y) / (m1->mass + m2->mass);
		double v2_final_x = v1_final_x - m1->velocity.first + m2->velocity.first;
		double v2_final_y = v1_final_y - m1->velocity.second + m2->velocity.second;

		// Calculate energy loss
		double E_initial = 0.5 * m1->mass * (m1->velocity.first * m1->velocity.first + m1->velocity.second * m1->velocity.second) + 0.5 * m2->mass * (m2->velocity.first * m2->velocity.first + m2->velocity.second * m2->velocity.second);
		double E_final = 0.5 * (m1->mass + m2->mass) * (v1_final_x * v1_final_x + v1_final_y * v1_final_y + v2_final_x * v2_final_x + v2_final_y * v2_final_y);
		double E_loss = E_initial - E_final;

		// Update velocities
		m1->velocity = {v1_final_x, v1_final_y};
		m2->velocity = {v2_final_x, v2_final_y};
		return E_loss;

	} else {
		// Positions are not the same, no collision
		cout << "Error: No collision, positions are different." << endl;
		return 0;
	}
}

double collide(Mass* m1, Mass* m2) {
	// Check if positions are the same
	if (equal_double(m1->position.first,m2->position.first) && equal_double(m1->position.second,m2->position.second)) {

		// Calculate final velocities and energy loss
		double v1_final_x = (m1->mass * m1->velocity.first + m2->mass * m2->velocity.first) / (m1->mass + m2->mass);
		double v1_final_y = (m1->mass * m1->velocity.second + m2->mass * m2->velocity.second) / (m1->mass + m2->mass);
		double v2_final_x = v1_final_x - m1->velocity.first + m2->velocity.first;
		double v2_final_y = v1_final_y - m1->velocity.second + m2->velocity.second;

		// Calculate energy loss (assuming perfectly elastic collision)
		double E_initial = 0.5 * m1->mass * (m1->velocity.first * m1->velocity.first + m1->velocity.second * m1->velocity.second) + 0.5 * m2->mass * (m2->velocity.first * m2->velocity.first + m2->velocity.second * m2->velocity.second);
		double E_final = 0.5 * (m1->mass + m2->mass) * (v1_final_x * v1_final_x + v1_final_y * v1_final_y + v2_final_x * v2_final_x + v2_final_y * v2_final_y);
		double E_loss = E_initial - E_final;

		// Update velocities
		m1->velocity = {v1_final_x, v1_final_y};
		m2->velocity = {v2_final_x, v2_final_y};
		return E_loss;

	} else {
		// Positions are not the same, no collision
		cout << "Error: No collision, positions are different." << endl;
		return 0;
	}
}

double dotProduct(pair<double, double> v1, pair<double, double> v2) {
	return v1.first * v2.first + v1.second * v2.second;
}

double magnitude(pair<double, double> v) {
	return sqrt(v.first * v.first + v.second * v.second);
}

double time_to_collide(Mass* m1, Mass* m2) {
	// Calculate relative position, velocity, and acceleration
	pair<double, double> relative_position = {m2->position.first - m1->position.first, m2->position.second - m1->position.second};
	pair<double, double> relative_velocity = {m2->velocity.first - m1->velocity.first, m2->velocity.second - m1->velocity.second};
	pair<double, double> relative_acceleration = {m2->acceleration.first - m1->acceleration.first, m2->acceleration.second - m1->acceleration.second};
	double along_x = check_r(0,relative_position.first,relative_velocity.first,relative_acceleration.first);
	double along_y = check_r(0,relative_position.second,relative_velocity.second,relative_acceleration.second);
	if((equal_double(along_x,along_y)) && (along_x != -1)) return along_x;
	if(along_y == 0) return along_x;
	else if(along_x == 0) return along_y;
	return -1;
}


// DISTANCE AFTER TIME t.

pair<double, double> s_after(Mass* m, double t) {
	// Calculate the new position using the kinematic equation
	double s_x = m->position.first + m->velocity.first * t + 0.5 * m->acceleration.first * t * t;
	double s_y = m->position.second + m->velocity.second * t + 0.5 * m->acceleration.second * t * t;
	return {s_x, s_y};
}


// RADIUS OF CURVATURE

double roc_after(Mass* m, double t) {

	// Calculate the new position using the kinematic equation
	double s_x = m->position.first + m->velocity.first * t + 0.5 * m->acceleration.first * t * t;
	double s_y = m->position.second + m->velocity.second * t + 0.5 * m->acceleration.second * t * t;

	// Calculate the new velocity using the kinematic equation
	double v_x = m->velocity.first + m->acceleration.first * t;
	double v_y = m->velocity.second + m->acceleration.second * t;

	// Calculate the magnitude of velocity
	double v_magnitude = sqrt(v_x * v_x + v_y * v_y);

	// Check if the magnitude of velocity is non-zero to avoid division by zero
	if (v_magnitude != 0) {
		// Calculate the radius of curvature using the formula: roc = v_magnitude / |acceleration perpendicular to velocity|
		
		double acc =  sqrt(m->acceleration.first * m->acceleration.first + m->acceleration.second * m->acceleration.second);
		if(acc == 0) return INT_MAX;
		double roc = v_magnitude / sqrt(m->acceleration.first * m->acceleration.first + m->acceleration.second * m->acceleration.second);
		return roc;
	} else {
		// Velocity magnitude is zero, so the radius of curvature is infinite
		return 0;
	}
}


// Momentum for m in time t

pair<double, double> p_after(Mass* m, double t) {
	// Calculate the new velocity using the kinematic equation
	double v_x = m->velocity.first + m->acceleration.first * t;
	double v_y = m->velocity.second + m->acceleration.second * t;

	// Calculate the momentum after time t
	double p_x = m->mass * v_x;
	double p_y = m->mass * v_y;
	return {p_x, p_y};
}

// time taken for reach position r

double time_to_r(Mass* m, pair<double, double> r) {
		double along_x = check_r(r.first,m->position.first,m->velocity.first,m->acceleration.first);
		double along_y = check_r(r.second,m->position.second,m->velocity.second,m->acceleration.second);
		if((equal_double(along_x,along_y)) && (along_x != -1)) return along_x;
	return -1;
}

double time_to_r(Mass* m, double r1, string r2) {
	if(r2 == "?"){
		double pos = r1;
		double time = check_r(pos,m->position.first,m->velocity.first,m->acceleration.first);
		if(time < 0) return -1;
		return time;
	}
	return -1;
}

double time_to_r(Mass* m, string r1, double r2) {
	if(r1 == "?"){
		double pos = r2;
		double time = check_r(pos,m->position.second,m->velocity.second,m->acceleration.second);
		if(time < 0) return -1;
		return time;
	}
	return -1;
}

double check_v(double v,double v_old,double acc){
	double time;
	// v = u + a*t
	// Linear equation.
	
	if(acc == 0) return -1;
	time = (v-v_old)/acc;
	if(time < 0) return -1;
	return time;
}


// TIME TAKEN TO ACQUIRE velocity v.

double time_to_v(Mass* m, double v1, string v2) {
	if(v2 == "?"){
		double vel = v1;
		double time = check_v(vel,m->velocity.first,m->acceleration.first);
		if(time < 0) return -1;
		return time;
	}
	return -1;
}

double time_to_v(Mass* m, string v1, double v2) {
	if(v1 == "?"){
		double vel = v2;
		double time = check_v(vel,m->velocity.second,m->acceleration.second);
		if(time < 0) return -1;
		return time;
	}
	return -1;
}

double time_to_v(Mass* m, pair<double, double> v) {
	double along_x = check_v(v.first,m->velocity.first,m->acceleration.first);
	double along_y = check_v(v.second,m->velocity.second,m->acceleration.second);
	if((equal_double(along_x, along_y)) && (along_x != -1)) return along_x;
	return -1;
}

double sin_val(double angle) {
	double result = sin(angle * (M_PI / 180.0));
	int decimalPlaces =  3;
	return round(result * pow(10, decimalPlaces)) / pow(10, decimalPlaces);
}

double cos_val(double angle) {
	double result = cos(angle * (M_PI / 180.0));
	int decimalPlaces =  3;
	return round(result * pow(10, decimalPlaces)) / pow(10, decimalPlaces);
}

double tan_val(double angle) {
	double result = tan(angle * (M_PI / 180.0));
	int decimalPlaces =  3;
	return round(result * pow(10, decimalPlaces)) / pow(10, decimalPlaces);
}