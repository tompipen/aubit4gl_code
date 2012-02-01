#include <QApplication>
#include <QStringList>
#include <QDir>
#include "test_fgl.h"
int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    QStringList testCmd;
    QDir qtestLogDir;
//    qtestLogDir.mkdir("UnitTest_Results");
//    testCmd<<" "<<"-o"<<"UnitTest_Results/QTestString_log.txt";
    Test_fgl test_fgl;
    QTest::qExec(&test_fgl, testCmd);
    return 0;
    //return a.exec();
}
