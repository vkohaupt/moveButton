QT += widgets

HEADERS = dialog.h

SOURCES = dialog.cpp \
          main.cpp

FORMS += dialog.ui

RESOURCES += spezialCheckBox/spezialCheckBox.qrc

include(moveButton/movebutton.pri)
include(spezialCheckBox/spezialcheckbox.pri)
