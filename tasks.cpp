#include "tasks.h"
#include <QThread>

void FFTCalcTask::run()
{
    exec();
    //quit();
}

void MatrixMultiplyTask::run(QString filePath)
{
    int size;
    float[][] a;
    float[][] b;
    float[][] c;

    // read two input square matrices into a[][] and b[][]
    QFile inputFile(filePath);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return; // FAULT occurs here

    QTextStream input(&filePath);
    while (!input.atEnd()) {
        QString line = input.readLine();
        //TODO: process line
    }


    // Do real multiplication in memory and stores it in the c[][] matrix
    for (int i = 0 ; i< size ; i++)
    {
        for (int j = 0; j < size ; j++)
        {
            c[i][j] = 0.0;
            for (int k = 0; k < size ; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // write output (if necessary)
    /**
    QFile outputFile(outputPath);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return; // FAULT occurs here

    QTextStream output(&outputFile);
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = 0 ; j < size ; j++)
        {
            output << c[i][j] << " ";
        }
        output << "\n";
    }
    */

    // clean up memory
    for (int i = 0 ; i < size ; i++)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];
    }

    exec();
    //quit();
}

void SortTask::run(QString filePath)
{
    float[] numbers;

    // read input numbers into numbers[]
    QFile inputFile(filePath);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return; // FAULT occurs here

    QTextStream input(&filePath);
    while (!input.atEnd()) {
        QString line = input.readLine();
        //TODO: process line
    }


    //TODO: sort

    // write output sorted sequence into file (if necessary)
    /**
    QFile outputFile(outputPath);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
        return; // FAULT occurs here

    QTextStream output(&outputFile);
    for (int i = 0 ; i < size ; i++)
    {
        output << numbers[i] << " ";
    }
    output << "\n";
    */

    // cleanup memory
    delete[] numbers;
    exec();
    //quit();
}
