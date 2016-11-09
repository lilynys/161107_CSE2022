
#include <iostream>
using namespace std;
#define ARRNUM 100000
double x_data[ARRNUM];
double y_data[ARRNUM];
//score = a *study_time + b
//y=a*x+b
class LinearHypothesis
{
public:
	double a, b;
	// x, y 
	// 기법에 따라서 저장 할 수 있음

	LinearHypothesis() :a(0), b(0) {

	}
	// y = a*x + b;
	double getY(const double& x_input) {
		return (a*x_input + b);
		// y : return value
	}
};

int main()
{
	// linear regression
	// gradient descent method
	// 0 -> 0
	// 1 -> 2
	// 2 -> 4
	// 2.5 -> ?!
	for (int i = 0; i < ARRNUM; i++) {
		for (int j = 0; j < 10; j++) {
			x_data[i] = -5 + j;
		}
	}
	// input data set

	for (int i = 0; i < ARRNUM; i++) {
		y_data[i] = 3.0 * x_data[i] + 1 + (double)rand() / RAND_MAX;
	}

	// x_data -> ydata 
	/*
	LinearHypothesis lh;

	for (int i = 0; i < 3; i++) {
		std::cout << lh.getY(x_data[i]) << std::endl;
	}
	*/
	// before learn
	LinearHypothesis lh;
	double lr = 0.01; //learning rate
	for (int tr = 0; tr < 1000; tr++) {
	for (int i = 0; i < ARRNUM; i++) {
		const double error = y_data[i] - lh.getY(x_data[i]); // error가 0 이면 ...

		const double sqr_error = 0.5*error*error; //Ω∫ƒ˘æÓµÂø°∑Ø : «◊ªÛ æÁºˆ --> ¡§»Æº∫¿ª ¿ß«ÿ double∑Œ
												  //a=[0..10], a^2 =[0 .. 100]

												  //a+ da -> sqr_error up/down
												  //sqr+drror = (y_target - (a*x +b))^2
												  //			= (y_target - a*x -b)^2
												  //d_se/d_a = 2*(y_target - a*x -b)*(-x)
												  //d_se/d_b = 2*(y_target - a*x -b)*(-1)
		const double dse_d_a = 2 * error*(-x_data[i]);
		const double dse_d_b = 2 * error*(-1);
		lh.a -= dse_d_a*lr;
		lh.b -= dse_d_b*lr;

		//cout << y_data[i] << " " << lh.getY(x_data[i]) << endl;
		//std::cout << lh.a << " " << lh.b << endl;
	}
}
	std::cout << "a :"<<lh.a << " " <<"b: "<< lh.b << endl;
	std::cout << " x = 2.5 y = "<<lh.getY(2.5) << endl;
}