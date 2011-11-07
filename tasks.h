#ifndef TASKS_H
#define TASKS_H

#include <QThread>

class FFTCalcTask : public QThread
{
    Q_OBJECT
public:
    explicit FFTCalcTask(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // TASKS_H
