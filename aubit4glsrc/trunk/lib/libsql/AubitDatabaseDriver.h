/**
 * Represent a database driver / connector loaded (normaly is an .so or .dll
 *
 * It could exist severall instances in order to have connections to diferent
 * databases.
 */
namespace Aubit4glSql {
  class Driver {
    private:
      /** Pointer to the handler of the dll (.so) loaded */
      void *dllHandler;
  
      /** Used to generate the statement names */
      int statementCount;
    
    public:
      void incrementStatement();
      char *getStatementName();
  };
}

