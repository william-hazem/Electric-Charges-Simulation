#ifndef HAZEM_SINGLETON
#define HAZEM_SINGLETON

#include <mutex>

namespace hz {
    class Singleton
    {
    private:
        static Singleton *instance;
        static std::mutex mutex;
    protected:
        Singleton();
        ~Singleton();
    public:
        Singleton(Singleton &) = delete;
        void operator=(const Singleton &) = delete;

        static Singleton *getInstance();
    };
}



#endif //!HAZEM_SINGLETON