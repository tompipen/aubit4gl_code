
/**
 * @file
 * A node of a 4gl abstract syntax tree.
 * Defines things that are comon to all nodes like:
 *   starting line number
 *   starting column
 *   finish line number
 *   finish column
 */
#ifndef FGL_NODE_H
#define FGL_NODE_H

class FglNode {
  private:
		int startLine;
		int endLine;
		int startColumn;
		int endColumn;
	public:
		FglNode() {};
		FglNode(int line,int column);
		void setStartLine(int line);
		int getStartLine(void);
};

#endif
