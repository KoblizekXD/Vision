#ifndef CWINDOW_H
#define CWINDOW_H

#define WINDOW(NAME) class NAME final : public Window

class Window {
public:
    virtual void Initialize() = 0;
    virtual void Frame() = 0;

    virtual ~Window() = default;
};

#endif //CWINDOW_H
