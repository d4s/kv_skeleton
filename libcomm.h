/* Basic communication API */
#ifndef libcomm
#define libcomm

#include <unistd.h>

extern int
create_server_pipe();

extern int
create_client_pipe(pid_t pid);

extern int
connect_to_server(void);

extern int
connect_to_client(pid_t pid);

extern int
disconnect_pipe(int fd);

extern int
destroy_pipe(int fd, pid_t pid);

extern int
send_msg(int fd, char *buf, size_t buf_len);

extern int
recv_msg(int fd, char *buf, size_t buf_len);

#endif
