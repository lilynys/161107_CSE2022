#include<iostream>
// score = a * study_time + b
// y = a * x + b 
// linear hypothesis
class LinearHypothesis {
public:
	double a, b;
	// x-> Hypothesis ->y
	LinearHypothesis()
		: a(0.0f), b(0.0f)
	{};
	float getY(const float& x_input) {
		return a*x_input + b;
	}
};
int main() {
	const float x_data[3] = { 0.0, 1.0 ,2.0 };
	const float y_data[3] = { 0.0, 2.0 , 4.0 };

	LinearHypothesis lh;
	for (int i = 0; i < 3; i++) {
		std::
	}
}