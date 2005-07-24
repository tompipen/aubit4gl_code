
%{

/** 
 * @file
 * Lexer for reading the keywords correspondence file
 * The goal is to make a generator of the necessary code that the lexer
 * use to serve the parser with.
 * 
 * This way the reserved words (even with multi word reserved words)
 * are keeped in a separeted very simple file without the need 
 * to change complicated C code.
 *
 * All the words are loaded in to a C++ template created for this purpose.
 * 
 * @todo : Implement it.
 */

%%

%%
