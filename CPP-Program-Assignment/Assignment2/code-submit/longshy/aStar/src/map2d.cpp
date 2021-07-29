#include "project/map2d.h"

map2d::map2d(const std::vector<std::vector<char>>& rawmap, const std::vector<value_type>& move, const value_type& start, const value_type& end)
	: m_map(rawmap), m_move(move), m_start(start), m_end(end) {
}

void map2d::get_adjacent_location(const value_type& curr, std::vector<value_type>& rlt) const
{
	rlt.clear();
	for (int i = 0; i < m_move.size(); i++) {
		value_type next = curr + m_move[i];
		if (is_feaseable(next)) {
			rlt.push_back(next);
		}
	}
	return;
}

map2d::value_type map2d::get_start_location() const
{
	return m_start;
}

map2d::value_type map2d::get_end_location() const
{
	return m_end;
}

char map2d::get_element(const value_type& curr) const
{
	return m_map[curr.y][curr.x];
}

int map2d::get_rows() const
{
	return m_map.size();
}

int map2d::get_cols() const
{
	return m_map.empty() ? 0 : static_cast<int>(m_map[0].size());
}

bool map2d::is_feaseable(const value_type& location) const
{
	return location.y >= 0 && location.y < get_rows() && location.x >= 0 && location.y < get_cols() && get_element(location) != 'x';
}



