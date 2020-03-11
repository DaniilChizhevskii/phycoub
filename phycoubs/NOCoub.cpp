/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2019-10-19 19:07:08
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-11 13:58:44
 */

#include <NOCoub.h>

#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <time.h>

namespace phycoub
{

NOCoub::NOCoub()
{
    ParticleGroupPtr azot = std::make_shared< ParticleGroup >();
    ParticleGroupPtr oxygen = std::make_shared< ParticleGroup >();

    setDeltaTime( dt_ );

    srand( time( NULL ) );
    rand();
    rand();
    rand();

    // NN
    azot->emplace_back( std::make_shared< Particle >(
        Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.45 * borders_.z_ ),
        Vector( .0, .0, .0 ), mN_, z_ ) );

    azot2azotFieldCreator_->addParticleGroup( azot );
    addContainParticleGroup( azot2azotFieldCreator_ );

    azot2azotFieldResponsive_->addParticleGroup( azot );
    addContainParticleGroup( azot2azotFieldResponsive_ );

    addFieldResponsive( azot2azotFieldResponsive_ );

    // OO
    oxygen->emplace_back( std::make_shared< Particle >(
        Vector( 0.5 * borders_.x_, 0.5 * borders_.y_, 0.55 * borders_.z_ ),
        Vector( .0, .0, .0 ), mO_, z_ ) );

    oxygen2oxygenFieldCreator_->addParticleGroup( oxygen );
    addContainParticleGroup( oxygen2oxygenFieldCreator_ );

    oxygen2oxyhenFieldResponsive_->addParticleGroup( oxygen );
    addContainParticleGroup( oxygen2oxyhenFieldResponsive_ );

    addFieldResponsive( oxygen2oxyhenFieldResponsive_ );

    // OO - NO
    azot2oxygenInterCommunication_->addParticleGroup( azot );
    addContainParticleGroup( azot2oxygenInterCommunication_ );

    azot2oxygenInterCommunication_->addParticleGroup( oxygen );
    addContainParticleGroup( azot2oxygenInterCommunication_ );

    addFieldResponsive( azot2oxygenInterCommunication_ );

    leapFrogCalculationGroup_->addParticleGroup( azot );
    addContainParticleGroup( azot2oxygenInterCommunication_ );

    leapFrogCalculationGroup_->addParticleGroup( oxygen );
    addContainParticleGroup( azot2oxygenInterCommunication_ );

    addCalculationGroup( leapFrogCalculationGroup_ );

    updateUniqParticleGroupList();
}

} // namespace phycoub
