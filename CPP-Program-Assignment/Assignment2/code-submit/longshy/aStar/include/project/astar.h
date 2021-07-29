#pragma once
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include "map2d.h"
#include "pathsolver.h"

using value_type = location2d;
using map_t = map2d;
class astar : public pathsolver
{
private:
    // 已经遍历的点集
	std::set<value_type> m_dead;
	// 待遍历的点集
	std::set<value_type> m_inpath; 
	// 记录路径 
	std::vector<value_type> m_path;
	double distance(const value_type& lhs, const value_type& rhs);
public:
	astar();
	bool solve(const map_t& map) override;
	std::vector<value_type> get_path() const override;
};

