#include <random>

#pragma once
class Random
{
public:
	Random(double prob);
	bool isAlive() const;
	double prob() const;
	void setProb(double prob);
	bool operator()();
	~Random();
private:
	size_t inverse_probability;
	static std::mt19937 m_rng;
	static std::random_device m_rand;
	static std::uniform_int_distribution<> m_uniform_dist;
};

