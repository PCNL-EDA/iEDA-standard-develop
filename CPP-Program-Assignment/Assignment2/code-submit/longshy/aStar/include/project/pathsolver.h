#pragma once
#include "map2d.h"
using map_t = map2d;
class pathsolver
{
public:
	pathsolver() {}
	virtual ~pathsolver() {};
	virtual bool solve(const map_t& map) = 0;
	virtual std::vector<map_t::value_type> get_path() const = 0;
};

