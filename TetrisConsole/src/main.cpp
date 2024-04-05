#include "View/View.h"
#include "Controller/Controller.h"

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
