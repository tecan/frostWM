//$Id: main.cpp,v 1.7 2001/11/18 20:34:15 sarang Exp $

/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Mon Feb 12 23:45:41 EST 2001
    copyright            : (C) 2001 by Sarang Lakare
    email                : sarang@users.sf.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>

#include "kmag.h"

KmagApp *kmagapp;

static const char *description =
	I18N_NOOP("Kmag");
// INSERT A DESCRIPTION FOR YOUR APPLICATION HERE
	
	
static KCmdLineOptions options[] =
{
  { "+[File]", I18N_NOOP("file to open"), 0 },
  { 0, 0, 0 }
  // INSERT YOUR COMMANDLINE OPTIONS HERE
};

int main(int argc, char *argv[])
{
	// about the application
  KAboutData *aboutData = new KAboutData("kmag", I18N_NOOP("K Magnifier"), VERSION,
                                         I18N_NOOP("Screen Magnifier for the K Desktop Environment (KDE)"),
                                         KAboutData::License_GPL,
                                         "(C) 2001, Sarang Lakare","",
                                         "http://kmag.sourceforge.net");

  // about the authors
  aboutData->addAuthor("Sarang Lakare",
                       "ReWrite + Current Maintainer","sarang@users.sf.net",
                       "http://www.cs.sunysb.edu/~lsarang/linux");
  aboutData->addAuthor("Michael Forster",
                       "Original Idea & Author (KDE1)", "forster@fmi.uni-passau.de");
	aboutData->addCredit("Claudiu Costin", "Tips, competition ;)", "claudiuc@work.ro",
                       "http://www.ro.kde.org");

	KCmdLineArgs::init( argc, argv, aboutData );
	KCmdLineArgs::addCmdLineOptions( options ); // Add our own options.

  KApplication app;
 
  if (app.isRestored())
  {
    RESTORE(KmagApp);
  }
  else 
  {
    kmagapp = new KmagApp();
    kmagapp->show();

    KCmdLineArgs *args = KCmdLineArgs::parsedArgs();
		
		args->clear();
  }

  return app.exec();
}  
