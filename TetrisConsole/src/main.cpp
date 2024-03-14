#include "Board.h"
#include "View.h"
#include <iostream>

using namespace std;

int main()
{


    Board b(10, 10);
    Game g;
    View view;
    Controller c(view, game);
    c.start;

    return 0;
}
