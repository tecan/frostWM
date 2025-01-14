//$Id: kmagselrect.h,v 1.5 2002/03/21 19:26:07 sarang Exp $
//==========================================================================
//
//   KMagSelRect.h
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

#ifndef KMAGSELRECT_H
#define KMAGSELRECT_H

#include <stdlib.h>

// Qt includes
#include <qapp.h>
#include <qrect.h>
#include <qwidget.h>
#include <qcursor.h>

// X11 includes
#include <X11/Xlib.h>

// Min function
#define min(a,b) ((a) < (b) ? (a) : (b))

/**
 * This class stores the selected rectangular area for grabbing. It also displays the
 * rectangular area on demand.
 * 
 * @author Original : Michael Forster
 * @author Current : Sarang Lakare
 */
class KMagSelRect : public QObject, public QRect
{
    Q_OBJECT
    
public:
    KMagSelRect(QWidget *parent=0);
    KMagSelRect(const QPoint &topleft, const QPoint &bottomright,
	    QWidget *parent=0);
    KMagSelRect(const QPoint &topleft, const QSize &size,
	    QWidget *parent=0);
    KMagSelRect(int left, int top, int width, int height,
	    QWidget *parent=0);

    virtual ~KMagSelRect();

    bool visible();

		/// Makes the rectangle always visible
		void alwaysVisible(bool visible=true);

		/// Returns true if always visible is set
		bool getAlwaysVisible() const {
			return (m_alwaysVisible);
		};
    
public slots:	

    void show();
    void hide();
    void update();

signals:

    void updated();
    
protected:

    void init(QWidget *);
    void paint(const QRect &);
    
    GC gc;
    QWidget *parent;
    bool isVisible;
    QRect old;
		bool m_alwaysVisible;

};

#endif // KMAGSELRECT_H
