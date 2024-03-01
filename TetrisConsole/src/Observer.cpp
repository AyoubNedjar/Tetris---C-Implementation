#include "Observer.h"

Observer::Observer()
{
public :
    virtual ~Observer() = default;
    virtual void update() = 0;
}
