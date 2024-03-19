#ifndef OBSERVABLE_H
#define OBSERVABLE_H


#include <set>
class Observer;//comme un include agit car utilisation de observer pour addobserver et remove

class Observable
{
public:
   virtual  ~Observable()= default;
   virtual void addObserver(Observer * observer) final;
   virtual void removeObserver(Observer * observer) final ;
   void notifyObservers() const;//const car pas de modif

private:
   std::set<Observer *> observers;

};


#endif // OBSERVABLE_H
