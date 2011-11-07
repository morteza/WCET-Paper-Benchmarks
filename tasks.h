#ifndef TASKS_H
#define TASKS_H

#include <QThread>

class FFTCalcTask : public QThread
{
public:
    void run();
};

class SortTask : public QThread
{
public:
    void run(QString filePath);
};

class MatrixMultiplyTask : public QThread
{
public:
    void run(QString filePath);
};

#endif // TASKS_H
