#include <Hazem/Util/Singleton.hpp>

namespace hz {

    Singleton *Singleton::instance = nullptr;
    std::mutex Singleton::mutex;

    Singleton::Singleton() {}

    Singleton::~Singleton() {}

    Singleton *Singleton::getInstance() {
        // MAYBE PROBLEMS WITH MULTI-TREAD
        std::lock_guard<std::mutex> lock(mutex);
        if(instance == nullptr)
            instance = new Singleton();
        return instance;
    }

}
