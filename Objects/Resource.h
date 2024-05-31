#ifndef PRAKTIKA_RESOURCE_H
#define PRAKTIKA_RESOURCE_H

class Resource{
private:
    int amount;
    double current_x, current_y, target_x, target_y, middle_x;
    double speed;
public:
    bool down = true;
    Resource(double new_speed = 1, int new_amount = 1, double cur_x = 0,double cur_y = 0, double targ_x = 0, double targ_y = 0, double mid = 0){
        speed = new_speed; amount = new_amount; current_x = cur_x;current_y = cur_y;target_x = targ_x;target_y = targ_y;middle_x = mid;
        if(current_y < targ_y){down = false;}
    }

    double get_speed(){return speed;}
    double get_amount(){return amount;}
    double get_curr_x(){return current_x;}
    double get_curr_y(){return current_y;}
    double get_target_x(){return target_x;}
    double get_target_y(){return target_y;}
    double get_mid_x(){return middle_x;}

    void set_new_curr_x(){current_x += speed;}
    void set_new_curr_y(bool t = true){
        if(t){current_y += speed;}
    else{current_y -= speed;}}
};

#endif //PRAKTIKA_RESOURCE_H
