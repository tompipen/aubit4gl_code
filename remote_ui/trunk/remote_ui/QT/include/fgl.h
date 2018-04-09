#ifndef FGL
#define FGL
#include <QString>
#include <QHash>
#include <QDate>

namespace Fgl
{

   enum DataType { DTYPE_CHAR, DTYPE_SMINT, DTYPE_INT, DTYPE_FLOAT, DTYPE_SMFLOAT, DTYPE_DECIMAL, DTYPE_SERIAL, DTYPE_DATE, DTYPE_MONEY, DTYPE_NULL, DTYPE_DTIME, DTYPE_BYTE, DTYPE_TEXT, DTYPE_VCHAR, DTYPE_INTERVAL, DTYPE_NCHAR, DTYPE_INT8, DTYPE_SERIAL8};
   enum State { IDLE, MENU, INPUT, CONSTRUCT, DISPLAYARRAY, INPUTARRAY };
   enum EventType { BEFORE_FIELD_EVENT, AFTER_FIELD_EVENT, BEFORE_ROW_EVENT, AFTER_ROW_EVENT, MENUACTION_EVENT, ONACTION_EVENT, ONKEY_EVENT, BEFORE_INPUT_EVENT, AFTER_INPUT_EVENT, BEFORE_CONSTRUCT_EVENT, AFTER_CONSTRUCT_EVENT, BEFORE_DISPLAY_EVENT, AFTER_DISPLAY_EVENT, BEFORE_MENU_EVENT, AFTER_MENU_EVENT, BEFORE_INSERT_DELETE_EVENT, AFTER_INSERT_DELETE_EVENT , BEFORE_INSERT_EVENT , AFTER_INSERT_EVENT , BEFORE_DELETE_EVENT , AFTER_DELETE_EVENT , GUI_ACTION_EVENT};

   typedef struct {
      EventType type;
      QString id;
      QString attribute;
      QString field;
   } Event;

   typedef struct {
     QString colName;
     int fieldIdRef;
   } Link;

  QString stringToKey(QString);
  QString keyToString(QString);

      extern QHash<QString, QString> env;
      DataType decodeDataType(QString);
      QString usingFunc(QString, QString, DataType, QString picture = "");
      QDate getDate(QString);
      QString getDateFormat(QString, QString);

      QString fgl_using(QString, QString);
      QString fgl_using_date(QString, QString);
      QString fgl_using_string(QString, QString, bool, QString dbmoney = "");
      QString fgl_convert_money(QString);
      QString vdc_to_fgl(QString, QString, DataType);


      QString getValueFromEnv(QString);
      QString dbDateToFormat(QString);
      QChar getDBDateSeperator(QString);
      bool isValidForType(DataType, QString, QString);

   enum FieldAttributes { AUBIT_COLOR_BLACK     = 0x00000,
                          AUBIT_COLOR_RED       = 0x00100,
                          AUBIT_COLOR_GREEN     = 0x00200,
                          AUBIT_COLOR_YELLOW    = 0x00300,
                          AUBIT_COLOR_BLUE      = 0x00400,
                          AUBIT_COLOR_MAGENTA   = 0x00500,
                          AUBIT_COLOR_CYAN      = 0x00600,
                          AUBIT_COLOR_WHITE     = 0x00700,
                          AUBIT_ATTR_NORMAL     = 0x0,
                          AUBIT_ATTR_REVERSE    = 0x01000,
                          AUBIT_ATTR_UNDERLINE  = 0x02000,
                          AUBIT_ATTR_BOLD       = 0x04000,
                          AUBIT_ATTR_BLINK      = 0x08000,
                          AUBIT_ATTR_DIM        = 0x10000,
                          AUBIT_ATTR_INVISIBLE  = 0x20000,
                          AUBIT_ATTR_ALTCHARSET = 0x40000,
                          AUBIT_ATTR_LEFT       = 0x80000 };
};

#endif
