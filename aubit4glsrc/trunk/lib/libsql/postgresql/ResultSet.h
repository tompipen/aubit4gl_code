/**
 * @file 
 *
 * Aubit 4gl direct postgresql connector.
 *
 * The result set class definition. This class is made like the JDBC ResultSet
 * but in C++ and only implements some methods.
 */

#ifndef RESULTSET_INCL
#define RESULTSET_INCL

#include <string>
#include <map>

#include "pgsql/libpq++.h"

using namespace std;

namespace Aubit4glSql_postgresql
{

  class ResultSet
  {
  private:
    PGresult * pqResultSet;
    int rowCount;
    int currentRow;
    int currentColumn;
    short fetch_direction;
  public:
      //andrej boolean absolute (int row);
      bool absolute (int row);
    void afterLast ();
    void beforeFirst ();
    void close ();
    void first ();

    // @todo : I just need getPointer function.
//andrej    Blob getBlob (int columnIndex);
//andrej    Byte getByte (int columnIndex);
//andrej    Decimal getDecimal (int columnIndex);
//andrej    Clob getClob (int columnIndex);
      string & getCursorName ();
//andrej    Date getDate (int columnIndex);
    double getDouble (int columnIndex);
    int getFetchDirection ();
    int getFetchSize ();
    float getFloat (int columnIndex);
    int getInt (int columnIndex);
    long getLong (int columnIndex);
    int getRow ();
    short getShort (int columnIndex);
    string getString (int columnIndex);
//andrej    Time getTime (int columnIndex);
//andrej    SQLWarning getWarnings ();
    void insertRow ();
    bool isAfterLast ();
    bool isBeforeFirst ();
    bool isFirst ();
    bool isLast ();
    bool last ();
    void moveToCurrentRow ();
    void moveToInsertRow ();
    bool next ();
    bool previous ();
    bool relative (int rows);
    bool rowDeleted ();
    bool wasNull ();
  };
}
#endif
