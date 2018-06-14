###############################################################################
##                                                                           ##
##         Yocto-recipe to building shared-library for getting               ##
##             the Linux-process-ID of running processes                     ##
##                                                                           ##
##---------------------------------------------------------------------------##
## Author:   Ulrich Becker                                                   ##
## File:     process-id.bb                                                   ##
## Date:     14.06.2018                                                      ##
## Revision:                                                                 ##
###############################################################################

SUMMARY          = "Shared-library for getting Linux-process-ID of running processes"

SECTION          = "libs"
S                = "${WORKDIR}/git"
LICENSE          = "GPLv3"
LIC_FILES_CHKSUM = "file://${S}/LICENSE;md5=84dcc94da3adb52b53ae4fa38fe49e5d"
SRC_URI          = "git://github.com/UlrichBecker/get_linux_process_id.git;branch=master"
SRCREV           = "${AUTOREV}"
PV               = "1.0-git${SRCPV}"
PR               = "r0"

TARGET_CC_ARCH   += "${LDFLAGS}"

FILES_${PN}      += "${libdir}/lib*.so.*"
FILES_${PN}-dev  += "${libdir}/lib*.so"
FILES_${PN}-dev  += "${includedir}/*.h"

do_compile() {
   oe_runmake -C ${S}/src
}

do_install() {
   mkdir -p ${D}${includedir}
   mkdir -p ${D}${libdir}
   oe_runmake -C ${S}/src HEADDER_DIR=${D}${includedir} LIB_DIR=${D}${libdir} install
}

#=================================== EOF ======================================
