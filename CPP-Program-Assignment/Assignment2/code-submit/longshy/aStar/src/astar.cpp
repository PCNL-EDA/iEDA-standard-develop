#include "project/astar.h"

double astar::distance(const value_type& lhs, const value_type& rhs) {
	return (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y);
}

astar::astar()
{
}

bool astar::solve(const map_t& map) {
	m_dead.clear();
	m_path.clear();

	std::vector<typename map_t::value_type> next;
	typename map_t::value_type start = map.get_start_location();
	typename map_t::value_type end = map.get_end_location();
	m_path.push_back(start);
	typename map_t::value_type curr;
	while (m_path.empty() == false) {
		curr = m_path.back();
		if (curr == end)
			break;
		map.get_adjacent_location(curr, next);
		//如果相邻的点集next为空，则把当前点curr从路径中m_inpath清除，放到m_dead，从m_inpath清除（不走死路）
		if (next.empty()) {
			m_inpath.erase(curr);
			m_dead.insert(curr);
			m_path.pop_back();
		}
		else {
			//将next中的点进行从小到大的排序，在遍历时优先选择距离终点距离小的点
			std::sort(next.begin(), next.end(), [&](const map_t::value_type& lhs, const map_t::value_type& rhs) {
				return distance(lhs, end) < distance(rhs, end);
				});
			bool flag = false;
			for (const map_t::value_type& n : next) {
				//不走已经走过的路
				if (m_dead.find(n) == m_dead.end() && m_inpath.find(n) == m_inpath.end()) {
					flag = true;
					m_path.push_back(n);
					m_inpath.insert(n);
					break;
				}
			}
			//如果是已经走过的点，进行相应的处理
			if (flag == false) {
				m_inpath.erase(curr);
				m_dead.insert(curr);
				m_path.pop_back();
			}
		}
	}
	return m_path.empty() == false;
}

std::vector<value_type> astar::get_path() const {
	return m_path;
}