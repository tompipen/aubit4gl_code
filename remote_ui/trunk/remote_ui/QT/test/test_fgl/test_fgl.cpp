#include "test_fgl.h"
#include <../../include/fgl.h>


void Test_fgl::convert_money_test() {

    QFETCH(QString, value);
    QFETCH(QString, result);

    QCOMPARE(Fgl::fgl_convert_money(value), result);

}

void Test_fgl::convert_money_test_data() {

    Fgl::env["DBMONEY"] = ",";

    QTest::addColumn<QString>("value");
    QTest::addColumn<QString>("result");

    QTest::newRow("ohne alles") << "1234" << "1234";
    QTest::newRow("mit Punkt") << "0.000004" << "0,000004";
    QTest::newRow("mit Punkt") << "-0.000004" << "-0,000004";
    QTest::newRow("mit Punkt") << "1234.5" << "1234,5";
    QTest::newRow("mit Punkt") << "1234.56" << "1234,56";
    QTest::newRow("mit Punkt") << "1234.567" << "1234,567";
    QTest::newRow("mit Punkt") << "1234.5678" << "1234,5678";
    QTest::newRow("mit Punkt") << "1234.56789" << "1234,56789";
    QTest::newRow("mit Komma") << "98765,43" << "98765,43";
    QTest::newRow("mit Komma") << "98765,432" << "98765,432";
    QTest::newRow("mit Komma") << "98765,4321" << "98765,4321";
    QTest::newRow("mit Komma") << "98765,43210" << "98765,43210";
    QTest::newRow("mit Komma") << "-0,000007892" << "-0,000007892";



}

void Test_fgl::getDBDateSeperator_test(){

    QFETCH(QString, dbdate);
    QFETCH(QChar, result);

    QCOMPARE(Fgl::getDBDateSeperator(dbdate), result);
}

void Test_fgl::getDBDateSeperator_test_data(){

    QTest::addColumn<QString>("dbdate");
    QTest::addColumn<QChar>("result");

    QTest::newRow("Slash") << "MDY4/" << QChar('/');
    QTest::newRow("Minus") << "MDY4-" << QChar('-');
    QTest::newRow("Punkt") << "MDY4." << QChar('.');
    QTest::newRow("Null") << "MDY40" << QChar('0');

    QTest::newRow("Slash") << "DMY4/" << QChar('/');
    QTest::newRow("Minus") << "DMY4-" << QChar('-');
    QTest::newRow("Punkt") << "DMY4." << QChar('.');
    QTest::newRow("Null") << "DMY40" << QChar('0');


}

void Test_fgl::getDate_test_mdy4() {

    QFETCH(QString, date);
    QFETCH(QDate, result);

    QDate date2 = Fgl::getDate(date);

    QCOMPARE(date2, result);

}

void Test_fgl::getDate_test_mdy4_data() {

    QDate date;
    QDate currentDate;
    currentDate = currentDate.currentDate();
    QString today;
    QString result;
    QString dateString = "";
    QDate resultDate;

    QTest::addColumn<QString>("date");
    QTest::addColumn<QDate>("result");


    Fgl::env["DBDATE"] = "MDY40";


    // test DBDATE = MDY40
    today = date.currentDate().toString("MMddyyyy");
    result = date.currentDate().toString("ddd MMM dd yyyy");
    QTest::newRow("0 currentDate") << today << currentDate;

    // test leap year
    QTest::newRow("leap year") << "02292012" << QDate(2012, 2, 29);

    // test year
    for(int year = 2012; year <= 2022; year++) {
        for(int month = 1; month <= 12; month++) {
            for(int day = 1; day <= 31; day++) {

                if ((month == 2) & (day > 28)) break;
                if ((month == 4 || month == 6 || month == 9 || month == 11) & (day >30)) break;

                dateString.append(QString("%1").arg(month, 2));
                dateString.append("");
                dateString.append(QString("%1").arg(day, 2));
                dateString.append("");
                dateString.append(QString("%1").arg(year));
                // result
                resultDate = QDate(year, month, day);

                QTest::newRow("for-Schleife") << dateString << resultDate;

                dateString = "";

            }
        }
    }


    // test DBDATE = MDY4.

    today = date.currentDate().toString("MM.dd.yyyy");
    result = date.currentDate().toString("ddd MMM dd yyyy");

    QTest::newRow("4 currentDate") << today << currentDate;


    for(int year = 2012; year <= 2022; year++) {
        for(int month = 1; month <= 12; month++) {
            for(int day = 1; day <= 31; day++) {

                if ((month == 2) & (day > 28)) break;
                if ((month == 4 || month == 6 || month == 9 || month == 11) & (day >30)) break;

                dateString.append(QString("%1").arg(month, 2));
                dateString.append(".");
                dateString.append(QString("%1").arg(day, 2));
                dateString.append(".");
                dateString.append(QString("%1").arg(year));

                resultDate = QDate(year, month, day);

                QTest::newRow("for-Schleife") << dateString << resultDate;

                dateString = "";

            }
        }
    }
}

void Test_fgl::getDate_test_dmy() {

    QFETCH(QString, date);
    QFETCH(QDate, result);

    QDate date2 = Fgl::getDate(date);

    QCOMPARE(date2, result);

}

void Test_fgl::getDate_test_dmy_data() {

    QDate date;
    QDate currentDate;
    currentDate = currentDate.currentDate();
    QString today;
    QString result;
    QString dateString = "";
    QDate resultDate;

    QTest::addColumn<QString>("date");
    QTest::addColumn<QDate>("result");


    Fgl::env["DBDATE"] = "DMY4/";

    // test DBDATE = DMY4/
    today = date.currentDate().toString("dd/MM/yyyy");
    result = date.currentDate().toString("ddd MMM dd yyyy");
    QTest::newRow("8 currentDate") << today << currentDate;


    for(int year = 2012; year <= 2022; year++) {
        for(int month = 1; month <= 12; month++) {
            for(int day = 1; day <= 31; day++) {

                if ((month == 2) & (day > 28)) break;
                if ((month == 4 || month == 6 || month == 9 || month == 11) & (day >30)) break;

                dateString.append(QString("%1").arg(day));
                dateString.append("/");
                dateString.append(QString("%1").arg(month));
                dateString.append("/");
                dateString.append(QString("%1").arg(year));
                // result
                resultDate = QDate(year, month, day);

                QTest::newRow("for-Schleife") << dateString << resultDate;

                dateString = "";

            }
        }
    }

}

void Test_fgl::getDate_test_ydm() {

    QFETCH(QString, date);
    QFETCH(QDate, result);

    QDate date2 = Fgl::getDate(date);

    QCOMPARE(date2, result);
}

void Test_fgl::getDate_test_ydm_data() {

    QDate date;
    QDate currentDate;
    currentDate = currentDate.currentDate();
    QString today;
    QString result;
    QString dateString = "";
    QDate resultDate;

    QTest::addColumn<QString>("date");
    QTest::addColumn<QDate>("result");


    // test DBDATE = YDM4/
    Fgl::env["DBDATE"] = "YDM4/";


    today = date.currentDate().toString("yyyy/dd/MM");
    result = date.currentDate().toString("ddd MMM dd yyyy");
    QTest::newRow("16 currentDate") << today << currentDate;


    for(int year = 2012; year <= 2022; year++) {
        for(int month = 1; month <= 12; month++) {
            for(int day = 1; day <= 31; day++) {

                if ((month == 2) & (day > 28)) break;
                if ((month == 4 || month == 6 || month == 9 || month == 11) & (day >30)) break;

                dateString.append(QString("%1").arg(year));
                dateString.append("/");
                dateString.append(QString("%1").arg(day));
                dateString.append("/");
                dateString.append(QString("%1").arg(month));
                // result
                resultDate = QDate(year, month, day);

                QTest::newRow("for-Schleife") << dateString << resultDate;

                dateString = "";

            }
        }
    }

}

void Test_fgl::getDate_test_mdy2() {

    QFETCH(QString, date);
    QFETCH(QDate, result);

    QDate date2 = Fgl::getDate(date);

    QCOMPARE(date2, result);

}

void Test_fgl::getDate_test_mdy2_data() {

    QDate date;
    QDate currentDate;
    currentDate = currentDate.currentDate();
    QString today;
    QString result;
    QString dateString = "";
    QDate resultDate;

    QTest::addColumn<QString>("date");
    QTest::addColumn<QDate>("result");



    // test DBDATE = MDY2-
    Fgl::env["DBDATE"] = "MDY2-";


    for(int year = 12; year <= 22; year++) {
        for(int month = 1; month <= 12; month++) {
            for(int day = 1; day <= 31; day++) {
                // einige Monate sind kürzer
                if ((month == 2) & (day > 28)) break;
                if ((month == 4 || month == 6 || month == 9 || month == 11) & (day >30)) break;
                // Teststring erstellen
                dateString.append(QString("%1").arg(month)); // zweistellig
                dateString.append("-");
                dateString.append(QString("%1").arg(day));
                dateString.append("-");

                dateString.append(QString("%1").arg(year));
                // result erstellen
                resultDate = QDate(year, month, day);

                QTest::newRow("for-Schleife") << dateString << resultDate;

                dateString = "";

            }
        }
    }

}

