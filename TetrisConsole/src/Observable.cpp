#include "Observable.h"
#include "Observer.h"



void Observable::addObserver(Observer * obs){
    observers.insert(obs);
}
void Observable::removeObserver(Observer * obs){
    observers.erase(obs);
}
void Observable::notifyObservers()const {

    for(Observer * obs: observers) {
        obs->update();
    }
}
