#include "Singleton.hpp"

namespace hz {

    Singleton *Singleton::instace = nullptr;

    Singleton::Singleton() {

    }

    Singleton::~Singleton() {

    }

    Singleton *Singleton::getInstance() {
        // MAYBE PROBLEMS WITH MULTI-TREAD
        // std::lock_guard<std::mutex> lock(mutex_);
        if(instace == nullptr)
            instace = new Singleton();
        return instace;
    }

}
