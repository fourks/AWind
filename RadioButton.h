#pragma once
/*
AWind.h - Arduino window library support for Color TFT LCD Boards
Copyright (C)2016 Andrei Degtiarev. All right reserved


You can always find the latest version of the library at
https://github.com/AndreiDegtiarev/AWind


This library is free software; you can redistribute it and/or
modify it under the terms of the CC BY-NC-SA 3.0 license.
Please see the included documents for further information.

Commercial use of this library requires you to buy a license that
will allow commercial use. This includes using the library,
modified or not, as a tool to sell products.

The license applies to all part of the library including the
examples and tools supplied with the library.
*/
#include "TextBoxString.h"
///Implement radio button control
class RadioButton : public TextBoxTString<const __FlashStringHelper>
{
	bool _isChecked;
public:
	///Constructor
	/**
	\param left left coordinate relative to parent indow
	\param top top coordinate relative to parent indow
	\param width window width
	\param height window height
	\param text button name
	*/
	RadioButton(int left, int top, int width, int height, const __FlashStringHelper * text) :TextBoxTString<const __FlashStringHelper>(left, top, width, height, text, F("Button")), _isChecked(false)
	{
		SetFont(BigFont);
		SetDecorators(Environment::Get()->FindDecorators(F("RadioButtonInactive")));
	}
	bool IsChecked()
	{
		return _isChecked;
	}
	void SetChecked(bool isChecked)
	{
		_isChecked = isChecked;
		if (_isChecked)
			SetDecorators(Environment::Get()->FindDecorators(F("RadioButtonActive")));
		else
			SetDecorators(Environment::Get()->FindDecorators(F("RadioButtonInactive")));
		Invalidate();
	}
};