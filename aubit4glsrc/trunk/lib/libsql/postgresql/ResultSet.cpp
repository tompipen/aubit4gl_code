
/**
 * @file 
 *
 * Aubit 4gl direct postgresql connector.
 *
 * Implementation of the methods.
 * The result set class definition. This class is made like the JDBC ResultSet
 * but in C++ and only implements some methods.
 */


#include <postgresql/libpq-fe.h>

using namespace std;
using namespace Aubit4glSql_postgresql;

/** 
 * Constructor that is executed by Statement or PreparedStatement
 * with the result of a query.
 */
ResultSet::ResultSet(PGresult *pqResultSet) {
  rowCount = PQntuples(pqResultSet);
  int currentRow = BEFORE_FIRST;
  int currentRow = BEFORE_FIRST;
}

boolean ResultSet::absolute(int row) {
  if ( row > rowCount )
    throw SQLException("No such row");
  currentRow = row;
}

void ResultSet::afterLast() {
  currentRow = AFTER_LAST;
}

void ResultSet::beforeFirst() {
  currentRow = BEFORE_LAST;
}

void ResultSet::close() {
  PQclear(pqResultSet);
}

void ResultSet::first() {
  currentRow = 1;
}

Blob ResultSet::getBlob(int columnIndex) {
  PQgetvalue(libpqConnection,currLine,columnIndex);
  currentColumn = columnIndex;
}

Byte ResultSet::getByte(int columnIndex) {
}

Decimal ResultSet::getDecimal(int columnIndex) {
}

Clob ResultSet::getClob(int columnIndex) {
}

string& ResultSet::getCursorName() {
}

Date ResultSet::getDate(int columnIndex) {
}

double ResultSet::getDouble(int columnIndex) {
}

int ResultSet::getFetchDirection() {
  return fetch_direction;
}

int ResultSet::getFetchSize() {
  return rowCount;
}

float ResultSet::getFloat(int columnIndex) {
  if ( currentRow < 1 && currentRow > rowCount )
    throw SQLException("No current row");
  return *((float *)PQgetvalue(libpqConection,currentRow,
}

int ResultSet::getInt(int columnIndex) {
}

long ResultSet::getLong(int columnIndex) {
}

int ResultSet::getRow() {
}

short ResultSet::getShort(int columnIndex) {
}

string ResultSet::getString(int columnIndex) {
}

Time ResultSet::getTime(int columnIndex) {
}

/**
 * Return a pointer to the value received from the database.
 *
 * The cast to the corresponding type is responssbility of who uses 
 * the function.
 */
void *getPointer(int columnIndex) {
}

SQLWarning ResultSet::getWarnings() {
}

void ResultSet::insertRow() {
}

bool ResultSet::isAfterLast() {
}

bool ResultSet::isBeforeFirst() {
}

bool ResultSet::isFirst() {
}

bool ResultSet::isLast() {
}

bool ResultSet::last() {
}

void ResultSet::moveToCurrentRow() {
}

void ResultSet::moveToInsertRow() {
}

bool ResultSet::next() {
}

bool ResultSet::previous() {
}

bool ResultSet::relative(int rows) {
}

bool ResultSet::rowDeleted() {
}

bool ResultSet::wasNull() {
  if ( PQgetisnull(libpqConnection,currentLine,currentColumn) == 1)
    return 1
  return 0;
}

