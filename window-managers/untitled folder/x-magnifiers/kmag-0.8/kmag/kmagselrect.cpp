//$Id: kmagselrect.cpp,v 1.4 2001/11/21 04:51:08 sarang Exp $
//==========================================================================
//
//   KMagSelRect.cpp
//
//==========================================================================


/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "kmagselrect.h"

//--------------------------------------------------------------------------
//   Construction
//--------------------------------------------------------------------------

KMagSelRect::KMagSelRect(QWidget *parent) :
  QRect()
{
  init(parent);
}

KMagSelRect::KMagSelRect(const QPoint &topleft, const QPoint &bottomright,
                 QWidget *parent) :
QRect(topleft, bottomright)
{
  init(parent);
}

KMagSelRect::KMagSelRect(const QPoint &topleft, const QSize &size,
                 QWidget *parent) :
QRect(topleft, size)
{
  init(parent);
}

KMagSelRect::KMagSelRect(int left, int top, int width, int height,
                 QWidget *parent) :
QRect(left, top, width, height)
{
  init(parent);
}

void KMagSelRect::init(QWidget *_parent)
{
  parent = _parent ? _parent : QApplication::desktop();

  isVisible = false;

  // partially stolen from KWM - thanx :-)

  Display *dpy = parent->x11Display();

  XGCValues gv;

  gv.function = GXxor;
  gv.line_width = 0;
  gv.foreground =
  WhitePixel(dpy, DefaultScreen(dpy)) ^
  BlackPixel(dpy, DefaultScreen(dpy));

  gv.subwindow_mode = IncludeInferiors;

  gc = XCreateGC(dpy, parent->winId(),
                 GCForeground | GCFunction | GCLineWidth | GCSubwindowMode,
                 &gv);

	m_alwaysVisible = false;
}

KMagSelRect::~KMagSelRect()
{
  XFreeGC(parent->x11Display(), gc);
}

//--------------------------------------------------------------------------
//   
//--------------------------------------------------------------------------

bool KMagSelRect::visible()
{
  return (isVisible);
}

void KMagSelRect::alwaysVisible(bool visible)
{
	m_alwaysVisible = visible;
}


//--------------------------------------------------------------------------
//   Slots
//--------------------------------------------------------------------------

void KMagSelRect::show()
{
  if ( !isVisible ) {
    isVisible = true;
    paint(*this);
    old = *this;
  }
}

void KMagSelRect::hide()
{
	if(m_alwaysVisible)
		return;
  if ( isVisible ) {
    isVisible = false;
    paint(*this);
  }
}

void KMagSelRect::update()
{
  if ( isVisible ) {
    paint(old);
    paint(*this);
    old = *this;
  }
  emit updated();
}

void KMagSelRect::paint(const QRect &rect)
{
  QRect normRect = rect.normalize();

  //QCursor::setPos(rect.center());

  XDrawRectangle(parent->x11Display(),
                 parent->winId(), gc,
                 min(normRect.left(), normRect.right()) - 1,
                 min(normRect.top(), normRect.bottom()) - 1,
                 abs(normRect.width()) + 1,
                 abs(normRect.height()) + 1);
}
