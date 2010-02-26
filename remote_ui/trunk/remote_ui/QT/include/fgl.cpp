#include <include/fgl.h>
#include <QStringList>
#include <QDebug>

namespace Fgl {
   QHash<QString, QString> env;

   bool usingFunc(QString fmt, QString *value, DataType dataType)
   {
      switch(dataType){
         case DTYPE_DECIMAL:
         case DTYPE_MONEY:
            {
            bool isneg = false;
            QByteArray p = value->toAscii();
            for (int a = 0; a < p.size(); a++)
            {
               if (p[a] >= '0' && p[a] <= '9') continue;
               if (p[a] == '.') { p[a] = '.'; continue; }
               if (p[a] == '-') { p[a] = ' '; isneg = true; continue; }
               p[a] = ' ';
            }

            fgl_using_string(fmt, value, isneg);

            
            }
            break;
         case DTYPE_BYTE:
         case DTYPE_SMINT:
         case DTYPE_INT:
         case DTYPE_SERIAL:
         case DTYPE_SMFLOAT:
         case DTYPE_FLOAT:
            fgl_using(fmt, value);
            break;

         case DTYPE_DATE:
            fgl_using_date(fmt, value);
            break;
         case DTYPE_CHAR:
         case DTYPE_NULL:
         case DTYPE_DTIME:
         case DTYPE_TEXT:
         case DTYPE_VCHAR:
         case DTYPE_INTERVAL:
         case DTYPE_NCHAR:
            break;
         default:
            if (fmt.contains("dd") || fmt.contains("mm") || fmt.contains("yy") ||
                fmt.contains("DD") || fmt.contains("MM") || fmt.contains("YY"))
            {
                return fgl_using_date(fmt, value);
            }
            else
            {
                return fgl_using(fmt, value);
            }
      }
      return true;
   }

   bool fgl_using(QString fmt, QString *value)
   {
      Q_UNUSED(fmt);
      Q_UNUSED(value);
      return true;
   }

   bool fgl_using_date(QString fmt, QString *value)
   {
      QDate d = getDate(*value);
      fmt = fmt.replace("mmmm", "MMMM");
      fmt = fmt.replace("mmm", "MMM");
      fmt = fmt.replace("mm", "MM");
      *value = d.toString(fmt);

      return true;
   }

   bool fgl_using_string(QString fmt, QString *value, bool isneg)
   {
       Q_UNUSED(fmt);
       Q_UNUSED(value);
       Q_UNUSED(isneg);
      return true;
   }

   DataType decodeDataType(QString type)
   {
      if(type.startsWith("DECIMAL"))  return DTYPE_DECIMAL;
      if(type.startsWith("CHAR"))     return DTYPE_CHAR;
      if(type.startsWith("VARCHAR"))  return DTYPE_VCHAR;
      if(type.startsWith("DATE"))     return DTYPE_DATE;
      if(type.startsWith("DATETIME")) return DTYPE_DTIME;
      if(type.startsWith("INTERVAL")) return DTYPE_INTERVAL;
      if(type == "SERIAL")            return DTYPE_SERIAL;
      if(type == "SMALLINT")          return DTYPE_SMINT;
      if(type == "INTEGER")           return DTYPE_INT;
      if(type == "FLOAT")             return DTYPE_SERIAL;
      if(type == "SMALLFLOAT")        return DTYPE_SERIAL;
      if(type == "MONEY")             return DTYPE_MONEY;

      return DTYPE_CHAR;
   }

   QDate getDate(QString value)
   {
      QStringList arr_mdy;
      QString sep;
      if(value.contains("/"))
      {
         sep = "/";
      }
      if(value.contains("-"))
      {
         sep = "-";
      }
      if(value.contains("."))
      {
         sep = ".";
      }

      if(sep.isEmpty()){
         //TODO: error
      }

      arr_mdy = value.split(sep);

      if(arr_mdy.count() <= 0){
         // TODO: error
      }

      if (arr_mdy[0].length() == 1) arr_mdy[0] = "0" + arr_mdy[0];
      if (arr_mdy[1].length() == 1) arr_mdy[1] = "0" + arr_mdy[1];

      if(dbDateToFormat(env["DBDATE"]).contains("yyyy")){
         if (arr_mdy[2].length() == 2)
         {  
            bool ok = true;
            int year = arr_mdy[2].toInt(&ok);
            if (ok && year > 50)
            {
               arr_mdy[2] = "19" + arr_mdy[2];
            }
            else
            {
               arr_mdy[2] = "20" + arr_mdy[2];
            }
         }
      }
      if (arr_mdy.count() > 0)
      {
         value = arr_mdy[0] + sep + arr_mdy[1] + sep + arr_mdy[2];
      }

      return QDate::fromString(value,  dbDateToFormat(env["DBDATE"]));
   }

   QDate getDate(QString value, QString fmt)
   {
      fmt = fmt.replace("mmmm", "MMMM");
      fmt = fmt.replace("mmm", "MMM");
      fmt = fmt.replace("mm", "MM");
      return QDate::fromString(value,  fmt);
   }

   QString dbDateToFormat(QString dbdate){
      QString fmt;
      QString sep = "/"; 
      int cnt = 4;
      switch(dbdate.length()){
         case 5: // DMY4/
            sep = dbdate.mid(dbdate.length()-1, 1);
            dbdate.remove(dbdate.length()-1, 1);
            cnt = dbdate.mid(dbdate.length()-1, 1).toInt();
            dbdate.remove(dbdate.length()-1, 1);

            for(int i=0; i<dbdate.length(); i++){
               bool found = false;
               if(dbdate.at(i) == 'D'){
                  fmt += "dd";
                  found = true;
               }

               if(dbdate.at(i) == 'M'){
                  fmt += "MM";
                  found = true;
               }

               if(dbdate.at(i) == 'Y'){
                  for(int k=0; k<cnt; k++){
                     fmt += "y";
                  }
                  found = true;
               }

               if(found && i < dbdate.length()-1){
                  fmt += sep;
                  found = false;
               }
            }
            break;

         case 4: // DMY4
            cnt = dbdate.remove(dbdate.length()-1, 1).toInt();
            for(int i=0; i<dbdate.length(); i++){
               bool found = false;
               if(dbdate.at(i) == 'D'){
                  fmt += "dd";
                  found = true;
               }

               if(dbdate.at(i) == 'M'){
                  fmt += "MM";
                  found = true;
               }

               if(dbdate.at(i) == 'Y'){
                  for(int k=0; k<cnt; k++){
                     fmt += "y";
                  }
                  found = true;
               }

               if(found && i < dbdate.length()){
                  fmt += sep;
                  found = false;
               }
            }
            break;

         case 3: // DMY
            for(int i=0; i<dbdate.length(); i++){
               bool found = false;
               if(dbdate.at(i) == 'D'){
                  fmt += "dd";
                  found = true;
               }

               if(dbdate.at(i) == 'M'){
                  fmt += "MM";
                  found = true;
               }

               if(dbdate.at(i) == 'Y'){
                  for(int k=0; k<cnt; k++){
                     fmt += "y";
                  }
                  found = true;
               }

               if(found && i < dbdate.length()){
                  fmt += sep;
                  found = false;
               }
            }
            break;

         default:
            qWarning("Unhandled DBDATE Format");
            return "";
      } 
      return fmt;
   }

   bool isValidForType(DataType datatype, QString value, QString format)
   {
      if (value.isEmpty()) return true;
       
      switch (datatype)
      {

         case DTYPE_TEXT:
         case DTYPE_NULL:
         case DTYPE_BYTE:
         case DTYPE_VCHAR:
         case DTYPE_NCHAR:
         case DTYPE_CHAR:
            return true;


         case DTYPE_INTERVAL:
         case DTYPE_DTIME:
            return true;


         case DTYPE_DECIMAL:
         case DTYPE_FLOAT:
         case DTYPE_SMFLOAT:
         case DTYPE_MONEY:
            {
               bool ok;
               value.toDouble(&ok);
               if(ok)
               {
                  return true;
               }
               else
               {
                  return false;
               }
            }

           case DTYPE_DATE:
              {
                 QDate dt;
                 bool ok = false;
                 if (!format.isEmpty())
                 {
                    dt = getDate(value, format);
                    if(dt.isValid())
                       ok = true;
                 }
                 else
                 {
                    dt = getDate(value);
                    if(dt.isValid())
                       ok = true;
                 }

                 if (ok)
                 {
                    return true;
                 }
                 else
                 {
                    return false;
                 }
              }

           case DTYPE_SERIAL:
           case DTYPE_INT:
              {
                 bool ok;
                 qint32 n;
                 n = value.toInt(&ok);
                 if(ok && (value.toInt() == n)){
                    return true;
                 }
                 else{
                    return false;
                 }
              }

           case DTYPE_SERIAL8:
           case DTYPE_INT8:
              {
                 bool ok;
                 qint64 n;
                 n = value.toInt(&ok);
                 if(ok && (value.toInt() == n)){
                    return true;
                 }
                 else{
                    return false;
                 }
              }

           case DTYPE_SMINT:
              {
                 bool ok;
                 qint16 n;
                 n = value.toInt(&ok);
                 if(ok && (value.toInt() == n)){
                    return true;
                 }
                 else{
                    return false;
                 }
              }

           default:
             qFatal("Datatype field checking not handled");
             return false;
      }
   }

   QString stringToKey(QString s)
   {
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
            if(s.toLower() == "enter")
               return QString::number(2016);
            if(s.toLower() == "esc")
               return QString::number(27);
            if(s.toLower() == "escape")
               return QString::number(27);
            if(s.toLower() == "return")
               return QString::number(13);

/*
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
*/
         }
   
         return s;
      };

   QString keyToString(QString s)
   {

      bool ok = false;
      int key = s.toInt(&ok);
      if(!ok)
         return s;

      if(key > 2999){
          return QString("f%1").arg(key-2999);
      }

      if(key == 2000)
         return "up";

      if(key == 2001)
         return "down";

      if(key == 2002)
         return "left";

      if(key == 2003)
         return "right";

      if(key == 2006)
         return "prevpage";

      if(key == 2008)
         return "help";

      if(key == 2016)
         return "accept";

      if(key == 27)
         return "escape";

      if(key == 13)
         return "return";

         return s;
      };

}
