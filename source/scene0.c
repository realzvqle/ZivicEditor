#include "../headers/scene0.h"



void scene0(state* state) {

    static zivWindow window2 = { 90, 90, 500, 800 , false, 0, 0, 0.0};
    static zivWindow window1 = { 10, 10, 200, 400 ,false, 0, 0, 0.0 };
    
    spawnWindow(&window2, state);

    spawnWindow(&window1, state);




    
    
	//spawnWindow(400, 200, 200, 400, state);


}