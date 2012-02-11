# Project: QTestToHTML
# Author:  Maximilian Seidel
# File:    QTestToHtml.pro
# 2012
# This file may be used under the terms of the GNU General Public
# License version 2.0 as published by the Free Software Foundation
# (http://www.gnu.org/licenses/gpl-2.0.html)
#
# This file is provided AS IT IS with NO WARRANTY OF ANY KIND, INCLUDING THE
# WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
# Enjoy using it!
#
#------------------------------------------------------------------------------



#-------------------------------------------------
#
# Project created by QtCreator 2012-02-11T11:42:54
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = QTestToHtml
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app


SOURCES += main.cpp \
    loghandler.cpp

HEADERS += \
    loghandler.h
