CONFIG += ordered
TEMPLATE=subdirs


VREPGEN_PATH = $$(VREPGEN)

!isEmpty(VREPGEN_PATH) {
SUBDIRS= quazip vdc-app.pro
vdc-app.pro.depends = quazip
} else {
SUBDIRS= vdc-app.pro
}
