/**
 * @file
 * The implementation of the FglNode class
 */

#include "FglNode.h"

FglNode::FglNode(int line,int column) 
{
  startLine = line;
	startColumn = column;
}

void FglNode::setStartLine(int line) 
{
  startLine = line;
}

int FglNode::getStartLine(void)
{
  return startLine;
}

