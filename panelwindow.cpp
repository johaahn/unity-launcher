#include "panelwindow.h"

#include <iostream>

#include <QtGui/QResizeEvent>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMenu>
#include <QtQml/QQmlEngine>
#include <paths.h>

#include "panelapplication.h"
#include "x11support.h"



PanelWindow::PanelWindow() :
		QQuickView(), m_screen(0) {
	bool isMirServer = false;
    if (qgetenv("QT_QPA_PLATFORM") == "ubuntumirclient") {
        setenv("QT_QPA_PLATFORM", "mirserver", 1 /* overwrite */);
        isMirServer = true;
    }

	std::cout << "winId = " << winId() << std::endl;
	;
	//setFlags(Qt::WA_X11NetWmWindowTypeDock);

#if QT_VERSION >= 0x050000
	//setWindowFlags(Qt::BypassWindowManagerHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
#endif
	// When in dock mode, panel should appear on all desktops.
	unsigned long desktop = 0xFFFFFFFF;
	X11Support::setWindowPropertyCardinal(winId(), "_NET_WM_DESKTOP", desktop);
	X11Support::setWindowPropertyDock (winId());
	//menu_win = new MyMenuWindow(this, m_screen);

	setColor("black");
	setTitle("Unity8 Shell");
	engine()->setBaseUrl(QUrl::fromLocalFile(::qmlDirectory()));

	QUrl source(::qmlDirectory() + "Main.qml");
	prependImportPaths(engine(), ::overrideImportPaths());
	if (!isMirServer) {
		prependImportPaths(engine(), ::nonMirImportPaths());
	}
	appendImportPaths(engine(), ::fallbackImportPaths());

	 setSource(source);
	 // ???QObject::connect(view->engine(), SIGNAL(quit()), application, SLOT(quit()));
	//setStyleSheet("background-color:red;");

	updateLayout();
	updatePosition();

}

PanelWindow::~PanelWindow() {

}

void PanelWindow::setScreen(int screen) {
	m_screen = screen;
	updateLayout();
	updatePosition();
}

void PanelWindow::updatePosition() {
	/* Partial struct content definition */
	enum {
		PS_LEFT = 0,
		PS_RIGHT = 1,
		PS_TOP = 2,
		PS_BOTTOM = 3,
		PS_LEFT_START_Y = 4,
		PS_LEFT_END_Y = 5,
		PS_RIGHT_START_Y = 6,
		PS_RIGHT_END_Y = 7,
		PS_TOP_START_X = 8,
		PS_TOP_END_X = 9,
		PS_BOTTOM_START_X = 10,
		PS_BOTTOM_END_X = 11,
	};

	QRect screenGeometry = QApplication::desktop()->screenGeometry(m_screen);

	// Values for setting _NET_WM_STRUT_PARTIAL property.
	QVector<unsigned long> values;
	values.fill(0, 12);

	values[PS_LEFT] = 48;
	values[PS_LEFT_START_Y] = 0;
	values[PS_LEFT_END_Y] = screenGeometry.height();

	//move(0, 0);

	/* set partial strut */
	X11Support::setWindowPropertyCardinalArray(winId(), "_NET_WM_STRUT_PARTIAL",
			values);

}

void PanelWindow::resizeEvent(QResizeEvent* event) {
	updateLayout();
	updatePosition();
}

void PanelWindow::updateLayout() {
	QRect screenGeometry = QApplication::desktop()->screenGeometry(m_screen);
	resize(48, screenGeometry.height());
}

void PanelWindow::showPanelContextMenu(const QPoint& point) {
#if 0
	QMenu menu;
	menu.addAction(QIcon::fromTheme("application-exit"), "Quit panel",
			QApplication::instance(), SLOT(quit()));
	menu.exec(pos() + point);
#endif
}

void PanelWindow::mousePressEvent(QMouseEvent * event) {

}

void PanelWindow::mouseReleaseEvent(QMouseEvent * event) {
	if (event->button() == Qt::LeftButton) {
		//menu_win->clicked();
	} else {
		showPanelContextMenu(event->pos());
	}
}

