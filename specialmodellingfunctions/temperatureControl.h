/*
 * temperatureControl.h
 *
 *  Created on: Dec 26, 2016
 *      Author: root
 */

#ifndef TEMPERATURECONTROL_H_
#define TEMPERATURECONTROL_H_

#include <vector>
#include <math.h>

#include "Vector.h"
#include "Particle.h"

namespace phycoub {

void temperatureControl(const double& temp, const double& kB, Particle& particle);
void temperatureControl(const double& temp, const double& kB, Particle* particle);

void temperatureControl(const double& temp, const double& kB, int num, std::vector<Particle>* particles, ...);
void temperatureControl(const double& temp, const double& kB, int num, std::vector<Particle*>* particles, ...);

} /* namespace phycoub */

#endif /* TEMPERATURECONTROL_H_ */