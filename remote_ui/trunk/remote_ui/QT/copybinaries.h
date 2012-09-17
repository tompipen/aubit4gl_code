#ifndef COPYBINARIES_H
#define COPYBINARIES_H

#include <QString>
#include <QObject>

class CopyBinaries : public QObject
{

public:
    CopyBinaries();
    void start(QString tmpDirPath, QString newDirPath);
    void copyBinaries(QString, QString);
    void logMessage(QString msg);
};

#endif // COPYBINARIES_H
