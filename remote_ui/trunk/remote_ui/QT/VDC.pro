CONFIG += ordered
TEMPLATE=subdirs

cache()

VREPGEN_PATH = $$(VREPGEN)

macx {
   DEFINES += VREPGEN_USE
}

!isEmpty(VREPGEN_PATH) {
    DEFINES += VREPGEN_USE
    message("Setze VDC Makro")
    SUBDIRS += quazip vdc-app.pro patcher.pro copybinaries.pro
    vdc-app.pro.depends += \
        quazip
patcher.pro.depends = quazip copybinaries.pro
} else {
    SUBDIRS += vdc-app.pro
}

