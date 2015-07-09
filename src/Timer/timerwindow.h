#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include "ui_timerwindow.h"
#include <QMainWindow>

class TimerWindow
		: public QMainWindow
{
	Q_OBJECT

public:
	TimerWindow(QWidget* parent = 0);

public slots:
	///Show timer page
	void showTimer();
	///Show stopwatch page
	void showStopwatch();

private:
	Ui::TimerWindow ui_;
};

#endif // TIMERWINDOW_H
