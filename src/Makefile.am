bin_PROGRAMS = asuroflash

EXTRA_DIST = \
	WinSerial.cpp \
	WinSerial.h

asuroflash_SOURCES = \
	Con_Flash.cpp \
	ANSIAsuro.cpp \
	ANSIAsuro.h \
	Asuro.cpp \
	Asuro.h \
	PosixSerial.cpp \
	PosixSerial.h \
	Serial.cpp \
	Serial.h

if HAVE_QT4
bin_PROGRAMS += qasuroflash

qasuroflash_CPPFLAGS = \
	$(QT4_CFLAGS)

qasuroflash_LDADD = \
	$(QT4_LIBS)

qasuroflash_SOURCES = \
	Main.cpp \
	Picture.h \
	Qt_FlashDialog.cpp \
	Qt_FlashDialog.h \
	Asuro.cpp \
	Asuro.h \
	PosixSerial.cpp \
	PosixSerial.h \
	Serial.cpp \
	Serial.h

nodist_qasuroflash_SOURCES = \
	Qt_FlashDialog.moc.cpp

CLEANFILES = $(nodist_qasuroflash_SOURCES)

# Define special suffices for moc/uic
SUFFIXES = .ui.h .moc.cpp

# Convert %.ui files into %.ui.h
.ui.ui.h:
	$(UIC_QT4) $< -o $@

# Create %.moc.cpp from %.h
.h.moc.cpp:
	$(MOC_QT4) $< -o $@

endif # HAVE_QT3

