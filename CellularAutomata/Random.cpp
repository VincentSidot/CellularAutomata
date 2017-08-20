#include "Random.h"

std::random_device Random::m_rand;
std::mt19937 Random::m_rng{ Random::m_rand() };
std::uniform_int_distribution<> Random::m_uniform_dist{ 1 };

Random::Random(double prob)
{
	inverse_probability = static_cast<size_t>(1 / prob);
}

bool Random::isAlive() const
{
	return (m_uniform_dist(m_rng)%inverse_probability)==0;
}

double Random::prob() const
{
	return 1/static_cast<double>(inverse_probability);
}

void Random::setProb(double prob)
{
	inverse_probability = static_cast<size_t>(1 / prob);
}

bool Random::operator()()
{
	return this->isAlive();
}


Random::~Random()
{
}
