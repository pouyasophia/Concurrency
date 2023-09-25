#include <iostream>
#include <random>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */
 
template <typename T>
T MessageQueue<T>::receive()
{
    
    //perform queue mod under lock
    std::unique_lock<std::mutex> uLock(_mtx);
    _cond.wait(uLock, [this] {return !_queue.empty();});

    //remove last element from queue vector
    T msg = std::move(_queue.back());
    _queue.pop_back();

    return msg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    
    //perform mod under lock
    std::lock_guard<std::mutex> uLock(_mtx);

    //add msg to queue
    _queue.push_back(std::move(msg));
    _cond.notify_one();

}


/* Implementation of class "TrafficLight" */

TrafficLight::TrafficLight()
{
    _currentPhase = TrafficLightPhase::red;
    _msgs = std::make_shared<MessageQueue<TrafficLightPhase>>();
}



void TrafficLight::waitForGreen()
{
    while(true) {
        TrafficLightPhase currPhase = _msgs->receive();
        if(currPhase == TrafficLightPhase::green) {
            return;
        }
    }
}

TrafficLightPhase TrafficLight::getCurrentPhase()
{
    return _currentPhase;
}


void TrafficLight::simulate()
{
    //use threads vector from trafficObject
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases,this));

}

// virtual function which is executed in a thread
void TrafficLight::cycleThroughPhases()
{
    std::random_device rd; // obtain random number from hardware
    std::mt19937 gen(rd()); //seed generator
    std::uniform_int_distribution<> distr(4000, 6000); //range

    while(true) {
        long randomNum = distr(gen);
        std::this_thread::sleep_for(std::chrono::milliseconds(randomNum));

        if( _currentPhase == TrafficLightPhase::red){
            _currentPhase = TrafficLightPhase::green;
        }
        else
            _currentPhase = TrafficLightPhase::red;

        //update method to the message queue using move semantics
        _msgs->send(std::move(_currentPhase));
       
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

}

