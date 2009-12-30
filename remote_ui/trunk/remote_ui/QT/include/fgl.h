#ifndef FGL
#define FGL
#include <QString>
#include <QHash>
#include <QDate>


namespace Fgl
{

   enum DataType { DTYPE_CHAR, DTYPE_SMINT, DTYPE_INT, DTYPE_FLOAT, DTYPE_SMFLOAT, DTYPE_DECIMAL, DTYPE_SERIAL, DTYPE_DATE, DTYPE_MONEY, DTYPE_NULL, DTYPE_DTIME, DTYPE_BYTE, DTYPE_TEXT, DTYPE_VCHAR, DTYPE_INTERVAL, DTYPE_NCHAR, DTYPE_INT8, DTYPE_SERIAL8};
   enum State { IDLE, MENU, INPUT, CONSTRUCT, DISPLAYARRAY, INPUTARRAY };
   enum EventType { BEFORE_FIELD_EVENT, AFTER_FIELD_EVENT, BEFORE_ROW_EVENT, AFTER_ROW_EVENT, MENUACTION_EVENT, ACTION_EVENT, ONKEY_EVENT, BEFORE_INPUT_EVENT, AFTER_INPUT_EVENT, BEFORE_CONSTRUCT_EVENT, AFTER_CONSTRUCT_EVENT, BEFORE_DISPLAY_EVENT, AFTER_DISPLAY_EVENT, BEFORE_MENU_EVENT, AFTER_MENU_EVENT, BEFORE_INSERT_DELETE_EVENT, AFTER_INSERT_DELETE_EVENT };

   typedef struct {
      EventType type;
      int id;
      QString attribute;
   } Event;

   typedef struct {
     QString colName;
     int fieldIdRef;
   } Link;

  QString stringToKey(QString);

      extern QHash<QString, QString> env;
      DataType decodeDataType(QString);
      bool usingFunc(QString, QString*, DataType);
      QDate getDate(QString);

      bool fgl_using(QString, QString*);
      bool fgl_using_date(QString, QString*);
      bool fgl_using_string(QString, QString*, bool);

      QString dbDateToFormat(QString);
      bool isValidForType(DataType, QString, QString);
};

#endif
