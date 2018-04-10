#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>


class Logger : public QObject
{
public:
    enum LogLevel {
        All = 4,
        Critical = 3,
        Warning = 2,
        Information = 1
    };

    void setLogLevel(int level) { m_logLevel = static_cast<LogLevel>(level); }

    LogLevel getLogLevel() { return m_logLevel; }

    void log(int level, QString);

    static Logger& instance()
    {
        static Logger _instance;
        return _instance;
    }
private:
    LogLevel m_logLevel;
};

#endif // LOGGER_H
