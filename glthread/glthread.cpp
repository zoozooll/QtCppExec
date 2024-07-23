#include "glthread.h"
#include "eglhelper.h"

void GLThread::stopEglSurfaceLocked()
{
    if (mHaveEglSurface)
    {
        mHaveEglSurface = false;
        mEglHelper->destroySurface();
    }
}

void GLThread::stopEglContextLocked()
{
    if (mHaveEglContext)
    {
        mEglHelper->finish();
        mHaveEglContext = false;
        cv.notify_all();
    }
}

void GLThread::guardedRun()
{
    mEglHelper = new EglHelper();
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
