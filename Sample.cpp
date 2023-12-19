// Sample.cpp : Defines the entry point for the application.
//

#include "Sample.h"
#include "pipeGnuPlot.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	PipeGnuPlot gnuPlot;
	gnuPlot.cmd("plot sin(x) title 'Sine Function'");

	return 0;
}
