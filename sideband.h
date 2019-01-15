#ifndef SIDEBAND_H
#define SIDEBAND_H

#define SIDEBAND_PROTOCOL_ERROR -2
#define SIDEBAND_REMOTE_ERROR -1
#define SIDEBAND_FLUSH 0
#define SIDEBAND_PRIMARY 1
#define SIDEBAND_PROGRESS 2

/*
 * Inspects a multiplexed packet read from the remote and returns which
 * sideband it is for.
 *
 * If SIDEBAND_PROTOCOL_ERROR, SIDEBAND_REMOTE_ERROR, or SIDEBAND_PROGRESS,
 * also prints a message (or the formatted contents of the notice in the case
 * of SIDEBAND_PROGRESS) to stderr.
 */
int demultiplex_sideband(const char *me, char *buf, int len, int die_on_error);

void send_sideband(int fd, int band, const char *data, ssize_t sz, int packet_max);

#endif
