#ifndef MANAGER_H
#define MANAGER_H

#include <QString>

class Manager
{
public:
    Manager(QString logFilePath);
    log(QString str);
};

#endif // MANAGER_H
