#pragma once
template<class T>
class Singleton
{
public:
	static T& instance();
	Singleton(const Singleton&) = delete;//���������
	Singleton(Singleton&&) = delete;//�̵�������
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;

private:
	Singleton() {}
	~Singleton() {}
};

