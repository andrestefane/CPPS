#pragma once

# include <stdint.h>
# include <iostream>
# include <string>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &rhs);
		~Serializer();
	public:
		static uintptr_t Serialize(Data *ptr);
		static Data		*deserialize(uintptr_t ray);
};