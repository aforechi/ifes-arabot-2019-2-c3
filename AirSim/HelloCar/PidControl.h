#pragma once

#include "common/PidController.hpp"

class PidControl : msr::airlib::PidController
{
public:
	PidControl(double p, double i, double d) {
		kProportional_ = p;
		kIntegral_ = i;
		kDerivative_ = d;
	};
	void update(double current_velocity, double desired_velocity) {

	};
	~PidControl() {};
};

