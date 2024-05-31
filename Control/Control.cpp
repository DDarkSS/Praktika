#include "Control.h"
const int Width = 5;
const double basic_radius = 15;
//bool Control::check_building_placement(Building building,std::vector<Building> &buildings_list){
//    double *a = new double[8];a[0] = building.get_startx();a[1] = building.get_starty();
//    a[2] = a[0] + building.getSizex();a[3] = a[1];
//    a[4] = a[0];a[5] = a[1] + building.get_starty();
//    a[6] = a[2];a[7] = a[5];
//    for(int i = 0; i < 8; i += 2){
//        for(int j = 0; j < buildings_list.size(); j++){
//            //- not working
//            double x1,x2,y1,y2;
//            x1 = buildings_list[i].get_startx();y1 = buildings_list[i].get_starty();
//            x2 = x1 + buildings_list[i].getSizex();y2 = y1 + buildings_list[i].getSizey();
//            if(a[i] > x1 && a[i] < x2 && a[i + 1] > y1 && a[i + 1] <y2){return false;}
//        }
//    }
//    return true;
//}
bool Control::check_building_placement(Building& building, std::vector<Building>& building_list) {
    for(int i = 0; building_list.size() > i; i++){
        if(Mechanichs::is_collision(building, building_list[i])){return false;}
    }
    return true;
}
void Control::PlaceBuilding(Building& building, sf::RenderWindow& window, std::vector<Building> &a) {
    if(check_building_placement(building, a)){a.push_back(building);}
//    else{std::cout << "Building can not be placed" << std::endl;}
}
void Control::Draw_Buildings(std::vector<Building>&Buildings_list, sf::RenderWindow &window) {
    for(int i = 0; i < Buildings_list.size();i++){
        sf::RectangleShape rectangle(sf::Vector2f(Buildings_list[i].getSizex(), Buildings_list[i].getSizey()));
        rectangle.setFillColor(sf::Color(Buildings_list[i].get_Color_Red(), Buildings_list[i].get_Color_Green(), Buildings_list[i].get_Color_Blue()));
        rectangle.setPosition(Buildings_list[i].get_startx(), Buildings_list[i].get_starty());
        window.draw(rectangle);
//        if(Buildings_list[i].getType() == 'f') {
//            Buildings_list[i].font.loadFromFile("/Users/mikalbr/Projects/Sem2/Praktika/CyrilicOld.TTF");
//            Buildings_list[i].text.setFont(Buildings_list[i].font);
//            auto s = std::to_string(Buildings_list[i].get_rss_amount());
//            Buildings_list[i].text.setString(s);
//            Buildings_list[i].text.setCharacterSize(24);
//            Buildings_list[i].text.setFillColor(sf::Color::Black);
//            Buildings_list[i].text.setPosition(Buildings_list[i].get_startx() + Buildings_list[i].getSizex()/2,
//                                               Buildings_list[i].get_starty() + Buildings_list[i].get_starty());
//            window.draw(Buildings_list[i].text);
//        }
    }
}
void Control::Connect_Buildings(Building& b1, Building& b2,int index1,int index2 ,std::vector<Trajectory>&All_Trajectory){
    if(b1.get_connected_status_right() == -1 && b2.get_connected_status_left() == -1
    && (b1.getType() == 'm' && b2.getType() == 'f')){
        if(b1.get_startx() > b2.get_startx()){Building temp = b1; b1 = b2; b2 = temp;int i2 = index1;index1 = index2;index1 = i2;}
        Trajectory new_trajectory(b1.get_startx()+b1.getSizex(), b1.getcurr_center_positiony(),
                                  b2.get_startx(), b2.getcurr_center_positiony(), 5);
        std::cout<<b1.get_connected_status_right() << " " << b2.get_connected_status_left() << std::endl;
        b1.set_connected_right_status(index2);b2.set_connected_left_status(index1);
        new_trajectory.first_connected_building = index2;
        new_trajectory.second_connected_building = index1;
        new_trajectory.is_connected = true;
        All_Trajectory.push_back(new_trajectory);
    }
}
void Control::Draw_Trajectories(std::vector<Trajectory> All_Trajectory, sf::RenderWindow& window){
    for(int i = 0; i < All_Trajectory.size(); i++){
        if(All_Trajectory[i].get_normal()){
            double width1 = Width;
            //rect1
    //        std::cout << All_Trajectory[i].get_y1() << std::endl;
            sf::RectangleShape rect1(sf::Vector2f((All_Trajectory[i].get_x2() - All_Trajectory[i].get_x1()) /2 ,All_Trajectory[i].get_width()));
            rect1.setFillColor(sf::Color(All_Trajectory[i].get_color_red(), All_Trajectory[i].get_color_green(), All_Trajectory[i].get_color_blue()));
            rect1.setPosition(All_Trajectory[i].get_x1(),All_Trajectory[i].get_y1() - All_Trajectory[i].get_width());
            //rect2
            sf::RectangleShape rect2(sf::Vector2f(All_Trajectory[i].get_width(), All_Trajectory[i].get_y2() - All_Trajectory[i].get_y1()));
            rect2.setFillColor(sf::Color(All_Trajectory[i].get_color_red(), All_Trajectory[i].get_color_green(), All_Trajectory[i].get_color_blue()));
            rect2.setPosition((All_Trajectory[i].get_x2() - All_Trajectory[i].get_x1()) /2 - Width + All_Trajectory[i].get_x1(), All_Trajectory[i].get_y1());
            sf::RectangleShape rect3(sf::Vector2f((All_Trajectory[i].get_x2() - All_Trajectory[i].get_x1()) /2 ,All_Trajectory[i].get_width()));
            rect3.setFillColor(sf::Color(All_Trajectory[i].get_color_red(), All_Trajectory[i].get_color_green(), All_Trajectory[i].get_color_blue()));
            if(All_Trajectory[i].get_y2() >= All_Trajectory[i].get_y1()){width1 = width1 - 2 * Width;}
            rect3.setPosition((All_Trajectory[i].get_x2() + All_Trajectory[i].get_x1())/2, All_Trajectory[i].get_y2() - Width);
            window.draw(rect1);
            window.draw(rect2);
            window.draw(rect3);}
    }

}

int Control::Get_Building_Index_onCords(double x, double y, std::vector<Building>& All_Buildings) {
    for(int i = 0; i < All_Buildings.size(); i++){
        if(Mechanichs::is_collision(x, y, All_Buildings[i])){
            return i;
        }
    }
    return -1;
}


void Control::Spawn_Resource(Building& Starting_Building, std::vector<Building>& All_Buildings, std::vector<Resource>&All_Resources){
    if(Starting_Building.get_connected_status_right() != -1){
        double x1,y1,xm,y2,x2;
        double speed = 0.1;
        double amount = 1;
        Building end_building = All_Buildings[Starting_Building.get_connected_status_right()];
        x1 = Starting_Building.get_startx() + Starting_Building.getSizex() - basic_radius;
        y1 = Starting_Building.get_starty() + Starting_Building.getSizey() / 2 - basic_radius;
        x2 = end_building.get_startx() - basic_radius;
        y2 = end_building.get_starty() + end_building.getSizey() / 2 - basic_radius;
        xm = x1 + (x2 - x1)/2;
        Resource new_rss(speed, amount, x1, y1, x2, y2, xm);
        All_Resources.push_back(new_rss);
    }
}

void Control::Draw_Resources(std::vector<Resource>& All_Resources, sf::RenderWindow& window) {
    for(int i = 0; i < All_Resources.size();i++){
        Resource curr = All_Resources[i];
        sf::CircleShape circle(basic_radius);
        circle.setFillColor(sf::Color(100, 100, 100));
        circle.setPosition(sf::Vector2f(curr.get_curr_x(), curr.get_curr_y()));
        window.draw(circle);
    }
}

void Control::Destroy_Resources(std::vector<Resource>& R_list, std::vector<Building>& b, int index, bool finished) {

    int building_index = Get_Building_Index_onCords(R_list[index].get_curr_x(), R_list[index].get_curr_y(), b);
    if(finished && building_index != 0){b[building_index].change_rss_amount(R_list[index].get_amount());}
    R_list.erase(R_list.begin() + index);
}

void Control::Move_Resources(std::vector<Resource>& All_Rss, std::vector<Building>& b) {
    for(int i = 0; i < All_Rss.size();i++){
        if(All_Rss[i].get_curr_x() < All_Rss[i].get_mid_x()){
            All_Rss[i].set_new_curr_x();
        }
        else if(All_Rss[i].get_curr_y() < All_Rss[i].get_target_y() && !All_Rss[i].down){
            All_Rss[i].set_new_curr_y();
        }
        else if(All_Rss[i].get_curr_y() > All_Rss[i].get_target_y() && All_Rss[i].down){
            All_Rss[i].set_new_curr_y(false);
        }
        else if(All_Rss[i].get_curr_x() < All_Rss[i].get_target_x()){
            All_Rss[i].set_new_curr_x();
        }
        else{Destroy_Resources(All_Rss,b, i,true);i--;}
    }
}

void Control::ResourceSpawnCheck(std::vector<Resource>& All_Rss, std::vector<Building>& All_Buildings) {
    for(int i = 0; i < All_Buildings.size(); i++){
        sf::Time time = All_Buildings[i].timer.getElapsedTime();
        if(All_Buildings[i].getType() == 'm' && All_Buildings[i].get_connected_status_right() && (time.asSeconds() > All_Buildings[i].getSpawnRate())){
            Spawn_Resource(All_Buildings[i], All_Buildings, All_Rss);
            All_Buildings[i].timer_reset();
        }
    }
}
