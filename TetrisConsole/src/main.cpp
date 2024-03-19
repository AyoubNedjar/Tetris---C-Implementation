#include "View.h"
#include "Controller.h"
#include <iostream>

using namespace std;


int main()
{

    Game g;
    View v;
    Controller c(g, v);

    g.addObserver(&c);

    c.start();



    return 0;
}
