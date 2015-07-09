#include "stopwatchpage.h"

StopwatchPage::StopwatchPage(QWidget* parent)
	: QWidget(parent)
	, ui_()
	, start_time_()
{
	ui_.setupUi(this);
	ui_.time->display("00:00:000");

	connect(ui_.button, SIGNAL(clicked()), this, SLOT(trigger()));

	gui_timer_.setInterval(5);
	gui_timer_.setSingleShot(false);
	connect(&gui_timer_, SIGNAL(timeout()), this, SLOT(update()));
}

void StopwatchPage::trigger()
{
	// start timer
	if (ui_.button->text()=="start")
	{
		ui_.button->setText("stop");
		start_time_.start();
		gui_timer_.start();
	}
	// stop timer
	else
	{
		ui_.button->setText("start");
		gui_timer_.stop();
	}
}

void StopwatchPage::update()
{
	QTime elapsed = QTime(0, 0, 0, 0).addMSecs(start_time_.elapsed());
	ui_.time->display(elapsed.toString("mm:ss:zzz"));
}
