package main

/*
#cgo CFLAGS: -Dbool=char -DHAS_BOOL -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -I/usr/lib64/perl5/CORE
#cgo LDFLAGS: -lm -lperl
#include <stdlib.h>

extern void *allocArgv (int argc);
extern void printArgs (int argc, char **argv);
extern int perlThings (int argc, char **argv, char **env);
*/
import "C"
import (
	"os"
	"unsafe"
)

func main() {
	argv := os.Args
	argc := C.int(len(argv))
	argvC := (*[0xfff]*C.char)(C.allocArgv(argc))
	defer C.free(unsafe.Pointer(argvC))
	for i, arg := range argv {
		argvC[i] = C.CString(arg)
		defer C.free(unsafe.Pointer(argvC[i]))
	}

	C.perlThings(argc, (**C.char)(unsafe.Pointer(argvC)), nil)
}
