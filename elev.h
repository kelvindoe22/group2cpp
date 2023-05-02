
#if !defined(VIP_ELEV_H)
#define VIP_ELEV_H
#include "app.h" 
#include "msoftcon.h" 
#include<iostream>
#include<iomanip> 
#include<conio.h> 
#include<stdlib.h> 
                    
#include<process.h> 



using namespace std;

enum Direction{UP, DOWN, STOP};
const int LOAD_TIME = 3; 
const int SPACING = 7; 
const int BUFF_LENGTH = 80; 

class Building;

class Elevator{
private:
    Building* buildingPtr;
    const int car_number; 
    int current_floor; 
    int old_floor;
    Direction current_direction; 
    bool destination[NUM_FLOORS]; 
    int loading_timer; 
    int unloading_timer; 

public:
    Elevator(Building*, int);
    void car_tick1(); 
    void car_tick2(); 
    void car_display(); 
    void display_destinations(); 
    void decide();
    void move();
    void get_destinations();
    int get_floor() const;
    Direction get_direction() const;  
   
};

class Building{
private:
    Elevator* car_list[NUM_CARS]; 
    int num_cars; 

    bool floor_request[2][NUM_FLOORS]; 

public:
    Building(); 
    ~Building(); 
    void master_tick();
    int get_car_floor(const int) const;
    Direction get_car_direction(const int) const; 
    bool check_floor_request(const int, const int) const;
    void set_floor_request(const int, const int, const bool);
    void record_floor_requests();
    void show_floor_requests();
};

#endif
