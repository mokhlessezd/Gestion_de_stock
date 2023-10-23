#include <gui/screen1_screen/Screen1View.hpp>
uint16_t counterValue = 0;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateTime(uint8_t hour, uint8_t minute, uint8_t second)
{
    analogClock1.setTime24Hour(hour, minute, second);
    if (hour == 0 && minute == 0 && second == 10)
        {
            resetCounter(); // Réinitialiser le compteur
        }
}

void Screen1View::updateDate(uint8_t date, uint8_t month, uint8_t year)
{
	digitalClock1.setTime24Hour(date, month, year);
}

void Screen1View::upclicked()
{
    counter++;
    counterValue = counter;
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%u", counter);
    textArea1.invalidate();
    presenter->saveButton(counterValue); // Appel de la fonction saveButton() avec la valeur du compteur
}
void Screen1View::resetCounter()
{
    counter = 0;
    counterValue = counter;
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%u", counter);
    textArea1.invalidate();
    presenter->saveButton(counterValue); // Appel de la fonction saveButton() avec la valeur du compteur
}

void Screen1View::count(bool state)
{
    counter++;
    counterValue = counter;
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%u", counter);
    textArea1.invalidate();
}

void Screen1View::setCounterValue(uint16_t value)
{
    counter = value;
    counterValue = value;
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%u", counter);
    textArea1.invalidate();
}
