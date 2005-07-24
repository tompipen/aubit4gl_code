
// @todo : Remove this after cleaning more
#include "a4gl_4glc_int.h"
#include "KeyWord.h"
#include <ctype.h>

/**
 * A pointer to the generated global structure that contains the 
 * keyword table.
 */
extern struct s_kw *hashed_list[];

/**
 * Generate an Hash value to a string.
 *
 * This value is used to access to the keyword table.
 * The hash value is the order of the character in the alfabet.
 *
 * @param s The string to wich we generate the hash.
 * @return The hash number that correspond to the string.
 */
int KeyWord::getHashVal(const char *s)
{
  int c;
  c = toupper (s[0]);
  if (c >= 'A' && c <= 'Z')
  {
    c = c - 'A' + 1;
  }
  else
  {
    c = 0;
  }

  return c;
}

/**
 * Get a pointer to an array (zero terminated) of s_kw struct.
 *
 * @todo : Understand what is done if it does not find the keyword.
 *
 * @param keyWord The first keyword (since could be multiword) to get.
 * @return The array wanted.
 */
struct s_kw *KeyWord::getKwords(const char *keyWord) 
{
  struct s_kw *kwords;

  kwords = getKwords(getHashVal(keyWord));
	return kwords;
}

/**
 * Get a pointer to an array (zero terminated) of s_kw struct.
 *
 * @todo : Understand what is done if it does not find the keyword.
 *
 * @param hashKey The key of the hash where the keyword wanted resides.
 * @return The array wanted.
 */
struct s_kw *KeyWord::getKwords(int hashKey) 
{
  struct s_kw *kwords;

  kwords = hashed_list[hashKey];
	return kwords;
}
