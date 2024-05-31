#include "Mechanichs.h"
bool Mechanichs::is_collision(double fx1, double fx2, double fy1, double fy2, double sx1, double sy1) {
    if(sx1 >= fx1 && sx1 <= fx2 && sy1 >= fy1 && sy1 <= fy2){return true;}
    if(sx1 <= fx1 && sx1 >= fx2 && sy1 >= fy1 && sy1 <= fy2){return true;}
    if(sx1 >= fx1 && sx1 <= fx2 && sy1 <= fy1 && sy1 >= fy2){return true;}
    if(sx1 <= fx1 && sx1 >= fx2 && sy1 <= fy1 && sy1 >= fy2){return true;}
    return false;
}
bool Mechanichs::is_collision(double fx1, double fx2, double fy1, double fy2, double sx1, double sx2, double sy1, double sy2) {
    if(is_collision(fx1, fx2, fy1, fy2, sx1, sy1)){return true;}
    if(is_collision(fx1, fx2, fy1, fy2, sx2, sy1)){return true;}
    if(is_collision(fx1, fx2, fy1, fy2, sx1, sy2)){return true;}
    if(is_collision(fx1, fx2, fy1, fy2, sx2, sy2)){return true;}
    return false;
}

bool Mechanichs::is_collision(Building b1, Building b2) {
    double fx1 = b1.get_startx();
    double fx2 = fx1 + b1.getSizex();
    double fy1 = b1.get_starty();
    double fy2 = fy1 + b1.getSizey();
    double sx1,sx2,sy1,sy2;
    sx1 = b2.get_startx();
    sy1 = b2.get_starty();
    sx2 = sx1 + b2.getSizex();
    sy2 = sy1 + b2.getSizey();
    return is_collision(fx1, fx2, fy1, fy2, sx1, sx2, sy1, sy2);
}

bool Mechanichs::is_collision(Building b1, Trajectory t1) {
    double fx1 = b1.get_startx();
    double fx2 = fx1 + b1.getSizex();
    double fy1 = b1.get_starty();
    double fy2 = fy1 + b1.getSizey();
    double sx1,sx2,sx3,sy1,sy2,sy3;
    sx1 = t1.get_x1();sy1 = t1.get_y1() + t1.get_width();
    sx2 = t1.get_xm();sy2 = sy1 - 2 * t1.get_width();
    sx3 = t1.get_x2();sy3 = t1.get_y2();
    if(is_collision(fx1, fx2, fy1, fy2, sx1, sx2 + t1.get_width(), sy1, sy2)){return true;}
    if(is_collision(fx1, fx2, fy1, fy2, sx2 - t1.get_width(), sx2 + t1.get_width(), sy1,sy3 - t1.get_width())){return true;}
    if(is_collision(fx1, fx2, fy1, fy2, sx2 - t1.get_width(), sx3, sy3 + t1.get_width(), sy3 - t1.get_width())){return true;}
    return false;
}

bool Mechanichs::is_collision(double x, double y, Building b1) {
    double fx1 = b1.get_startx();
    double fx2 = fx1 + b1.getSizex();
    double fy1 = b1.get_starty();
    double fy2 = fy1 + b1.getSizey();
    return is_collision(fx1, fx2, fy1, fy2, x, y);
}



