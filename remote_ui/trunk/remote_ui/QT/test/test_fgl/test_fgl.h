#ifndef TEST_FGL_H
#define TEST_FGL_H

#include <QtTest/QtTest>

class Test_fgl: public QObject {

    Q_OBJECT

private slots:
    void convert_money_test();
    void convert_money_test_data();

    void getDBDateSeperator_test();
    void getDBDateSeperator_test_data();

    void getDate_test_mdy4();
    void getDate_test_mdy4_data();

    void getDate_test_dmy();
    void getDate_test_dmy_data();

    void getDate_test_ydm();
    void getDate_test_ydm_data();

    void getDate_test_mdy2();
    void getDate_test_mdy2_data();

};

#endif // TEST_FGL_H
