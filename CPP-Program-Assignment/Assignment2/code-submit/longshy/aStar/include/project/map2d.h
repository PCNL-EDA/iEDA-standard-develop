#pragma once
#include <vector>
#include <functional>

//用location2d表示地图中的坐标点
struct location2d {
	int x, y;
	location2d(int x_ = -1, int y_ = -1) : x(x_), y(y_) {}
	location2d operator+(const location2d& rhs) const {
		return location2d(x + rhs.x, y + rhs.y);
	}
	bool operator==(const location2d& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator<(const location2d& rhs) const {
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
};

//构建地图的类
class map2d
{
public:
	using value_type = location2d;
	map2d(const std::vector<std::vector<char>>& rawmap,
		const std::vector<value_type>& move,
		const value_type& start, const value_type& end);
	void get_adjacent_location(const value_type& curr, std::vector<value_type>& rlt) const;
	value_type get_start_location() const;
	value_type get_end_location() const;
	char get_element(const value_type& curr) const;
	int get_rows() const;
	int get_cols() const;
private:
	bool is_feaseable(const value_type& location) const;
	std::vector<std::vector<char>> m_map;
	std::vector<value_type> m_move;
	const value_type m_start, m_end;
};

