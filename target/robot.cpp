#include "robot.h"
#include "actuator.h"
#include "sensor.h"

robot::robot(const std::wstring &str, double drainRate)
{
	if (str == L"")
	{
		throw std::invalid_argument("invalid file");
	}
	orientationState = orientation::Up;
	filename = str;
//C# TO C++ CONVERTER NOTE: The following call to the 'RectangularVectors' helper class reproduces the rectangular array initialization that is automatic in C#:
//ORIGINAL LINE: grid = new int[SIZE, SIZE];
	grid = RectangularVectors::RectangularIntVector(SIZE, SIZE);
	count = 0;
	upSensor = new sensor(drainRate,0,grid);
	downSensor = new sensor(drainRate,1,grid);
	rightSensor = new sensor(drainRate,2,grid);
	leftSensor = new sensor(drainRate,3,grid);
	nAct = new actuator(0);
	sAct = new actuator(1);
	eAct = new actuator(2);
	wAct = new actuator(3);
	rCoord = 5;
	cCoord = 5;
	state = true;
	std::wstring text = System::IO::File::ReadAllText(filename);
	std::wstring ss = StringHelper::replace(text, L"\n", L" ");
	ss = std::wstring::Join(L" ", ss.Split({L' '}, StringSplitOptions::RemoveEmptyEntries));
	std::vector<std::wstring> arr = StringHelper::split(ss, L' ');
	for (int r = 0; r <= 10; r++)
	{
		for (int c = 0; c <= 10; c++)
		{
			grid[r][c] = std::stoi(arr[count]);
			count++;
		}
	}
}

bool robot::isValid()
{

	return (upSensor->isValid(rCoord,cCoord) && downSensor->isValid(rCoord,cCoord) && rightSensor->isValid(rCoord,cCoord) && leftSensor->isValid(rCoord,cCoord));
}

int robot::getColumn()
{
	return cCoord;
}

int robot::getRow()
{
	return rCoord;
}

void robot::Move()
{
	while (upSensor->isValid(rCoord,cCoord))
	{
		nAct->MoveForward(rCoord, cCoord);
	}
}

void robot::MoveOne()
{
	if (upSensor->isValid(rCoord,cCoord))
	{
		nAct->MoveForward(rCoord, cCoord);
	}
}

bool robot::isPowered()
{
	return state;
}

void robot::Recharge()
{
	upSensor->Recharge();
	downSensor->Recharge();
	rightSensor->Recharge();
	leftSensor->Recharge();
}
