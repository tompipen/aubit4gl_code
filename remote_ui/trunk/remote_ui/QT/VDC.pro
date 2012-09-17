CONFIG += ordered
TEMPLATE=subdirs

VREPGEN_PATH = $$(VREPGEN)

macx {
   DEFINES += VREPGEN_USE
}

!isEmpty(VREPGEN_PATH) {
    DEFINES += VREPGEN_USE
    message("Setze VDC Makro")
    SUBDIRS += quazip vdc-app.pro
    vdc-app.pro.depends += \
        quazip
} else {
    SUBDIRS += vdc-app.pro
}

SUBDIRS += patcher.pro copybinaries.pro
patcher.pro.depends = quazip copybinaries.pro
