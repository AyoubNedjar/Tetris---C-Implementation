#ifndef OBSERVABLE_H
#define OBSERVABLE_H


#include <set>
class Observer;//comme un include agit car utilisation de observer pour addobserver et remove

class Observable
{
public:
   virtual  ~Observable()= default;
   void addObserver(Observer * observer);
   void removeObserver(Observer * observer);
   void notifyObservers() const;//const car pas de modif

private:
   std::set<Observer *> observers;

};


#endif // OBSERVABLE_H
