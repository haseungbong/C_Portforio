#pragma once
template<class T>
class Singleton
{
public:
	static T& instance();
	Singleton(const Singleton&) = delete;//복사생성자
	Singleton(Singleton&&) = delete;//이동생성자
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;

private:
	Singleton() {}
	~Singleton() {}
};

