# ----------------------------------------------------------------------
# Adapt the installation directories to your local standards.
# ----------------------------------------------------------------------

# This is where the wicotorenuei executable will go.

DESTBIN = /usr/bin

# Select your favorite compiler.
CC = /usr/bin/g++

# This assumes the BSD install.
INSTALL = install -c

# ----------------------------------------------------------------------
# Files.
# ----------------------------------------------------------------------

SRCS = with-colo-to-receive-nur-einmal.cc
OBJS = with-colo-to-receive-nur-einmal.o
PROG = wicotorenuei

CLEANUP = $(PROG) $(OBJS)

# ----------------------------------------------------------------------
# Rules for installation.
# ----------------------------------------------------------------------

STRIP = -s

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

install: $(PROG)
	$(INSTALL) $(STRIP) $(PROG) $(DESTDIR)$(DESTBIN)

clean:
	rm -f $(CLEANUP)
