#ifndef PRAKTIKA_MECHANICHS_H
#define PRAKTIKA_MECHANICHS_H
#include "../Objects/Building.h"
#include "../Objects/Trajectory.h"
#include "../Objects/Resource.h"
namespace Mechanichs{
    bool is_collision(double,double, double, double, double, double);
    bool is_collision(double,double, double, double, double, double, double, double);
    bool is_collision(Building, Building);
    bool is_collision(Building, Trajectory);
    bool is_collision(double, double, Building);
}

#endif //PRAKTIKA_MECHANICHS_H
