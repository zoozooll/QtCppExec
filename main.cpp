#include <QCoreApplication>

#include <iostream>

#include "jsonexec.h"
#include "json_exercise2.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    jsonExercise();
//    json_exercise2_run();
    return a.exec();
}
