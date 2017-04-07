/****************************************************************************
**
** Copyright (C) 2005-2008 Trolltech ASA. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** Licensees holding a valid Qt License Agreement may use this file in
** accordance with the rights, responsibilities and obligations
** contained therein.  Please consult your licensing agreement or
** contact sales@trolltech.com if any conditions of this licensing
** agreement are not clear to you.
**
** Further information about Qt licensing is available at:
** http://www.trolltech.com/products/qt/licensing.html or by
** contacting info@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef ReportConfigReader_H
#define ReportConfigReader_H

#include <QXmlStreamReader>

//! [0]
class ReportConfigReader : public QXmlStreamReader
{
public:
//! [1]
    ReportConfigReader(QBuffer *reportConfig);
//! [1]
	bool IsEndTimeValid();
	int getPeriodUnit();

	QBuffer *reportConfig;
};
//! [0]

#endif
