clean.bat^
 && cl -Icommon/^
    -Iborderconditions/^
    -Iborderevents/^
    -Iborderfieldconditions/^
    -Icalculationmodels/^
    -Ifieldfunctions/^
    -Iinterworkingfunctions/^
    -Iotherobjects/^
    -Ilifetimecontrollers/^
    -Iparticlesources/^
    -Iphycoubs/^
    -Iphymeasurement/^
    -Iphyobjects/^
    -Iphyobjects/particlefigurematrix/^
    -Ispecialmodellingfunctions/^
    -Ishapes/^
    -Itypes/^
    /EHsc^
    /MDd^
    /c^
    borderconditions/BorderCondition.cpp^
    borderconditions/CyclicBorder.cpp^
    borderconditions/CylinderBorderCondition.cpp^
    borderconditions/ElasticBorder.cpp^
    borderconditions/ElasticCoubCondition.cpp^
    borderconditions/ThermostatBorder.cpp^
    borderevents/BorderReachedEventGenerator.cpp^
    borderfieldconditions/BorderFieldCondition.cpp^
    borderfieldconditions/CyclicBoundedField.cpp^
    calculationmodels/CalculationModel.cpp^
    calculationmodels/HighSpeedModificationVerle.cpp^
    calculationmodels/LeapFrog.cpp^
    common/HasId.cpp^
    common/ContainParticleGroupList.cpp^
    fieldfunctions/DirectHomogeneousField.cpp^
    fieldfunctions/ElectricField.cpp^
    fieldfunctions/ElectricHomogeneousDirectField.cpp^
    fieldfunctions/ElectricHomogeneousRadialXYField.cpp^
    fieldfunctions/LDField.cpp^
    fieldfunctions/MagneticHomogeneousDirectField.cpp^
    fieldfunctions/RadialHomogeneousField.cpp^
    interworkingfunctions/CulonInterworking.cpp^
    interworkingfunctions/LDInterworking.cpp^
    interworkingfunctions/MagneticInterworking.cpp^
    lifetimecontrollers/QuantityLifeTimeController.cpp^
    particlesources/CylindricalXYParticleSource.cpp^
    phycoubs/ArCoub.cpp^
    phycoubs/ElectronInHomogeneousFieldsCoub.cpp^
    phycoubs/FigureDemonstration.cpp^
    phycoubs/Magnetron.cpp^
    phycoubs/NOCoub.cpp^
    phycoubs/PhyCoub.cpp^
    phymeasurement/MeasurementUtils.cpp^
    phyobjects/CalculationGroup.cpp^
    phyobjects/DynamicFieldCreator.cpp^
    phyobjects/FieldCreator.cpp^
    phyobjects/FieldReceiver.cpp^
    phyobjects/HomogeneousFieldCreator.cpp^
    phyobjects/InterCommunication.cpp^
    phyobjects/InterGroupCommunication.cpp^
    phyobjects/InterworkingCalculatorBase.cpp^
    phyobjects/Particle.cpp^
    phyobjects/ParticleGroup.cpp^
    phyobjects/particlefigurematrix/LineFigure.cpp^
    phyobjects/particlefigurematrix/ParallelepipedFigure.cpp^
    phyobjects/particlefigurematrix/PlaneFigure.cpp^
    shapes/CubicShape.cpp^
    shapes/CylindricShape.cpp^
    types/Vector.cpp^
    types/VectorUtils.cpp^
 && lib^
    /out:phycoub.lib^
    *.obj