#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

extern uint16_t counterValue; // Déclaration de la variable externe

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateTime(uint8_t hour, uint8_t minute, uint8_t second);
    void updateDate(uint8_t date, uint8_t month, uint8_t year);
    virtual void upclicked();
    virtual void resetCounter();
    virtual void count(bool state);
    void setCounterValue(uint16_t value);

protected:
    uint16_t counter = 0;
    static const uint16_t TEXTAREA2_SIZE = 234;
    Unicode::UnicodeChar textArea2Buffer[TEXTAREA2_SIZE];

};

#endif // SCREEN1VIEW_HPP
