#include<iostream>
#include<cmath>


class particle;
class collider;

#define G 1 
#define dt 0.01


class particle{
private:
    double m;
    double x;    double vx;    double fx;
    double y;    double vy;    double fy;
    double z;    double vz;    double fz;
public:
    particle();
    //~particle();
    void initial_conditions(double x0,double y0,double z0);
    void initial_conditions_v(double x0,double y0,double z0);
    void step();
    double Get_x(){return x;};
    double Get_y(){return y;};
    double Get_z(){return z;};
    double Get_vx(){return vx;};
    double Get_vy(){return vy;};
    double Get_vz(){return vz;};
    double Get_fx(){return fx;};
    double Get_fy(){return fy;};
    double Get_fz(){return fz;};
    void res_f();
    void print_position();
    void print_forces();
    friend class collider;
};


class collider{
private:
public:

void cal_forces_pair(particle & p1, particle & p2);


};




void collider::cal_forces_pair(particle & p1, particle & p2){
    double dx,dy,dz;
    dx=p1.x-p2.x;
    dy=p1.y-p2.y;
    dz=p1.z-p2.z;
    double dis;
    dis= sqrt(dx*dx+dy*dy+dz*dz);
    
    
    double fx1,fy1,fz1;

    fx1=-G* p1.m*p2.m*(dx)/(pow(dis,3));
    fy1=-G* p1.m*p2.m*(dy)/(pow(dis,3));
    fz1=-G* p1.m*p2.m*(dz)/(pow(dis,3));

    p1.res_f();    p2.res_f();

    p1.fx=fx1;    p2.fx=-fx1;
    p1.fy=fy1;    p2.fy=-fy1;
    p1.fz=fz1;    p2.fz=-fz1;

}


particle::particle(){
    x=0;    y=0;    z=0;
    vx=0;    vy=0;    vz=0;
    fx=0;    fy=0;    fz=0;
    m=1;
}

void particle::print_position(){
    std::cout<<x<<' '<<y<<' '<<z<<std::endl;
}


void particle::print_forces(){
    std::cout<<fx<<' '<<fy<<' '<<fz<<std::endl;
}

void particle::initial_conditions(double x0,double y0,double z0){
    x=x0;
    y=y0;
    z=z0;
}

void particle::initial_conditions_v(double x0,double y0,double z0){
    vx=x0;
    vy=y0;
    vz=z0;
}
void particle::res_f(){
    fx=0; fy=0; fz=0;
}



void particle::step(){

    vx+=fx/m*dt;
    x+=vx*dt; 

    vy+=fy/m*dt;
    y+=vy*dt; 

    vz+=fz/m*dt;
    z+=vz*dt; 

}




int main(int argc, char * argv[]){

particle par[2];
collider Newton;

par[0].initial_conditions(-1,0,0);
par[1].initial_conditions(1,0,0);

par[0].initial_conditions_v(0,-.5,0);
par[1].initial_conditions_v(0,.5,0);


for(int i=0; i<=10000;i++){
    Newton.cal_forces_pair(par[0],par[1]);
    par[0].step();
    par[1].step();
    std::cout<<i*dt<<' '<<par[0].Get_x()<<' '<<par[0].Get_y()<<' '<<par[1].Get_x()<<' '<<par[1].Get_y()<<std::endl;
}
return 0;
}


