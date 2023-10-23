#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{
	view.setCounterValue(model->getCounterValue());

}

void Screen1Presenter::deactivate()
{

}
void Screen1Presenter::updateTime(uint8_t hour, uint8_t minute, uint8_t second)
{
	view.updateTime(hour, minute, second);
}
void Screen1Presenter::updateDate(uint8_t date, uint8_t month, uint8_t year)
{
	view.updateDate(date, month, year);
}
void Screen1Presenter::count (bool state)
{
	view.count (state);
}
void Screen1Presenter::saveButton(int counterValue)
{
    // Implémentez le code nécessaire pour stocker la valeur du compteur
    // Cette fonction peut communiquer avec votre modèle ou effectuer toute autre opération appropriée.
	model->saveButton(counterValue);
}
