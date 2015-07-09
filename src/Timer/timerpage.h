#ifndef TIMERPAGE_H
#define TIMERPAGE_H

#include "ui_timerpage.h"
#include <QWidget>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QSound>

class TimerPage
		: public QWidget
{
	Q_OBJECT

public:
	TimerPage(QWidget* parent = 0);


	///Performs the requested action
	void performAction();

public slots:
	///Start/stop timer
	void trigger();
	///Update displayed time
	void update();
	///Set the time through the context menu
	void timeContextMenu(QPoint point);

private:
	Ui::TimerPage ui_;
	QTimer gui_timer_; // timer for continous update of UI
	QTime overall_time_; // overall time of current run
	QTime start_time_; // start time of current run
	QSystemTrayIcon tray_icon_;
	QTimer tray_timer_;
	QSound sound_;
};

#endif // TIMERPAGE_H
