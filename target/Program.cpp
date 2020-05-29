#include "Program.h"
#include "robot.h"

void Program::Main(std::vector<std::wstring> &args)
{
	robot *a = new robot(L"/Users/shaunlee/Projects/P3/P3/grid.txt", 1);

	delete a;
}
