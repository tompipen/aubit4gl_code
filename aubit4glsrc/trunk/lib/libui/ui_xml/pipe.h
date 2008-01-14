#ifndef FPRINTF
#define FPRINTF fprintf
#endif

#ifndef SPRINTF
#define SPRINTF sprintf
#endif

int pipe_sock_gets (int sockfd, char *str, size_t count);
int pipe_sock_read (int sockfd, char *buf, size_t count);
int pipe_sock_write (int sockfd, char *buf, size_t count);
void pipe_flush (int sockfd);
int pipe_sock_puts (int sockfd, char *str);
int pipe_expect (int serversocket, char *s);
void suspend_flush(int a);
void set_envelope_mode(void); // Turn enveloping on
void timeout_flush(int sockfd) ;
void set_timeout_flush_sock(int sockfd);
