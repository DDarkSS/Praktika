#include "iostream"
#include "Control/Control.h"

double cord_x;
double cord_y;
int building_index_selected = -1;
int previous_building_selected = -1;
bool selected = false;
std::vector<Building> All_Buildings;
std::vector<Trajectory> All_Trajectory;
std::vector<Resource> All_Resources;
void Game();
void test1();
void print1(){
    using namespace std;
    std::cout << 1 << std:: endl;
}

void Binds(sf::RenderWindow& window, sf::Clock clock){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !selected){
        cord_x = sf::Mouse::getPosition(window).x;
        cord_y = sf::Mouse::getPosition(window).y;
        int temp = Control::Get_Building_Index_onCords(cord_x, cord_y, All_Buildings);
        if(temp != -1){
            if(temp != building_index_selected){previous_building_selected = building_index_selected;
                building_index_selected = temp;}
        }
        else{previous_building_selected = -1; building_index_selected = -1;}}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        if(previous_building_selected != -1 && building_index_selected != -1){
            Control::Connect_Buildings(All_Buildings[previous_building_selected], All_Buildings[building_index_selected],previous_building_selected,building_index_selected, All_Trajectory);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
        if(previous_building_selected == -1 && building_index_selected == -1){
            Building new_building('m', cord_x, cord_y);
            Control::PlaceBuilding(new_building, window, All_Buildings);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
        if(previous_building_selected == -1 && building_index_selected == -1){
            Building new_building('f', cord_x, cord_y);
            Control::PlaceBuilding(new_building, window, All_Buildings);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        if(building_index_selected != -1 && All_Buildings[building_index_selected].get_connected_status_right() != -1){
            Control::Spawn_Resource(All_Buildings[building_index_selected], All_Buildings, All_Resources);
        }
    }
}

void renderThread(sf::RenderWindow* window){
    window->setActive(true);
    while(window->isOpen()){
        window->display();
    }
}

int main()
{
    Game();
    return 0;
}
void Game(){
    sf::RenderWindow window(sf::VideoMode(1920, 720), "OpenGL", sf::Style::Default);
    sf::Clock in_game_time;
    while (window.isOpen()){
        sf::Event events;
        while(window.pollEvent(events)){
            switch (events.type) {
                case sf::Event::Closed:
                    window.close();
                default:
                    break;
            }
        }
        Binds(window, in_game_time);

        window.clear(sf::Color::White);
        Control::Draw_Buildings(All_Buildings, window);
        Control::Draw_Trajectories(All_Trajectory, window);
        Control::Draw_Resources(All_Resources, window);
        Control::Move_Resources(All_Resources, All_Buildings);
        Control::ResourceSpawnCheck(All_Resources, All_Buildings);
        window.display();
    }
}