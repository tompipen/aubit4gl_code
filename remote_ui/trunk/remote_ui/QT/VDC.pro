CONFIG += ordered
TEMPLATE=subdirs
SUBDIRS=quazip vdc-app.pro

vdc-app.pro.depends = quazip
