#ifndef FGL
#define FGL


class Fgl
{

public:
   enum State { IDLE, MENU, INPUT, CONSTRUCT, DISPLAYARRAY, INPUTARRAY };

   enum EventType { BEFORE_FIELD_EVENT, AFTER_FIELD_EVENT, BEFORE_ROW_EVENT, AFTER_ROW_EVENT, ONKEY_EVENT, ONACTION_EVENT, BEFORE_INPUT_EVENT, AFTER_INPUT_EVENT, BEFORE_CONSTRUCT_EVENT, AFTER_CONSTRUCT_EVENT, BEFORE_DISPLAY_EVENT, AFTER_DISPLAY_EVENT, BEFORE_MENU_EVENT, AFTER_MENU_EVENT, BEFORE_INSERT_DELETE_EVENT, AFTER_INSERT_DELETE_EVENT };

   typedef struct {
      EventType type;
      int id;
      QString attribute;
   } Event;

   typedef struct {
     QString colName;
     int fieldIdRef;
   } Link;

   static QString stringToKey(QString s) {
      if(s.toLower().startsWith("f")){
         s.remove(0,1);
         bool ok = false;
         int key = s.toInt(&ok);
         if(ok){
            key += 2999;
            return QString::number(key);
         }
      }
      else{
         if(s.toLower() == "up")
            return QString::number(2000);
         if(s.toLower() == "down")
            return QString::number(2001);
         if(s.toLower() == "left")
            return QString::number(2002);
         if(s.toLower() == "right")
            return QString::number(2003);
         if(s.toLower() == "help")
            return QString::number(2008);
         if(s.toLower() == "prevpage")
            return QString::number(2006);
         if(s.toLower() == "accept")
            return QString::number(2016);
         if(s.toLower() == "esc")
            return QString::number(27);
         if(s.toLower() == "escape")
            return QString::number(27);

         if(s.toLower() == "control-a")
            return QString::number(1);
         if(s.toLower() == "control-b")
            return QString::number(2);
         if(s.toLower() == "control-c")
            return QString::number(3);
         if(s.toLower() == "control-d")
            return QString::number(4);
         if(s.toLower() == "control-e")
            return QString::number(5);
         if(s.toLower() == "control-f")
            return QString::number(6);
         if(s.toLower() == "control-g")
            return QString::number(7);
         if(s.toLower() == "control-h")
            return QString::number(8);
         if(s.toLower() == "control-i")
            return QString::number(9);
         if(s.toLower() == "control-j")
            return QString::number(10);
         if(s.toLower() == "control-k")
            return QString::number(11);
         if(s.toLower() == "control-l")
            return QString::number(12);
         if(s.toLower() == "control-m")
            return QString::number(13);
         if(s.toLower() == "control-n")
            return QString::number(14);
         if(s.toLower() == "control-o")
            return QString::number(15);
         if(s.toLower() == "control-p")
            return QString::number(16);
         if(s.toLower() == "control-q")
            return QString::number(17);
         if(s.toLower() == "control-r")
            return QString::number(18);
         if(s.toLower() == "control-s")
            return QString::number(19);
         if(s.toLower() == "control-t")
            return QString::number(20);
         if(s.toLower() == "control-u")
            return QString::number(21);
         if(s.toLower() == "control-v")
            return QString::number(22);
         if(s.toLower() == "control-w")
            return QString::number(23);
         if(s.toLower() == "control-x")
            return QString::number(24);
         if(s.toLower() == "control-y")
            return QString::number(25);
         if(s.toLower() == "control-z")
            return QString::number(26);
      }

      return s;
   };

/*
   typedef struct {
      State state;
      QStringList fieldList;
      QHash<QString, int> options;
   } Context;
*/
};

#endif
