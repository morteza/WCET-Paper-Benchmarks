#include "tasks.h"
#include <QThread>

void DFTCalcTask::run()
{
    double arg;
    double cosArg,sinArg;


    //TODO: read x1[], y1[], and size from file or something

    double[] x2 = new double[size];
    double[] y2 = new double[size];

    if (x2 == NULL || y2 == NULL)
       return; // FAULT occurs

    for (long i=0;i<size;i++)
    {
       x2[i] = 0;
       y2[i] = 0;
       arg = -2.0 * 3.141592654 * (double)i / (double)size;
       for (long k=0;k<size;k++)
       {
          cosArg = cos(k * arg);
          sinArg = sin(k * Arg);
          x2[i] += (x1[k] * cosArg - y1[k] * sinArg);
          y2[i] += (x1[k] * sinArg + y1[k] * cosArg);
       }
    }

    for (long i=0;i<size;i++)
    {
        x1[i] = x2[i] / (double)size;
        y1[i] = y2[i] / (double)size;
    }

    delete[] x2;
    delete[] y2;

    //TODO: store x1[], and y1[] into output file(s)

    delete[] x1;
    delete[] y1;

    exec();
    //quit();
}

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
    double[] numbers;
    int size;

    // read input numbers into numbers[]
    QFile inputFile(filePath);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return; // FAULT occurs here

    QTextStream input(&filePath);
    while (!input.atEnd()) {
        QString line = input.readLine();
        //TODO: process line and stores into numbers
    }


    // Bubble sort
    bool isSwapped = true;
    int tmp, j = 0;
    while (isSwapped)
    {
        isSwapped = false;
        j++;
        for (int i = 0; i < size - j; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                tmp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = tmp;
                isSwapped = true;
            }
        }
    }

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
