#include "MyMaze.h"

std::istream& operator>>(std::istream& in, MazeMap& m)
{
	in >> m.x >> m.y;
	m.m_Content.resize(m.x, std::vector<MazeType>(m.y, MazeType::None));
	for (int i = 0; i < m.x; i++)
	{
		for (int j = 0; j < m.y; j++)
		{
			int b;
			in >> b;
			m.m_Content[i][j] = (MazeType)b;
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const MazeMap& m)
{
	out << m.x << " " << m.y << std::endl;
	for (int i = 0; i < m.x; i++)
	{
		for (int j = 0; j < m.y; j++)
		{
			out << (int)m.m_Content[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}
