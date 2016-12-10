#ifndef GDBSTUB_H
#define GDBSTUB_H

#ifdef __cplusplus
extern "C" {
#endif

void gdbstub_init();

#ifdef __cplusplus
}
#endif

#define RAMFUNC __attribute__ ((section( ".entry.text")))

#endif
