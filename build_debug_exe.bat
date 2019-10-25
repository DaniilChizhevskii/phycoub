clean.bat^
 && cl -Icommon/^
    -Iborderconditions/^
    -Iborderfieldconditions/^
    -Icalculationmodels/^
    -Ifieldfunctions/^
    -Iinterworkingfunctions/^
    -Iotherobjects/^
    -Iphycoubs/^
    -Iphymeasurement/^
    -Iphyobjects/^
    -Iphyobjects/particlefigurematrix/^
    -Ispecialmodellingfunctions/^
    -Itypes/^
    /EHsc^
    /Zi^
    /Fe:phycoub_test.exe^
    borderconditions/BorderCondition.cpp^
    borderconditions/CyclicBorder.cpp^
    borderconditions/ElasticBorder.cpp^
    borderconditions/ElasticCoubCondition.cpp^
    borderconditions/ThermostatBorder.cpp^
    borderfieldconditions/BorderFieldCondition.cpp^
    borderfieldconditions/CyclicBoundedField.cpp^
    calculationmodels/CalculationModel.cpp^
    calculationmodels/HighSpeedModificationVerle.cpp^
    calculationmodels/LeapFrog.cpp^
    fieldfunctions/ElectricField.cpp^
    fieldfunctions/ElectricHomogeneousField.cpp^
    fieldfunctions/HomogeneousField.cpp^
    fieldfunctions/LDFieldFunction.cpp^
    fieldfunctions/MagneticHomogeneousField.cpp^
    interworkingfunctions/CulonInterworking.cpp^
    interworkingfunctions/InterworkingFunction.cpp^
    interworkingfunctions/LDInterworking.cpp^
    otherobjects/NodeCrystal.cpp^
    phycoubs/ArCoub.cpp^
    phycoubs/ElectronInHomogeneousFieldsCoub.cpp^
    phycoubs/FigureDemonstration.cpp^
    phycoubs/NOCoub.cpp^
    phymeasurement/measurement.cpp^
    phyobjects/CalculationGroup.cpp^
    phyobjects/CreateField.cpp^
    phyobjects/CreateFieldBase.cpp^
    phyobjects/CreateHomogeneousField.cpp^
    phyobjects/FeelField.cpp^
    phyobjects/Particle.cpp^
    phyobjects/particlefigurematrix/LineFigure.cpp^
    phyobjects/particlefigurematrix/ParallelepipedFigure.cpp^
    phyobjects/particlefigurematrix/PlaneFigure.cpp^
    specialmodellingfunctions/temperatureControl.cpp^
    src/main.cpp^
    types/Vector.cpp^
    types/VectorUtils.cpp