#include <gui/screen3_screen/Screen3View.hpp>
#include "stdio.h"
#include <cstring>

Screen3View::Screen3View()
{
	keyboard.setPosition (77,19,368,243);
	add(keyboard);
	keyboard.setVisible (false);
	keyboard.invalidate();

}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}
void Screen3View::NameClicked()
{
	keyboard.setVisible (true);
	keyboard.invalidate();
	flexButtonOk.setVisible(true);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(true);
	flexButtonExit.invalidate();
	buttonWithLabelSend.setVisible(false);
	buttonWithLabelSend.invalidate();
	namemod = 1;
	mdpmod = 0;
}
void Screen3View::MdpClicked()
{
	keyboard.setVisible (true);
	keyboard.invalidate();
	flexButtonOk.setVisible(true);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(true);
	flexButtonExit.invalidate();
	buttonWithLabelSend.setVisible(false);
    buttonWithLabelSend.invalidate();
	namemod = 0;
	mdpmod = 1;
}
void Screen3View::OkClicked()
{
	keyboard.setVisible (false);
	keyboard.invalidate();
	flexButtonOk.setVisible(false);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(false);
	flexButtonExit.invalidate();
	buttonWithLabelSend.setVisible(true);
	buttonWithLabelSend.invalidate();
	if (namemod)
	{
		Unicode::strncpy(textAreaNameBuffer, keyboard.getBuffer(), TEXTAREANAME_SIZE);
		textAreaName.invalidate();
	}
	if (mdpmod)
	{
		Unicode::strncpy(textAreaMdpBuffer, keyboard.getBuffer(), TEXTAREAMDP_SIZE);
		textAreaMdp.invalidate();
	}
	keyboard.clearBuffer();

}
void Screen3View::ExitClicked()
{
	keyboard.setVisible (false);
	keyboard.invalidate();
	flexButtonOk.setVisible(false);
	flexButtonOk.invalidate();
	flexButtonExit.setVisible(false);
	flexButtonExit.invalidate();
	buttonWithLabelSend.setVisible(true);
	buttonWithLabelSend.invalidate();
	namemod = mdpmod = 0;
}
void Screen3View::SendClicked()
{
	int i = 0;
	do
	{
		NameBuf[i] = (char) textAreaNameBuffer[i];
		i++;
	}while (textAreaNameBuffer[i]!=0);
	i = 0;
	do
	{
		MdpBuf[i] = (char) textAreaMdpBuffer[i];
		i++;
	}while (textAreaMdpBuffer[i]!=0);
	sprintf (dataBuf, "%s,%s\r\n", NameBuf, MdpBuf);
	presenter->sendData(dataBuf);
	memset (NameBuf, '\0', TEXTAREANAME_SIZE);
	memset (MdpBuf, '\0', TEXTAREAMDP_SIZE);

}
