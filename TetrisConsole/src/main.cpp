#include "View.h"
#include "Controller.h"
#include <iostream>

using namespace std;


int main()
{

    Game g;
    View v;
    Controller c(g, v);
    c.start();
    std::cout<<"bjr";



    return 0;
}
