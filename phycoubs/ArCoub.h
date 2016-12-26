/*
 * ArCoub.h
 *
 *  Created on: 20 дек. 2016 г.
 *      Author: serv
 */

#ifndef ARCOUB_H_
#define ARCOUB_H_

#include <vector>

#include "Vector.h"
#include "Particle.h"
#include "CreateField.h"
#include "FeelField.h"
#include "math.h"

#include "ThermostatBorder.h"
#include "BorderFieldCondition.h"
#include "LeapFrog.h"
#include "LDFieldFunction.h"
#include "LDInterworking.h"

namespace phycoub {

class ArCoub {
public:
	ArCoub();
	virtual ~ArCoub();

	void phyCoub();

	double dt_ = 1E-15, k_ = 1.38E-23, z_ = 0.0, temp = 100.0;
	double mAr_ = 6.6E-26, epsAr_ = 1.67E-21, aAr_ = 3.4E-10, radiusCut_ = 2.5 * aAr_;
	Vector borders_{aAr_*20};

	std::vector<Particle> argon_;
private:
	ThermostatBorder thermostatBorder{&borders_, &k_, &temp};
	BorderFieldCondition borderFieldCondition_{BorderFieldCondition()};
	LeapFrog leapFrog{LeapFrog()};

	LDFieldFunction argonField_{aAr_, aAr_, epsAr_};
	LDInterworking argontInterworking;


	std::vector<CreateField> createField_;
	std::vector<FeelField> feelField_;

};

} /* namespace phycoub */

#endif /* ARCOUB_H_ */
