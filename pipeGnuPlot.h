#ifndef PIPE_GNUPLOT_H
#define PIPE_GNUPLOT_H

#include <string>

class PipeGnuPlot
{
public:
    PipeGnuPlot(bool persistent = true)
    {
#ifdef __unix__
        if(persistent)
            pipeHandle = popen("gnuplot -persistent", "w");
        else
            pipeHandle = popen("gnuplot", "w");
#else
        if(persistent)
            pipeHandle = _popen("gnuplot -persistent", "w");
        else
            pipeHandle = _popen("gnuplot", "w");
#endif       
    }

    ~PipeGnuPlot()
    {
        cmd("exit");
#ifdef __unix__
        pclose(pipeHandle);
#else
        _pclose(pipeHandle);
#endif
    }

    void cmd(std::string args) {
        fprintf(pipeHandle, "%s\n", args.c_str());
        fflush(pipeHandle);
    }

private:
    FILE *pipeHandle;
};

#endif
