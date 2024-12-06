#ifndef DISPLAYSCREEN_H
#define DISPLAYSCREEN_H

class DisplayScreen {
public:
    virtual void render() = 0;
    virtual ~DisplayScreen() = default;
};

#endif