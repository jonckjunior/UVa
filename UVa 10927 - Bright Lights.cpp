#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
vector<ii> p;
#define EPS 1e-9
#define PI acos(-1.0)
#define DEG_to_RAD(theta) ( (theta*PI) / 180.0 )
struct line {
	double a, b, c;
	bool operator < (line other) const{
		if(other.a != a)
			return a < other.a;
		if(other.b != b)
			return b < other.b;
		return c < other.c;
	}
};

struct point_i { int x, y;
	point_i() { x = y = 0; }	
	point_i(int _x, int _y) : x(_x), y(_y) {}
};

struct point{
	double x,y;
	point(){ x = y = 0; }
	point(double xx, double yy): x(xx), y(yy){}
	bool operator < (point other) const{
		if(fabs(x-other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
};

struct vec{
	double x, y;
	vec(double xx, double yy){
		x = xx; y = yy;
	}
};


void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {// vertical line is fine
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	}// default values
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;// IMPORTANT: we fix the value of b to 1.0
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

double dist(point p1, point p2){return hypot(p1.x - p2.x, p1.y - p2.y);}

point rotate(point p, double theta){
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad),
				 p.x * sin(rad) + p.y * cos(rad));
}

bool areParallel(line l1, line l2){return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);}

bool areSame(line l1, line l2){return areParallel(l1,l2) && (fabs(l1.c-l2.c) < EOF);}

bool areIntersect(line l1, line l2, point& p){
	if(areParallel(l1,l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return true;
}

vec toVec(point a, point b){return vec(b.x-a.x, b.y-a.y);}
vec toVector(point a, point b){return vec(b.x-a.x, b.y-a.y);}

vec scale(vec v, double s){return vec(v.x*s, v.y*s);}
vec scaleVector(vec v, double s){return vec(v.x*s, v.y*s);}

point translate(point p, vec v){return point(p.x+v.x, p.y+v.y);}

double dot(vec a, vec b){return (a.x*b.x + a.y*b.y);}

double norm_sq(vec v){return v.x * v.x + v.y * v.y;}

double distToLine(point p, point a, point b, point &c){
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sq(ab);
	c = translate(a, scale(ab,u));
	return dist(p,c);
}

double distToLineSegment(point p, point a, point b, point &c){
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b);
	}
	return distToLine(p, a, b, c);
}

double angle(point a, point o, point b) {
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double angle3p(point a, point o, point b) {
	vec oa = toVector(o, a), ob = toVector(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

bool isOnSameSegment(point p, point a, point b){	
	double ab = dist(a,b);
	double ap = dist(a,p);
	double pb = dist(p,b);
	//printf("checkando (%f,%f) e (%f,%f) = %f\n",p.x, p.y, a.x, a.y, fabs(ab - (ap+pb)));
	//printf("%d\n", fabs(ab - (ap+pb)) <= 0.000000001);
	if(fabs(ab - (ap+pb)) <= 0.000000001) return true;
	else return false;
}

struct state{
	point p;
	int z;
	double a;
	state(point pp, int zz, double aa){
		p = pp; z = zz; a = aa;
	}
	bool operator < (state other) const{
		if(fabs(a-other.a) < EOF){
			if(p.x != other.p.x)
				return p.x < other.p.x;
			return p.y < other.p.y;
		}
		return a < other.a;
	}
};

bool func(state a, state b){
	point zero(0,0);
	return dist(a.p,zero) < dist(b.p, zero);
}

vector<state> vs;
vector<point> final;
map<double, vector<state> > mapa;
int main(){
	int n,x,y,z,caso=0;
	point zero(0,0);
	while(cin >> n, n!=0){
		vs.clear(); mapa.clear(); final.clear();
		for(int i = 0; i < n; i++){
			cin >> x >> y >> z;
			vs.push_back(state(point(x,y), z, atan2(x, y)));
			mapa[vs[i].a].push_back(vs[i]);
		}
		sort(vs.begin(), vs.end());
		map<double, vector<state> >::iterator it;
		for(it = mapa.begin(); it != mapa.end(); it++){
			vector<state> &vm = it->second;
			sort(vm.begin(), vm.end(), func);
			int maxz = -1;
			for(int i = 0; i < vm.size(); i++){
				z = vm[i].z;
				if(z <= maxz)
					final.push_back(vm[i].p);			
				maxz = max(maxz, z);
			}
		}
		sort(final.begin(), final.end());
		printf("Data set %d:\n",++caso);
		if(final.empty()) printf("All the lights are visible.\n");
		else{
			printf("Some lights are not visible:\n");
			for(int i = 0; i < (int)final.size(); i++){
				printf("x = %d, y = %d",(int)final[i].x,(int)final[i].y);
				if(i == final.size() - 1) printf(".\n");
				else printf(";\n");
			}
		}
	}
}
