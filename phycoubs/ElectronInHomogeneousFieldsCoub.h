/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-25 11:55:21
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2019-10-27 10:19:54
 */

#pragma once

#include <vector>

#include "PhyCoub.h"
#include "Vector.h"
#include "CyclicBorder.h"
#include "LeapFrog.h"
#include "ElectricHomogeneousField.h"
#include "Constants.h"
#include "CulonInterworking.h"
#include "FieldCreator.h"
#include "FieldReceiver.h"
#include "HomogeneousFieldCreator.h"
#include "CalculationGroup.h"
#include "ElasticCoubCondition.h"

namespace phycoub
{

class ElectronInHomogeneousFieldsCoub final : public PhyCoub
{
  public:
    ElectronInHomogeneousFieldsCoub();
    ~ElectronInHomogeneousFieldsCoub() = default;

    const Vector& getBorders() const;
    ParticleGroupPtr getParticleGroup();

  private:
    double dt_ = 1E-11;
    ParticleGroupPtr electrons_ = std::make_shared< ParticleGroup >();

    CyclicBorderPtr cyclicBorder_ = std::make_shared< CyclicBorder >( Vector{ 1.e-1 } );
    ElasticCoubConditionPtr elascticBorder_
        = std::make_shared< ElasticCoubCondition >( Vector{ 1.e-1 } );

    LeapFrogPtr leapFrog_ = std::make_shared< LeapFrog >();
    CalculationGroupPtr leapFrogCalculationGroup_ = std::make_shared< CalculationGroup >(
        leapFrog_, /*cyclicBorder_*/ elascticBorder_ );

    ElectricHomogeneousFieldPtr electricHomogeneousField_
        = std::make_shared< ElectricHomogeneousField >(
            Vector{ 0, 0, 1 }, ElectricConstants::electronCharge * 100'000 );
    HomogeneousFieldCreatorPtr electricHomogeneousFieldCreator_
        = std::make_shared< HomogeneousFieldCreator >(
            electricHomogeneousField_, "ElectricHomogeneousField" );
    CulonInterworkingPtr culonInterworking_ = std::make_shared< CulonInterworking >();
    FieldReceiverPtr feelWithCulonInterworking_ = std::make_shared< FieldReceiver >(
        electricHomogeneousFieldCreator_, culonInterworking_, "culon interworking" );
};

} // namespace phycoub