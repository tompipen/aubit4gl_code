/**
 * @file
 *
 * An fgl statement interface
 */
class FglStatement {
public:
  virtual ~FglStatement () {}

  //  It's necessary because we need to clone objects without
  // knowing the exact type.
  virtual FglStatement *clone () = 0;

  // 
};
