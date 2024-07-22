#ifndef GLTHREAD_H
#define GLTHREAD_H

#include <vector>
#include <functional>
#include <mutex>
#include <condition_variable>

class EglHelper;

class IGLView;

class GLThread
{
private:
    bool mShouldExit = false;
    bool mExited = false;

    bool mRequestPaused = false;
    bool mPaused = false;
    bool mHasSurface = false;
    bool mSurfaceIsBad = false;
    bool mWaitingForSurface = false;
    bool mHaveEglContext = false;
    bool mHaveEglSurface = false;
    bool mFinishedCreatingEglSurface = false;
    bool mShouldReleaseEglContext = false;
    int mWidth = 0;
    int mHeight = 0;
    int mRenderMode = 0;
    bool mRequestRender = true;
    bool mWantRenderNotification = true;
    bool mRenderComplete = false;
    std::vector<std::function<void()>> mEventQueue;
    bool mSizeChanged = true;
    std::function<void()> *mFinishDrawingRunnable = nullptr;
    EglHelper* mEglHelper = nullptr;
    IGLView* mGLSurfaceViewWeakRef = nullptr;

    std::mutex mutex;
    std::condition_variable cv;

    void stopEglSurfaceLocked();

    void stopEglContextLocked();

    void guardedRun();

    bool readyToDraw();

public:
    GLThread();

    void run();

    bool ableToDraw();

    int getRenderMode() const;

    void setRendMode(const int &renderMode);

    void requestRender();

    void requestRenderAndNotify(const std::function<void()>& finishDrawing);

    void surfaceDestroyed();

    void onPause();

    void onResume();

    void onWindowResize(int w, int h);

    void requestExitAndWaint();

    void requestReleaseEglContextLocked();

    void queueEvent(const std::function<void()> &r);
};

#endif // GLTHREAD_H
