#
#  Main targets can be executed directly, and they are:
#
#     build                    build a specific configuration
#     clean                    remove built files from a configuration
#     clobber                  remove all built files
#     all                      build all configurations
#     help                     print help mesage
#

CC = gcc
LD = gcc

ODIR = objs

SOURCES = $(wildcard src/*.c)

STD_WARNINGS = -Wall -Wextra -pedantic  -std=gnu99
STD_INCLUDES = -Iinclude

_OBJS = $(patsubst %.c,%.o,$(notdir $(SOURCES)))
OBJS = $(addprefix $(ODIR)/, $(_OBJS))

EXE = badscheme.exe

$(ODIR)/%.o: src/%.c
	$(CC) $(STD_INCLUDES) $(STD_WARNIGS) -c $< -o $@

all: _odir $(EXE)

clean:
	rm -fv $(OBJS) $(EXE)

_odir: $(ODIR)

$(ODIR):
	mkdir -p $@

$(EXE): $(OBJS)
	$(LD) $(OBJS) -o $@

.PHONY: _odir all clean