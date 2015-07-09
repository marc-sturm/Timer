#include "timerwindow.h"
#include "timerpage.h"
#include "stopwatchpage.h"

#include <QMenuBar>
#include <QToolButton>
#include "Settings.h"

#include <iostream>

TimerWindow::TimerWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui_()
{
	ui_.setupUi(this);
	setWindowTitle(QApplication::applicationName());
	ui_.stack->addWidget(new TimerPage());
	ui_.stack->addWidget(new StopwatchPage());

	setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

	connect(ui_.timer_btn, SIGNAL(pressed()), this, SLOT(showTimer()));
	connect(ui_.stop_btn, SIGNAL(pressed()), this, SLOT(showStopwatch()));
}

void TimerWindow::showTimer()
{
	ui_.stack->setCurrentIndex(0);
}

void TimerWindow::showStopwatch()
{
	ui_.stack->setCurrentIndex(1);
}
