// Sample.cpp : Defines the entry point for the application.
//

#include "Sample.h"
#include "pipeGnuPlot.h"
#include <sstream>

using namespace std;

int main()
{
	cout << "Hello GnuPlot" << endl;
	PipeGnuPlot gnuPlot;

	int xmin = -10;
	int xmax = 10;
	stringstream ss;
	ss << "set xrange[" << xmin << ":" << xmax << "]";
	gnuPlot.cmd(ss.str());

	gnuPlot.cmd("set yrange[-250:250]");
	gnuPlot.cmd("a = 0.6");
	gnuPlot.cmd("b = -1.6");
	gnuPlot.cmd("c = -25");
	gnuPlot.cmd("f(x) = a * x**3 + b * x**2 + c * x + 10");
	gnuPlot.cmd("plot f(x) title 'polynomial'");

	return 0;
}
