/*
 * ElasticBorder.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: root
 */

#include <ElasticBorder.h>
#include "Particle.h"

namespace phycoub {

ElasticBorder::ElasticBorder(Vector* borders): BorderCondition(borders) {}
ElasticBorder::~ElasticBorder() {}

void ElasticBorder::psyMove(const Vector& move, Particle& particle) {
	Vector move_;
	IntersectionVector intersectionVector = getIntersectionVector(move, particle);

	if(!intersectionVector.intersection) {
		particle.coordinate_ += move;
	} else {
		Vector move_ = move;
		do {
			particle.coordinate_ = intersectionVector.intersectionMark;
			Vector elasticDirection((particle.coordinate_ + move_) - intersectionVector.intersectionMark);
			switch(intersectionVector.planeIntersection) {
			case 1:
				elasticDirection.x_ = -elasticDirection.x_;
				break;
			case 2:
				elasticDirection.y_ = -elasticDirection.y_;
				break;
			case 3:
				elasticDirection.z_ = -elasticDirection.z_;
				break;
			case 4:
				elasticDirection.x_ = -elasticDirection.x_;
				break;
			case 5:
				elasticDirection.y_ = -elasticDirection.y_;
				break;
			case 6:
				elasticDirection.z_ = -elasticDirection.z_;
				break;
			}
			move_ = elasticDirection;
			intersectionVector = getIntersectionVector(move_, particle);
		} while (intersectionVector.intersection);
		particle.coordinate_ += move_;
	}
}

const ElasticBorder::IntersectionVector ElasticBorder::getIntersectionVector(const Vector& move, const Particle& particle) {
	IntersectionVector result_;
	PlaneMarket planeMarket_;
	Vector newCoordinate(particle.coordinate_ + move);
	int lastIntersection = 0;

	result_.intersectionMark = particle.coordinate_ + move;
	result_.intersection = !isMarkInBorder(result_.intersectionMark);
	if(!result_.intersection) {
		return result_;
	}

	while(!isMarkInBorder(result_.intersectionMark)) {
		if(particle.coordinate_.x_ < 0. && lastIntersection != 1) {
			lastIntersection = 1;
			planeMarket_.M1 = Vector(0.);
			planeMarket_.M2 = Vector(0., borders_->y_, 0.);
			planeMarket_.M3 = Vector(0., 0., borders_->z_);
		} else if(particle.coordinate_.y_ < 0. && lastIntersection != 2) {
			lastIntersection = 2;
			planeMarket_.M1 = Vector(0.);
			planeMarket_.M2 = Vector(borders_->x_, 0., 0.);
			planeMarket_.M3 = Vector(0., 0., borders_->z_);
		} else if(particle.coordinate_.z_ < 0. && lastIntersection != 3) {
			lastIntersection = 3;
			planeMarket_.M1 = Vector(0.);
			planeMarket_.M2 = Vector(borders_->x_, 0., 0.);
			planeMarket_.M3 = Vector(0., borders_->y_, 0.);
		} else if(particle.coordinate_.x_ > borders_->x_ && lastIntersection != 4) {
			lastIntersection = 4;
			planeMarket_.M1 = Vector(*borders_);
			planeMarket_.M2 = Vector(borders_->x_, 0., borders_->z_);
			planeMarket_.M3 = Vector(borders_->x_, borders_->y_, 0.);
		} else if(particle.coordinate_.y_ > borders_->y_ && lastIntersection != 5) {
			lastIntersection = 5;
			planeMarket_.M1 = Vector(*borders_);
			planeMarket_.M2 = Vector(0., borders_->y_, borders_->z_);
			planeMarket_.M3 = Vector(borders_->x_, borders_->y_, 0.);
		} else if(particle.coordinate_.z_ > borders_->z_ && lastIntersection != 6) {
			lastIntersection = 6;
			planeMarket_.M1 = Vector(*borders_);
			planeMarket_.M2 = Vector(0., borders_->y_, borders_->z_);
			planeMarket_.M3 = Vector(borders_->x_, 0., borders_->z_);
		} else {
			throw "Can't find intersection with board in \"ElasticBorder::getPlaneMarket\"";
		}
		result_.intersectionMark = getMarkIntersection(planeMarket_, particle.coordinate_, move);
	}
	result_.planeIntersection = lastIntersection;

	return result_;
}
const Vector ElasticBorder::getMarkIntersection(const PlaneMarket& planeMarket, const Vector& mark, const Vector& direction) {
	Vector result_;

	double A = (planeMarket.M2.y_ - planeMarket.M1.y_) * (planeMarket.M3.z_ - planeMarket.M1.z_) -
			(planeMarket.M3.y_ - planeMarket.M1.y_) * (planeMarket.M2.z_ - planeMarket.M1.z_);
	double B = (planeMarket.M2.x_ - planeMarket.M1.x_) * (planeMarket.M3.z_ - planeMarket.M1.z_) -
			(planeMarket.M3.x_ - planeMarket.M1.x_) * (planeMarket.M2.z_ - planeMarket.M1.z_);
	double C = (planeMarket.M2.x_ - planeMarket.M1.x_) * (planeMarket.M3.y_ - planeMarket.M1.y_) -
			(planeMarket.M3.x_ - planeMarket.M1.x_) * (planeMarket.M2.y_ - planeMarket.M1.y_);
	double D = A * (-planeMarket.M1.x_) - B * (-planeMarket.M1.y_) - C * (-planeMarket.M1.z_);
	double zn_ = direction.x_ * A + direction.y_ * B + direction.z_ * C;

	if (zn_ == 0.){
		throw "Division by zero in \"ElasticBorder::getMarketIntersection\"";
	}

	double t = (-D - A * mark.x_ - B * mark.y_ - C * mark.z_)/zn_;

	result_.x_ = direction.x_ * t + mark.x_;
	result_.y_ = direction.y_ * t + mark.y_;
	result_.z_ = direction.z_ * t + mark.z_;

	return result_;
}
bool ElasticBorder::isMarkInBorder(const Vector& mark) {
	if(mark.x_ < 0 || mark.x_ > borders_->x_ ||
			mark.y_ < 0 || mark.y_ > borders_->y_ ||
			mark.z_ < 0 || mark.z_ > borders_->z_)
	{
		return false;
	}
	return true;
}

} /* namespace phycoub */
