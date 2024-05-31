
class Trajectory{
private:
    double width;
    int color_r;
    int color_g;
    int color_b;
    double x1, x2, y1, y2, xm;
    bool normal;
    char type;
public:
    bool is_connected = false;
    Building first_connected_building;
    Building second_connected_building;
    Trajectory(double start_x, double start_y, double end_x, double end_y, double new_width, int new_red = 0, int new_green = 0, int new_blue = 0, char new_t = 'f', bool new_n = true){
        x1 = start_x;y1 = start_y; x2 = end_x; y2 = end_y;
        xm = x2 - x1;
        width = new_width;
        type = new_t;
        normal = new_n;
        color_r = new_red;color_b = new_blue;color_g = new_green;
    }
    void setWidth(double new_width){
        width = new_width;
    }
    void setColor(int R, int G, int B){
        color_r = R; color_g = G; color_b = B;
    }
    void setStartCordinates(double new_x, double new_y){x1 = new_x;y1 = new_y;}
    void setEndCordinates(double new_x, double new_y){x2 = new_x;y2 = new_y;}
    void set_xm(double new_v){xm = new_v;}
    void set_normal(bool temp){normal = temp;}

    double get_width(){return width;}
    double get_x1(){return x1;}
    double get_x2(){return x2;}
    double get_y1(){return y1;}
    double get_y2(){return y2;}
    double get_xm(){return xm;}
    bool get_normal(){return normal;}

    int get_color_red(){return color_r;}
    int get_color_green(){return color_g;}
    int get_color_blue(){return color_b;}

};