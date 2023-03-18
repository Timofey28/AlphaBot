#ifndef ROBOT_H
#define ROBOT_H


class Robot
{
    float x, y, angle;
public:
    Robot();
    void turn(std::pair<float, float> destination);
    void go(std::pair<float, float> destination);
    void setCoords(float, float, float);
};

#endif // ROBOT_H
