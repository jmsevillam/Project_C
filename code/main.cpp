#include<iostream>

class particle{
private:
    double m;
    double y;
    double z;
    double x;
public:
    double test;
    double Get_x(){return x;};
    double Get_y(){return y;};
    double Get_z(){return z;};
};



int main(int argc, char * argv[]){

particle ball;

std::cout<< ball.Get_x() <<std::endl;

return 0;
}
