#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define oo 0x3f3f3f3fLL
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[] { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[] { 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#else
#endif
}
typedef complex<double> point;  // it can be long long not double
template<class T>
istream& operator>>(istream &is, complex<T> &p) {
	T value;
	is >> value;
	p.real(value);
	is >> value;
	p.imag(value);
	return is;
}

#define PI acos(-1.0)
#define EPS 1e-8
#define X real()   // can sign values point a; a.real(5) , a.image(2)
#define Y imag()
#define angle(a)  (atan2((a).imag(), (a).real())) // angle with orignial
#define dist(a)   (hypot((a).imag(), (a).real())) // distance between two point send diff
#define length(a) dist(a)
#define vec(a,b)  ((b)-(a)) // diff x1-x2 , y1-y2 return vec (x,y)
#define rotateO(p,ang)    ((p)*exp(point(0,ang)))  // angle should be in radian aroun origin
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)// rotate around point
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS) // check to points same or not
#define dp(a,b)   ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep dot product A.B
#define cp(a,b)   ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel cross product = area of parllelogram
#define norm(a)  (norm(a))  // return x^2 + y^2 a is point can use dp(a,a)
#define reflectO(v,m)  (conj((v)/(m))*(m))
#define normalize(a)            (a)/dist(a)
double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}
double getAngle_A_abc(double a, double b, double c) {
	return acos(((b * b + c * c - a * a) / (2 * b * c)));
}
int dcmp(long double x, long double y) {
	return fabs(x - y) < EPS ? 0 : x < y ? -1 : 1;
}

void fix(double &a) {
	a = fmod(fmod(a, 2 * PI) + 2 * PI, 2 * PI);
	a = min(a, 2 * PI - a);
}

int main() {
	run();
	int t;
	cin >> t;
	while (t--) {
		point p[4];
		for (auto &it : p)
			cin >> it;
		double angle1 = angle(vec(p[0],p[2])) - angle(vec(p[0],p[1]));
		fix(angle1);
		double angle2 = angle(vec(p[2],p[0])) - angle(vec(p[2],p[3]));
		fix(angle2);
		int cmp = dcmp(angle1, angle2);
		if (cmp == -1)
			cout << "Hero\n";
		else if (cmp == 0)
			cout << "0\n";
		else
			cout << "Heroine\n";
	}
}
