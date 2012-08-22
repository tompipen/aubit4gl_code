CONFIG += ordered
TEMPLATE=subdirs


VREPGEN_PATH = $$(VREPGEN)

macx {
   DEFINES += VREPGEN_USE
}

SUBDIRS += breakpad

!isEmpty(VREPGEN_PATH) {
    DEFINES += VREPGEN_USE
    message("Setze VDC Makro")
    SUBDIRS += quazip vdc-app.pro
    vdc-app.pro.depends += \
        quazip \
        breakpad
} else {
    SUBDIRS += vdc-app.pro
    unix {
        !macx {
            vdc-app.pro.depends += \
            breakpad
        }
    }
}
#SUBDIRS += createVersionsXml
