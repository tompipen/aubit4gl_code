#ifndef FGL
#define FGL

class Fgl
{

public:
   enum State { IDLE, MENU, INPUT, CONSTRUCT, DISPLAYARRAY, INPUTARRAY };

   enum EventType { BEFORE_FIELD_EVENT, AFTER_FIELD_EVENT, BEFORE_ROW_EVENT, AFTER_ROW_EVENT, ONKEY_EVENT, ONACTION_EVENT, BEFORE_INPUT_EVENT, AFTER_INPUT_EVENT, BEFORE_CONSTRUCT_EVENT, AFTER_CONSTRUCT_EVENT, BEFORE_DISPLAY_EVENT, AFTER_DISPLAY_EVENT, BEFORE_MENU_EVENT, AFTER_MENU_EVENT };

   typedef struct {
      EventType type;
      int id;
      QString attribute;
   } Event;

   typedef struct {
     QString colName;
     int fieldIdRef;
   } Link;

/*
   typedef struct {
      State state;
      QStringList fieldList;
      QHash<QString, int> options;
   } Context;
*/
};

#endif
