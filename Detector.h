#ifndef DETECTOR_H
#define DETECTOR_H
#include <tuple>


template<class DetectionPolicy>
class Detector
{
    DetectionPolicy strategy;
public:
    std::pair<float, float> getHumanCoords() {return strategy.getHumanCoords();}
    std::tuple<float, float, float> getRobotCoords() {return strategy.getRobotCoords();}
    std::pair<float, float> getDispenserCoords() {return strategy.getDispenserCoords();}
};


struct Strategy1
{
    std::pair<float, float> getHumanCoords();
    std::tuple<float, float, float> getRobotCoords();
    std::pair<float, float> getDispenserCoords();
};

struct Strategy2
{
    std::pair<float, float> getHumanCoords();
    std::tuple<float, float, float> getRobotCoords();
    std::pair<float, float> getDispenserCoords();
};

#endif // DETECTOR_H
