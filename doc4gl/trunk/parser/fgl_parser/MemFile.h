
#ifndef MEMFILE_H
#define  MEMFILE_H

class MemFile {
	private:
    int opened; //< To indicate that the file is opened

    /** The buffer where the file is loaded to */
    char *buff;

    /** Length of the buffer where the file was readed to */
    long buff_len;
    
    /** The FILE structure where the file is opened */
    FILE *in;
    
    /** The current position in the buffer */
    long pos;


  public :
		~MemFile();
		MemFile();
    int fopen (const char *f);
    int fseek (long offset, int whence);
    int getchar(void);
    void fclose (void);
    void rewind (void);
    long ftell (void);
    int ungetchar(int c);
    int feof (void);
    int getLength(void);
};

#endif
