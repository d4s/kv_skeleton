#include "config.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* HINT: __maybe__ easier to use FILE steam for communication, instead
 * of low-level descriptors, since the stream is based on strings.
 * i.e. popen()/fscanf()/fprintf()/fclose()
 * Needs API changing.
 **/

int
create_server_pipe()
{
	warning("stub");
	/* FIXME:
	 * - create pipe file object for read:
	 *   /tmp/server.pipe
	 * - open pipe
	 * - return descriptor
	 **/
	return STDIN_FILENO;
}

int
create_client_pipe(pid_t pid)
{
	warning("stub");
	/* FIXME:
	 * - create pipe file object based on PID of client for read:
	 *   /tmp/client.<PID>.fifo
	 * - open pipe
	 * - return descriptor
	 */
	return STDIN_FILENO;
}

static int
connect_pipe(char *path)
{
	warning("stub");
	/* FIXME:
	 * - open pipe by path for sending data
	 * - return descriptor
	 */
	return STDOUT_FILENO;
}

int
connect_to_server(void)
{
	int fd;
	warning("stub");
	fd = connect_pipe("/tmp/server.pipe");
	if (fd < 0) {
		error("unable to connect: %s", strerror(errno));
		return -1;
	}

	return fd;
}

int
connect_to_client(pid_t pid)
{
	/* FIXME: change path according PID */
	char path[] = "/tmp/client.<PID>.pipe";
	int fd;

	warning("stub");

	fd = connect_pipe(path);
	if (fd < 0) {
		error("unable to connect to %s: %s", path, strerror(errno));
		return FALSE;
	}

	return fd;
}

int
disconnect_pipe(int fd)
{
	warning("stub");
	/* FIXME:
	 * - close the pipe
	 */

	return TRUE;
}

int
destroy_pipe(int fd, pid_t pid)
{
	warning("stub");

	if (fd > 0)
		disconnect_pipe(fd);

	/* FIXME:
	 * - unlink pipe file object
	 */
	if (pid == 0) {
		/* unlink server pipe */
	} else {
		/* unlink client pipe by PID */
	}

	return TRUE;
}

int
send_msg(int fd, char *buf, size_t buf_len)
{
	int count;
	char data[MAX_STRING_LENGTH + 10] = {0};

	/* add PID prefix (10 bytes) to every message
	 * that allows to distinguish clients' messages
	 */
	sprintf(data, "%08d: ", getpid());
	memcpy(data + 10, buf, buf_len);

	count = write(fd, data, buf_len + 10);
	if (count < 0) {
		error("error on write");
		return FALSE;
	}

	if (count != (buf_len + 10)) {
		warning("written %d of %lu bytes", count, buf_len);
		return FALSE;
	}

	return TRUE;
}

int
recv_msg(int fd, char *buf, size_t buf_len)
{
	int count;

	/* FIXME: read from stdin */

	/* cleanup buffer */
	memset(buf, 0, buf_len);

	count = read(fd, buf, buf_len);
	if (count < 0) {
		error("error on read");
		return FALSE;
	}

	if (count == 0) {
		debug("EOF");
		return FALSE;
	}

	return TRUE;
}

void
init(void)
{
	debug("Library for communication loaded");
}

void
fini(void)
{
	debug("Library for communication unloaded");
}
