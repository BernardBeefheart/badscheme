#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x_64Bits-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/bs-errors.o \
	${OBJECTDIR}/src/bsfiles-utils.o \
	${OBJECTDIR}/src/bslist.o \
	${OBJECTDIR}/src/bsprogramm.o \
	${OBJECTDIR}/src/interp.o \
	${OBJECTDIR}/src/load_file.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/version.o


# C Compiler Flags
CFLAGS=-Wall -Wextra -pedantic

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/badscheme.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/badscheme.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/badscheme ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/bs-errors.o: src/bs-errors.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/bs-errors.o src/bs-errors.c

${OBJECTDIR}/src/bsfiles-utils.o: src/bsfiles-utils.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/bsfiles-utils.o src/bsfiles-utils.c

${OBJECTDIR}/src/bslist.o: src/bslist.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/bslist.o src/bslist.c

${OBJECTDIR}/src/bsprogramm.o: src/bsprogramm.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/bsprogramm.o src/bsprogramm.c

${OBJECTDIR}/src/interp.o: src/interp.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/interp.o src/interp.c

${OBJECTDIR}/src/load_file.o: src/load_file.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/load_file.o src/load_file.c

${OBJECTDIR}/src/main.o: src/main.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.c

${OBJECTDIR}/src/version.o: src/version.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Wall -Iinclude -std=c11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/version.o src/version.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/badscheme.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
