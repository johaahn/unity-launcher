#include "panelapplication.h"

//#include <QtCore/QSettings>
//#include <QtCore/QTimer>
//#include "ui_panelapplicationsettings.h"
//#include "menu_window_exemple.h"
//#include "x11support.h"

PanelApplication* PanelApplication::m_instance = NULL;

PanelApplication::PanelApplication(int& argc, char** argv)
	: QApplication(argc, argv)
{
	m_instance = this;

	setOrganizationName("xxxx");
	setApplicationName("xxxxxxx");

	m_x11support = new X11Support();

	panelWindow = NULL;

}

PanelApplication::~PanelApplication()
{
	delete m_x11support;
	m_instance = NULL;
}

bool PanelApplication::x11EventFilter(XEvent* event)
{
	m_x11support->onX11Event(event);
	return false;
}

void PanelApplication::showConfigurationDialog()
{

}

void PanelApplication::reinit()
{
	init();
}

void PanelApplication::init()
{
	PanelWindow* panelWindow = new PanelWindow();
	panelWindow->show();
}



void PanelApplication::setIconThemeName(const QString& iconThemeName)
{

}
