
#include <string.h>
#include <stdlib.h>
#include "FglToken.h"

FglToken::FglToken(int line,char *_tokenText) {
	setStartLine(line);
	tokenText = strdup(_tokenText);
}

char *FglToken::getText(void) {
  return tokenText;
}

FglToken::~FglToken() {
  free(tokenText);
}

