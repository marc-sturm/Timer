#include "Application.h"
#include "timerwindow.h"

int main(int argc, char *argv[])
{
	Application a(argc, argv);

	TimerWindow w;
	w.setWindowFlags(w.windowFlags() ^ Qt::WindowMaximizeButtonHint);
	w.show();

	w.setMinimumSize(w.size());
	w.setMaximumSize(w.size());

	return a.exec();
}
