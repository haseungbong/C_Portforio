#pragma once

template <typename T>
class Singleton//Meyers Singletor
{
protected:
    Singleton() = default;
    ~Singleton() = default;
    
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
	
    static T& GetInstance()
    {
        static T instance;
        return instance;
    }
};

