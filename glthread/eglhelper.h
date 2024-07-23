#ifndef EGLHELPER_H
#define EGLHELPER_H


class IGLView;

class EglHelper
{
private:
    IGLView* mGLSurfaceViewWeakRef = nullptr;

public:
    EglHelper();

    void start();

    bool createSurface();

    void createGL();

    int swap();

    void destroySurface();

    void finish();
};

#endif // EGLHELPER_H
