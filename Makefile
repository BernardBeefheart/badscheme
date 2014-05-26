#
#  Main targets can be executed directly, and they are:
#
#     build                    build a specific configuration
#     clean                    remove built files from a configuration
#     clobber                  remove all built files
#     all                      build all configurations
#     help                     print help mesage
#
#		@todo : rewrite text above, comming from Netbeans Makefile
#

CC = gcc
LD = gcc

ODIR = objs


STD_WARNINGS = -Wall -Wextra -pedantic -std=gnu99
STD_INCLUDES = -Iinclude

_os = $(shell uname)
ifeq ($(OS), Windows_NT)
	_exe = .exe
else
	_exe =
endif

SOURCES = $(wildcard src/*.c)
_OBJS = $(patsubst %.c,%.o,$(notdir $(SOURCES)))
OBJS = $(addprefix $(ODIR)/, $(_OBJS))

EXE = badscheme$(_exe)

$(ODIR)/%.o: src/%.c
	$(CC) $(STD_INCLUDES) $(STD_WARNIGS) -c $< -o $@

all: _odir $(EXE)
	@echo "_os $(_os) OS $(OS) EXE $(EXE)"

clean:
	rm -fv $(OBJS) $(EXE)

_odir: $(ODIR)

$(ODIR):
	mkdir -p $@

$(EXE): $(OBJS)
	$(LD) $(OBJS) -o $@

.PHONY: _odir all clean
