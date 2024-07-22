#include "glthread.h"

void GLThread::stopEglSurfaceLocked()
{
    if (mHaveEglSurface)
    {
        mHaveEglSurface = false;

    }
}

GLThread::GLThread()
{

}

void GLThread::run()
{
    guardedRun();
    mExited = true;
    {
        std::lock_guard<std::mutex> lock(mutex);
        cv.notify_all();
    }
}
