#pragma once

template <typename T>
class Singleton//Meyers Singletor
{
protected:
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static T& GetInstance()
    {
        static T instance;
        return instance;
    }
};

