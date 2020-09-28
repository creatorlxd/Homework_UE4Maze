#pragma once
#include <vector>
#include <fstream>

enum class MazeType :int
{
	None = 0,
	Wall = 1,
	Src = 2,
	Dst = 3
};

struct MazeMap
{
	int x, y;
	std::vector<std::vector<MazeType>> m_Content;
};

std::istream& operator >> (std::istream& in, MazeMap& m);
std::ostream& operator << (std::ostream& out, const MazeMap& m);