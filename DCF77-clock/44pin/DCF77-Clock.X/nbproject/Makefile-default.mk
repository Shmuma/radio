#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/XLCD/openxlcd.p1 ${OBJECTDIR}/XLCD/busyxlcd.p1 ${OBJECTDIR}/XLCD/putrxlcd.p1 ${OBJECTDIR}/XLCD/putsxlcd.p1 ${OBJECTDIR}/XLCD/readaddr.p1 ${OBJECTDIR}/XLCD/readdata.p1 ${OBJECTDIR}/XLCD/setcgram.p1 ${OBJECTDIR}/XLCD/setddram.p1 ${OBJECTDIR}/XLCD/wcmdxlcd.p1 ${OBJECTDIR}/XLCD/writdata.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/d10ktcyx.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/XLCD/openxlcd.p1.d ${OBJECTDIR}/XLCD/busyxlcd.p1.d ${OBJECTDIR}/XLCD/putrxlcd.p1.d ${OBJECTDIR}/XLCD/putsxlcd.p1.d ${OBJECTDIR}/XLCD/readaddr.p1.d ${OBJECTDIR}/XLCD/readdata.p1.d ${OBJECTDIR}/XLCD/setcgram.p1.d ${OBJECTDIR}/XLCD/setddram.p1.d ${OBJECTDIR}/XLCD/wcmdxlcd.p1.d ${OBJECTDIR}/XLCD/writdata.p1.d ${OBJECTDIR}/main.p1.d ${OBJECTDIR}/d10ktcyx.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/XLCD/openxlcd.p1 ${OBJECTDIR}/XLCD/busyxlcd.p1 ${OBJECTDIR}/XLCD/putrxlcd.p1 ${OBJECTDIR}/XLCD/putsxlcd.p1 ${OBJECTDIR}/XLCD/readaddr.p1 ${OBJECTDIR}/XLCD/readdata.p1 ${OBJECTDIR}/XLCD/setcgram.p1 ${OBJECTDIR}/XLCD/setddram.p1 ${OBJECTDIR}/XLCD/wcmdxlcd.p1 ${OBJECTDIR}/XLCD/writdata.p1 ${OBJECTDIR}/main.p1 ${OBJECTDIR}/d10ktcyx.p1


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F887
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/XLCD/openxlcd.p1: XLCD/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/openxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/openxlcd.p1  XLCD/openxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/openxlcd.d ${OBJECTDIR}/XLCD/openxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/openxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/busyxlcd.p1: XLCD/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/busyxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/busyxlcd.p1  XLCD/busyxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/busyxlcd.d ${OBJECTDIR}/XLCD/busyxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/busyxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/putrxlcd.p1: XLCD/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/putrxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/putrxlcd.p1  XLCD/putrxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/putrxlcd.d ${OBJECTDIR}/XLCD/putrxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/putrxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/putsxlcd.p1: XLCD/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/putsxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/putsxlcd.p1  XLCD/putsxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/putsxlcd.d ${OBJECTDIR}/XLCD/putsxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/putsxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/readaddr.p1: XLCD/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/readaddr.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/readaddr.p1  XLCD/readaddr.c 
	@-${MV} ${OBJECTDIR}/XLCD/readaddr.d ${OBJECTDIR}/XLCD/readaddr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/readaddr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/readdata.p1: XLCD/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/readdata.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/readdata.p1  XLCD/readdata.c 
	@-${MV} ${OBJECTDIR}/XLCD/readdata.d ${OBJECTDIR}/XLCD/readdata.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/readdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/setcgram.p1: XLCD/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/setcgram.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/setcgram.p1  XLCD/setcgram.c 
	@-${MV} ${OBJECTDIR}/XLCD/setcgram.d ${OBJECTDIR}/XLCD/setcgram.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/setcgram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/setddram.p1: XLCD/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/setddram.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/setddram.p1  XLCD/setddram.c 
	@-${MV} ${OBJECTDIR}/XLCD/setddram.d ${OBJECTDIR}/XLCD/setddram.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/setddram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/wcmdxlcd.p1: XLCD/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/wcmdxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/wcmdxlcd.p1  XLCD/wcmdxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/wcmdxlcd.d ${OBJECTDIR}/XLCD/wcmdxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/wcmdxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/writdata.p1: XLCD/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/writdata.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/writdata.p1  XLCD/writdata.c 
	@-${MV} ${OBJECTDIR}/XLCD/writdata.d ${OBJECTDIR}/XLCD/writdata.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/writdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/d10ktcyx.p1: d10ktcyx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/d10ktcyx.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/d10ktcyx.p1  d10ktcyx.c 
	@-${MV} ${OBJECTDIR}/d10ktcyx.d ${OBJECTDIR}/d10ktcyx.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/d10ktcyx.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/XLCD/openxlcd.p1: XLCD/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/openxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/openxlcd.p1  XLCD/openxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/openxlcd.d ${OBJECTDIR}/XLCD/openxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/openxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/busyxlcd.p1: XLCD/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/busyxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/busyxlcd.p1  XLCD/busyxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/busyxlcd.d ${OBJECTDIR}/XLCD/busyxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/busyxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/putrxlcd.p1: XLCD/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/putrxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/putrxlcd.p1  XLCD/putrxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/putrxlcd.d ${OBJECTDIR}/XLCD/putrxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/putrxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/putsxlcd.p1: XLCD/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/putsxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/putsxlcd.p1  XLCD/putsxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/putsxlcd.d ${OBJECTDIR}/XLCD/putsxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/putsxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/readaddr.p1: XLCD/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/readaddr.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/readaddr.p1  XLCD/readaddr.c 
	@-${MV} ${OBJECTDIR}/XLCD/readaddr.d ${OBJECTDIR}/XLCD/readaddr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/readaddr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/readdata.p1: XLCD/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/readdata.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/readdata.p1  XLCD/readdata.c 
	@-${MV} ${OBJECTDIR}/XLCD/readdata.d ${OBJECTDIR}/XLCD/readdata.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/readdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/setcgram.p1: XLCD/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/setcgram.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/setcgram.p1  XLCD/setcgram.c 
	@-${MV} ${OBJECTDIR}/XLCD/setcgram.d ${OBJECTDIR}/XLCD/setcgram.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/setcgram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/setddram.p1: XLCD/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/setddram.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/setddram.p1  XLCD/setddram.c 
	@-${MV} ${OBJECTDIR}/XLCD/setddram.d ${OBJECTDIR}/XLCD/setddram.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/setddram.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/wcmdxlcd.p1: XLCD/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/wcmdxlcd.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/wcmdxlcd.p1  XLCD/wcmdxlcd.c 
	@-${MV} ${OBJECTDIR}/XLCD/wcmdxlcd.d ${OBJECTDIR}/XLCD/wcmdxlcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/wcmdxlcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/XLCD/writdata.p1: XLCD/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/XLCD 
	@${RM} ${OBJECTDIR}/XLCD/writdata.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/XLCD/writdata.p1  XLCD/writdata.c 
	@-${MV} ${OBJECTDIR}/XLCD/writdata.d ${OBJECTDIR}/XLCD/writdata.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/XLCD/writdata.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/main.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/d10ktcyx.p1: d10ktcyx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/d10ktcyx.p1.d 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G --asmlist  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"  -o${OBJECTDIR}/d10ktcyx.p1  d10ktcyx.c 
	@-${MV} ${OBJECTDIR}/d10ktcyx.d ${OBJECTDIR}/d10ktcyx.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/d10ktcyx.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G --asmlist -mdist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit2  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"   -odist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G --asmlist -mdist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.map  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --addrqual=ignore --mode=free -P -N255 -I"E:/DCF77-Clock.X" --warn=0 --summary=default,-psect,-class,+mem,-hex,-file --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib "--errformat=%%f:%%l: error: %%s" "--warnformat=%%f:%%l: warning: %%s" "--msgformat=%%f:%%l: advisory: %%s"   -odist/${CND_CONF}/${IMAGE_TYPE}/DCF77-Clock.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
