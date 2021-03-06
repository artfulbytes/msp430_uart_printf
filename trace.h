#ifndef TRACE_H
#define TRACE_H

#include <stdarg.h>

#define TRACE_INFO(fmt, ...) trace("INFO: %s: " fmt "\n", __FUNCTION__, ##__VA_ARGS__)
#define TRACE_WARN(fmt, ...) trace("WARNING: %s: " fmt "\n", __FUNCTION__, ##__VA_ARGS__)

/* This should be used for printing, because we really don't want to
 * include stdio.h functions when build for the MCU, adds ~5 kB and ROM is
 * only 16 kB on MSP430G2553. */

/* You can read the traces from the MCU by hooking up the USB to the Launchpad
 * (make sure you rotate the RXD/TXD bridges 90 degrees), and if you are on Linux,
 * you can then connect with your favorite terminal emulation program
 * (e.g. picocom -b 9600 /dev/ttyACM1). */
void trace(const char *format, ...);

#endif /* TRACE_H */
