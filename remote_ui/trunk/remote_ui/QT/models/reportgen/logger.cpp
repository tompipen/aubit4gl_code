#include "logger.h"

/*!
    \class Logger
    \brief Die Logger Klasse dient für die Ausgabe bestimmter Meldungen anhand des debug levels.

    Die Logger Klasse dient für die Ausgabe bestimmter Meldungen anhand des debug levels. Es handelt sich hierbei um eine Statische Klasse die ohne Instanzieren benutzt werden kann.

    Beispiel:

    Logger::instance().log(1, "Meine Log Meldung");

    Es gibt 4 verschiedene Loglevels:
        \li All = 4,
        \li Critical = 3,
        \li Warning = 2,
        \li Information = 1

*/

void Logger::log(int level, QString msg)
{

    LogLevel log = static_cast<LogLevel>(level);

    if (getLogLevel() == All) {
        qDebug() << "[LOG]: " << msg;
    }

    if (log == getLogLevel()) {
        qDebug() << "[LOG]: " << msg;
    }
}
