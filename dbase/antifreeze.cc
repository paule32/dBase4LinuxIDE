// --------------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2018 Jens Kallup
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------
#include "antifreeze.h"
// -----------------------------------------------
// this ns check all 5 seconds, if the application
// produce inf memory leaks or simply freeze.
// Is so, then try to free memory and exit app ...
// -----------------------------------------------
namespace antifreeze
{
	using namespace std;

	int appSize = 0, oldSize = 0;
	int memDyna = 0, oldDmem = 0;

	// ------------------------------
	// start of monitoring memory ...
	// ------------------------------
	void MyTimer::MyTimerSlot()
	{
		qDebug() << "Memory thread initialized...";

		if (oldSize > appSize+10) {
		}

/*
        #if Q_OS_LINUX
		ifstream buffer("/proc/self/statm");
		buffer  >> appSize
				>> memDyna;

		long page_size_kb = sysconf(_SC_PAGESIZE) / 1024;
		double rss = memDyna * page_size_kb;

		qDebug() << "Mem: " << rss;
		#endif
*/
	}

	// -----------------------------
	// simple timer function:
	// set interval, connect to proc
	// -----------------------------
	MyTimer::MyTimer()
	{
#ifdef TIMERS_TESTERS
		timer = new QTimer(this);
		connect(timer,
			SIGNAL(timeout()),this,
			SLOT(MyTimerSlot()));

		timer->start(5000);  // check memory/freeze all 5 seconds
#endif
	}

	// simple doofy
	void init() { /*MyTimer *ltimer = new MyTimer; qDebug() << "gesetinhs"; */ }

}  // namespace antifreeze

