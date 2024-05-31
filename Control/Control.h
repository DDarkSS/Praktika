#ifndef PRAKTIKA_CONTROL_H
#define PRAKTIKA_CONTROL_H
#include "../Mechanichs/Mechanichs.h"
namespace Control{
    bool check_building_placement(Building&, std::vector<Building> &);
    void PlaceBuilding(Building& , sf::RenderWindow&, std::vector<Building> &);
    void Draw_Buildings(std::vector<Building>&, sf::RenderWindow&);
    void Connect_Buildings(Building&, Building&,int, int, std::vector<Trajectory>&);
    void Draw_Trajectories(std::vector<Trajectory>, sf::RenderWindow&);
    void Spawn_Resource(Building&, std::vector<Building>&, std::vector<Resource>&);
    int Get_Building_Index_onCords(double, double, std::vector<Building> &);
    void Draw_Resources(std::vector<Resource>&, sf::RenderWindow&);
    void Destroy_Resources(std::vector<Resource>&,std::vector<Building>&, int, bool);
    void Move_Resources(std::vector<Resource>&,std::vector<Building>&);
    void ResourceSpawnCheck(std::vector<Resource>&, std::vector<Building>&);
}

#endif //PRAKTIKA_CONTROL_H
