#ifndef STOPWATCHPAGE_H
#define STOPWATCHPAGE_H

#include "ui_stopwatchpage.h"
#include <QWidget>
#include <QTimer>
#include <QTime>

class StopwatchPage
		: public QWidget
{
	Q_OBJECT

public:
	StopwatchPage(QWidget* parent = 0);

public slots:
	/// Starts/stops the timer
	void trigger();
	/// Update displayed time
	void update();

private:
	Ui::StopwatchPage ui_;
	QTimer gui_timer_; // timer for continous update of UI
	QTime start_time_; // start time of current run
};

#endif // STOPWATCHPAGE_H
