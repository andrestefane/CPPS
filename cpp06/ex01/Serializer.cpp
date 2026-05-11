#include "Serializer.hpp"

Serializer::Serializer(void)
{

}

Serializer::Serializer(const Serializer &cp)
{
	*this = cp;
}

Serializer &Serializer::operator=(const Serializer &cp)
{
	(void)cp;
	return (*this);
}

Serializer::~Serializer()
{

}

uintptr_t Serializer::Serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
