#ifndef PRAKTIKA_BUILDING_H
#define PRAKTIKA_BUILDING_H

#include "iostream"
#include "SFML/Audio.hpp"
#include <SFML/Audio.hpp>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Building{
private:
    double Sizex;
    double Sizey;
    double curr_center_position_x;
    double curr_center_position_y;
    double start_x;
    double start_y;
    int color_R;
    int color_G;
    int color_B;
    char type;
    int building_connected_left = -1;
    int building_connected_right = -1;
    int rss_amount = 0;
    double spawn_rate = 0.5;
public:
    sf::Clock timer;
    sf::Font font;
    sf::Text text;
    Building(double new_Sizex = 2, double new_Sizey = 2,int Red = 0, int Green = 0, int Blue = 0 ,double new_startx = 0,double new_starty = 0,char new_t = 'f'){
        Sizey = new_Sizey;Sizex = new_Sizex; color_R = Red; color_G = Green; color_B = Blue;
        start_x = new_startx;start_y = new_starty;
        type = new_t;
        update_center();
    }
    Building(char building_type, double start_cord_x, double start_cord_y){
        switch (building_type) {
            case 'm':
                Sizex = 100;Sizey = 50;type = building_type;
                color_R = 255;color_G = color_B = 0;
                start_x = start_cord_x - Sizex / 2;start_y = start_cord_y - Sizey / 2;
                update_center();
                break;
            case 's':
                Sizex = 150;Sizey = 75;type = building_type;
                color_R = 0;color_G = 255;color_B = 0;
                start_x = start_cord_x - Sizex / 2;start_y = start_cord_y - Sizey / 2;
                update_center();
                break;
            case 'f':
                Sizex = 200;Sizey = 100;type = building_type;
                color_R = 0;color_G = 0;color_B = 255;
                start_x = start_cord_x - Sizex / 2;start_y = start_cord_y - Sizey / 2;
                update_center();
                break;
            default:
                std::cout << "Unable to find '" << building_type << "' type of building" << std::endl;
        }
    }

    void update_center(){curr_center_position_x = Sizex / 2 + start_x; curr_center_position_y = Sizey / 2 + start_y;}

    void setSizex(double new_x){Sizex = new_x; update_center();}
    void setSizey(double new_y){Sizex = new_y; update_center();}
    void setCenterx(double new_x){curr_center_position_x = new_x;}
    void setCentery(double new_y){curr_center_position_y = new_y;}
    void setType(char new_t){type = new_t;}
    void setColor(int R, int G, int B){
        color_R = R; color_G = G; color_B = B;
    }
    void setStartcordinates(double x, double y){
        start_x = x; start_y = y;
    }
    void set_connected_left_status(int new_status){building_connected_left = new_status;}
    void set_connected_right_status(int new_status){building_connected_right = new_status;}
    void change_rss_amount(int a){rss_amount+=a;}
    void timer_reset(){timer.restart();}

    double getSpawnRate(){return spawn_rate;}
    char getType(){return type;}
    double get_startx(){return start_x;}
    double get_starty(){return start_y;}
    int get_Color_Red(){return color_R;}
    int get_Color_Green(){return color_G;}
    int get_Color_Blue(){return color_B;}
    double getSizex(){return Sizex;}
    double getSizey(){return Sizey;}
    double getcurr_center_positionx(){return curr_center_position_x;}
    double getcurr_center_positiony(){return curr_center_position_y;}
    int get_connected_status_left(){return building_connected_left;}
    int get_connected_status_right(){return building_connected_right;}
    int get_rss_amount() { return rss_amount;}
};

#endif //PRAKTIKA_BUILDING_H
