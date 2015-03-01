#ifndef PANELAPPLICATION_H
#define PANELAPPLICATION_H

#include <QtWidgets/QApplication>
#include <QtGui/QFont>
#include "panelwindow.h"
#include "menu_window_exemple.h"
#include <QtCore/QSettings>
#include <QtCore/QTimer>
//#include "ui_panelapplicationsettings.h"
//#include "menu_window_exemple.h"
#include <x11support.h>
class IconLoader;
class X11Support;
class DesktopApplications;

class PanelApplication: public QApplication
{
	Q_OBJECT
public:
	PanelApplication(int& argc, char** argv);
	~PanelApplication();

	static PanelApplication* instance()
	{
		return m_instance;
	}

	bool x11EventFilter(XEvent* event);

	void init();

	void setFontName(const QString& fontName);
	void setIconThemeName(const QString& iconThemeName);

public slots:
	void showConfigurationDialog();

private slots:
	void reinit();

private:
	static PanelApplication* m_instance;
	X11Support* m_x11support;
	DesktopApplications* m_desktopApplications;

	PanelWindow * panelWindow;

};

#endif
