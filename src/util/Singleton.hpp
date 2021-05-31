#ifndef HAZEM_SINGLETON
#define HAZEM_SINGLETON

namespace hz {
    class Singleton
    {
    private:
        static Singleton *instace;

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