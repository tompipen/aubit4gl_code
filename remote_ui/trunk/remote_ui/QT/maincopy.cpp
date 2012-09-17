#include "copybinaries.h"
#include <QDebug>
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    CopyBinaries cBinaries;
    QCoreApplication a(argc, argv);
    cBinaries.logMessage("[DEBUG] fange an");

    if(argc < 2)
    {
        return 0;
    }

    QString arg1;
    QString arg2;

    if(argv[1] != NULL && argv[2] != NULL)
    {
        arg1 = argv[1];
        arg2 = argv[2];
    }

    cBinaries.start(arg1, arg2);

}
