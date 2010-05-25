#include <include/fgl.h>
#include <QStringList>
#include <QDebug>

namespace Fgl {
   QHash<QString, QString> env;

   QString usingFunc(QString fmt, QString value, DataType dataType)
   {
      if(value.isEmpty())
         return value;

      switch(dataType){
         case DTYPE_DECIMAL:
         case DTYPE_MONEY:
            {
            bool isneg = false;
            QByteArray p = value.toAscii();
            for (int a = 0; a < p.size(); a++)
            {
               if (p[a] >= '0' && p[a] <= '9') continue;
               if (p[a] == '.') { p[a] = '.'; continue; }
               if (p[a] == '-') { p[a] = ' '; isneg = true; continue; }
               p[a] = ' ';
            }

            return fgl_using_string(fmt, value, isneg);

            
            }
            break;
         case DTYPE_BYTE:
         case DTYPE_SMINT:
         case DTYPE_INT:
         case DTYPE_SERIAL:
         case DTYPE_SMFLOAT:
         case DTYPE_FLOAT:
            return fgl_using(fmt, value);
            break;

         case DTYPE_DATE:
            return fgl_using_date(fmt, value);
            break;
         case DTYPE_CHAR:
         case DTYPE_NULL:
         case DTYPE_DTIME:
         case DTYPE_TEXT:
         case DTYPE_VCHAR:
         case DTYPE_INTERVAL:
         case DTYPE_NCHAR:
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
      return value;
   }

   QString fgl_using(QString fmt, QString value)
   {
      Q_UNUSED(fmt);
      Q_UNUSED(value);

      bool isNeg = false;
      bool ok = false;
      qreal dec = value.toDouble(&ok);

      if(ok){
         if(dec < 0)
            isNeg = true;
      }

      return fgl_using_string(fmt, value, isNeg);
   }

   QString fgl_using_date(QString fmt, QString value)
   {
      QDate d = getDate(value);
      fmt = fmt.replace("mmmm", "MMMM");
      fmt = fmt.replace("mmm", "MMM");
      fmt = fmt.replace("mm", "MM");
      value = d.toString(fmt);

      return value;
   }

   QString fgl_using_string(QString fmt, QString value, bool isneg)
   {
      Q_UNUSED(fmt);
      Q_UNUSED(value);
      Q_UNUSED(isneg);

      QString overflow;
      bool hasMoney = false;
      QList<QChar> canFloatHead;
      canFloatHead << '*' << '-' << '+' << '(' << '$';
      QList<QChar> repDigit;
      repDigit << '*' << '&' << '#' << '<' << '-' << '+' << '(' << ')' << '$';
      int def = 30;

      int lb, cb = 0;

      int s;

      s = fmt.length();

      overflow.fill('*', s);


      for(int a=0; a<s; a++){
         if(fmt.at(a) == '(')
            lb++;
         if(fmt.at(a) == ')')
            cb++;
      }

      if(lb > 1 && cb > 1){
         //TODO: ERROR
      }

      if(lb > 0 && cb > 0){
         QString buff = fmt.mid(fmt.indexOf("(")+1);
         int eob = buff.indexOf(")");
         if(eob == -1){
            return QString("");
         }
         buff = buff.mid(0, eob-1);
         for(int a=0; a<buff.length(); a++){
            if(lb == 1 && cb == 1){
               if(buff.at(a) == '(')
                  buff[a] = '#';
               if(buff.at(a) == ')')
                  buff[a] = '#';
            }

            if(lb > 1 && cb == 1){
               if(buff.at(a) == '(')
                  buff[a] = '#';
            }

            if(lb == 1 && cb > 1){
               if(buff.at(a) == ')')
                  buff[a] = '#';
            }
         }

         QString res = fgl_using_string(buff, value, false);
         QString fmtOrig = fmt;
         fmt = fmt.mid(0, fmt.indexOf('(')+1);
         fmt += res;
         fmt += fmtOrig.mid(eob+1);

         if(!isneg){
            if(fmt.indexOf('(') >= 0 && fmt.indexOf(')') >= 0){
               buff = fmt.replace('(', ' ');
               fmt = fmt.replace(')', ' ');
            }
            else{
               if(lb > 1){
                  for(int a=0; a<fmt.length()-1; a++){
                     if(fmt.at(a) == '(' && fmt.at(a+1) == ' '){
                        fmt[a] = ' ';
                        fmt[a+1] = '(';
                     }
                  }
               }

               if(cb > 1){
                  for(int a=0; a<fmt.length()-1; a++){
                     if(fmt.at(a) == ' ' && fmt.at(a+1) == ')'){
                        fmt[a] = ')';
                        fmt[a+1] = ' ';
                     }
                  }
               }
            }
         }

         return fmt;
      }

      bool ok = false;

      value.toDouble(&ok);

      if(!ok)
         return "";

      int num_places = 0;
      QString fm1;
      QString fm2;
      QString lbuff;

      if (fmt.indexOf('.') >= 0){
         QString lbuff;
         int pos_dot;
         pos_dot = fmt.indexOf('.');
         lbuff = fmt.mid(pos_dot + 1);
         fm1 = fmt.mid(0, pos_dot);
         lbuff.trimmed();
         num_places = lbuff.length();
         fm2 = lbuff;
      }
      else
      {
         fm1 = fmt;
         fm2 = "";
         num_places = 0;
      }

      //TODO: find a better way
      QString qs_buffInteger;
      QString qs_buffDecimal;

      bool decFound = false;
      for(int i=0; i<value.length(); i++){
         if(value.at(i) == '.'){
            decFound = true;
            continue;
         }

         if(!decFound){
            qs_buffInteger += value.at(i);
         }
         else{
            qs_buffDecimal += value.at(i);
         }
      }

      qs_buffInteger = qs_buffInteger.rightJustified(31);

      if(num_places > 64 || qs_buffDecimal.length() >= 64){
         return overflow;
      }

      qs_buffDecimal.append("000000000000000000000000000000000");
      qs_buffDecimal.mid(0,32);

      QString qs_str = fmt;
      bool isprnt = true;

      int f_cnt = 0;
      int d_cnt = 0;
      int n_cnt = 0;

      if(isneg){
         n_cnt = 1;
      }
      else{
         n_cnt = 0;
      }

      if(isneg){
         if(fmt.contains('(') || fmt.contains(')') || fmt.contains('+') || fmt.contains('-')){
         }
         else{
            n_cnt = 0;
         }
      }
      else{
         if(fmt.contains('(') || fmt.contains(')') || fmt.contains('+') || fmt.contains('-')){
            n_cnt = 1;
         }
      }

      decFound = false;
      for(int i=0; i<fmt.length(); i++){
         if(fmt.at(i) == '.'){
            decFound = true;
            continue;
         }

         if(!decFound){
            if(repDigit.contains(fmt.at(i)))
               f_cnt++;
         }
         else{
            if(repDigit.contains(fmt.at(i)))
               d_cnt++;
         }
      }

      for (int a = def; (a > 0 && qs_buffInteger.at(a) != ' '); a--)
         n_cnt++;


      if(fmt.contains('$')){
         hasMoney = true;
      }
      else{
         hasMoney = false;
      }

      if(f_cnt < n_cnt + (hasMoney?1:0)){
         int a = fmt.length();
         if(a > s){
            a = s;
         }

         if(n_cnt > a)
         {
            return overflow;
         }

         return overflow;
      }


      for(int a = fm1.length()-1; a >= 0; a--){
         if(repDigit.contains(fm1.at(a))){
            if(def >= 0){
               if(((qs_buffInteger.at(def) == '0' && qs_buffInteger.at(def) == ' ') || qs_buffInteger[def] == ' ' ) && isprnt)
               {
                  isprnt = false;
               }
            }
            qs_str[a] = qs_buffInteger.at(def--);
            if(!isprnt){
               if(fm1.at(a) == '#'){
                  qs_str[a] = ' ';
                  continue;
               }

               if(fm1.at(a) == '*'){
                  qs_str[a] = '*';
                  continue;
               }

               if(fm1.at(a) == '&'){
                  qs_str[a] = '0';
                  continue;
               }

               if(fm1.at(a) == '<'){
                  qs_str[a] = '<';
                  continue;
               }

               int p = canFloatHead.indexOf(fm1.at(a));
               if(p >= 0){
                  //canFloatHead[p] = QChar(1);
                  if(fm1.at(a) == '+' && isneg){
                     qs_str[a] = '-';
                     continue;
                  }

                  if(fm1.at(a) == '+' && !isneg){
                     qs_str[a] = '+';
                     continue;
                  }

                  if(fm1.at(a) == '-' && isneg){
                     qs_str[a] = '-';
                     continue;
                  }

                  if(fm1.at(a) == '-' && !isneg){
                     qs_str[a] = ' ';
                     continue;
                  }

                  if(fm1.at(a) == '('){
                     if(isneg){
                        qs_str[a] = '(';
                        continue;
                     }
                     else{
                        qs_str[a] = ' ';
                        continue;
                     }
                  }
                  if(fm1.at(a) == ')' && isneg){
                     qs_str[a] = ')';
                     continue;
                  }
                  qs_str[a] = fm1.at(a);
                  continue;
               }
               else{
                  qs_str[a] = ' ';
                  continue;
               }
            }
         }
         else{
            if(qs_buffInteger.at(def) == ' ' && qs_str.at(a) == ','){
               if(fm1.at(a+1) == '<'){
                  qs_str[a] = '<';
               }
               else{
                  qs_str[a] = QChar((char)0x01);
               }
            }
         }
      }
      def = 0;

      for(int a = 0; a < fm2.length(); a++){
         if(repDigit.contains(fm2.at(a))){
            if(fm2.at(a) == ')'){
               if(isneg){
                  qs_str[a+fm1.length()+1] = ')';
               }
               else{
                  qs_str[a+fm1.length()+1] = ' ';
               }
            }
            qs_str[a+fm1.length()+1] = qs_buffDecimal.at(def++);
         }
         else{
            qs_str[a+fm1.length()+1] = fm2.at(a);
         }
      }

      if(qs_str.contains("<")){
         QString buffx;
         def = 0;
         for(int a =0; a < qs_str.length(); a++){
            if(qs_str.at(a) == '<'){
               if(qs_str.at(a+1) == ','){
                  qs_str[a+1] = '<';
               }
               continue;
            }
            if(!isneg && qs_str.at(a) == '-' && qs_str.at(a+1) == '<'){
               continue;
            }
            buffx += qs_str.at(a);
         }

         qs_str = buffx;
      }

      for(int a=0; a < qs_str.length(); a++){
         if(qs_str.at(a) == QChar((char)0x01)){
            if(a == 0){
               qs_str[a] = ' ';
            }
            else{
               qs_str[a] = qs_str.at(a-1);
            }
            if(a == 1){
               if(qs_str.at(a-1) == '$'){
                   qs_str[a-1] = ' ';
               }
               if(qs_str.at(a-1) == '-'){
                   qs_str[a-1] = ' ';
               }
               if(qs_str.at(a-1) == '('){
                   qs_str[a-1] = ' ';
               }
            }
            if(a >= 2){
               if(qs_str.at(a-1) == '$' && qs_str.at(a-2) != '$'){
                   qs_str[a-1] = ' ';
               }
               if(qs_str.at(a-1) == '-' && qs_str.at(a-2) != '-'){
                   qs_str[a-1] = ' ';
               }
               if(qs_str.at(a-1) == '(' && qs_str.at(a-2) != '('){
                   qs_str[a-1] = ' ';
               }
            }
         }
      }

      QString prefix;
      QChar dec;
      QString suffix;
      const QString DBMONEY = env["DBMONEY"];
      decFound = false;
      for(int i=0;i<DBMONEY.size(); i++){
         if(DBMONEY.at(i) == QChar('.') || DBMONEY.at(i) == QChar(',')){
            decFound = true;
            dec = DBMONEY.at(i);
            continue;
         }

         if(!decFound){
            prefix += DBMONEY.at(i);
         }
         else{
            suffix += DBMONEY.at(i);
         }
      }

      for(int a=qs_str.length()-1; a>=0; a--){
         if(qs_str.at(a) == '.'){
            qs_str[a] = dec;
         }
      }

      if(hasMoney && !qs_str.contains('$')){
         int firstNonSpace = -1;
         for(int a = 0; a>qs_str.length(); a++){
            if(qs_str.at(a) != ' '){
               firstNonSpace = a;
            }
         }
         if(firstNonSpace > 0){
            if(qs_str.at(firstNonSpace) == '-' || qs_str.at(firstNonSpace) == '(' || qs_str.at(firstNonSpace) == '+'){
               qs_str[firstNonSpace-1] = qs_str.at(firstNonSpace);
               qs_str[firstNonSpace] = '$';
            }
            else{
               qs_str[firstNonSpace-1] = '$';
            }
         }
      }
      
      return qs_str;
   }

   QString fgl_convert_money(QString value){

      QString prefix;
      QChar dec;
      QString suffix;
      const QString DBMONEY = env["DBMONEY"];
      bool decFound = false;

      for(int i=0;i<DBMONEY.size(); i++){
         if(DBMONEY.at(i) == QChar('.') || DBMONEY.at(i) == QChar(',')){
            decFound = true;
            dec = DBMONEY.at(i);
            continue;
         }

         if(!decFound){
            prefix += DBMONEY.at(i);
         }
         else{
            suffix += DBMONEY.at(i);
         }
      }

      for(int a=value.length()-1; a>=0; a--){
         if(value.at(a) == '.'){
            value[a] = dec;
         }
      }
      return value;
   }
/*
      QString prefix;
      QChar dec;
      QString suffix;
      const QString DBMONEY = env["DBMONEY"];
      bool decFound = false;
      QString new_value = value;

      for(int i=0;i<DBMONEY.size(); i++){
         if(DBMONEY.at(i) == QChar('.') || DBMONEY.at(i) == QChar(',')){
            decFound = true;
            dec = DBMONEY.at(i);
            continue;
         }

         if(!decFound){
            prefix += DBMONEY.at(i);
         }
         else{
            suffix += DBMONEY.at(i);
         }
      }

      for(int i=0; i<new_value.size(); i++){
          if(new_value.at(i) == QChar('.'))
             new_value.replace(i, dec);
      }

      value = new_value;

      return value;
   }
*/

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
             //qFatal("Datatype field checking not handled");
             return false;
      }
   }

   QString stringToKey(QString s)
   {
      if(s.toLower().startsWith("f")){
            QString s2 = s;
            s2.remove(0,1);
            bool ok = false;
            int key = s2.toInt(&ok);
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

      if(key < 126 && QChar(key).isPrint()){
         return QString(QChar(key));
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
