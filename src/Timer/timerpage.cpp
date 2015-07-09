#include "timerpage.h"

#include <QFile>
#include <QMenu>
#include <QDebug>

TimerPage::TimerPage(QWidget* parent)
	: QWidget(parent)
	, ui_()
	, start_time_()
	, tray_icon_(QIcon(":/Timer/icon.png"))
	, tray_timer_()
	, sound_(":/Timer/Resources/sound.wav")
{
	ui_.setupUi(this);

	connect(ui_.button, SIGNAL(clicked()), this, SLOT(trigger()));

	ui_.time->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui_.time, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(timeContextMenu(QPoint)));

	gui_timer_.setInterval(100);
	gui_timer_.setSingleShot(false);
	connect(&gui_timer_, SIGNAL(timeout()), this, SLOT(update()));

	tray_timer_.setSingleShot(true);
	tray_timer_.setInterval(10000);
	connect(&tray_timer_, SIGNAL(timeout()), &tray_icon_, SLOT(hide()));

	sound_.setLoops(3);
}

void TimerPage::timeContextMenu(QPoint point)
{
	QMenu* menu = new QMenu();
	menu->addAction("00:00:30");
	menu->addAction("00:01:00");
	menu->addAction("00:02:00");
	menu->addAction("00:03:00");
	menu->addAction("00:04:00");
	menu->addAction("00:04:30");
	menu->addAction("00:04:45");
	menu->addAction("00:05:00");
	menu->addAction("00:10:00");
	menu->addAction("00:15:00");
	menu->addAction("00:30:00");
	menu->addAction("00:45:00");
	menu->addAction("01:00:00");
	menu->addAction("02:00:00");
	menu->addAction("04:00:00");
	if (QAction* action = menu->exec(ui_.time->mapToGlobal(point)))
	{
		ui_.time->setTime(QTime::fromString(action->text()));
	}
}

void TimerPage::update()
{
	QTime elapsed = QTime(0,0,0,0).addMSecs(start_time_.elapsed());

	QTime left = QTime(0,0,0,0).addMSecs(elapsed.msecsTo(overall_time_));
	ui_.time->setTime(left);

	//perform action if time is over
	if (elapsed>=overall_time_)
	{
		activateWindow();

		QString action = ui_.action->currentText();
		if (action=="play sound")
		{
			sound_.play();
		}
		else if (action=="shut down")
		{
			system("shutdown -s -t 10");
		}

		//always show visual alarm
		tray_icon_.show();
		tray_icon_.showMessage("Timer", "timed out!", QSystemTrayIcon::NoIcon);
		tray_timer_.start();

		trigger();
	}
}

void TimerPage::trigger()
{
	//stop timer
	if (ui_.button->text()=="stop")
	{
		gui_timer_.stop();
		ui_.button->setText("start");
		ui_.time->setEnabled(true);
		ui_.action->setEnabled(true);
		ui_.time->setTime(overall_time_);
	}
	//start timer
	else
	{
		overall_time_ = ui_.time->time();
		gui_timer_.start();
		start_time_.start();
		ui_.button->setText("stop");
		ui_.time->setEnabled(false);
		ui_.action->setEnabled(false);
	}
}
