#ifndef QWMICOMPUTERSYSTEM_H
#define QWMICOMPUTERSYSTEM_H

#include <QObject>
#include <QVector>

#include "qabstractwmi.h"
#include "extern.h"
#include "define.h"

class QWmiComputerSystem : public QObject, public QAbstractWmi
{
	Q_OBJECT

public:
	QWmiComputerSystem(QObject *parent=0);
	~QWmiComputerSystem();

	enum {Type=WMI_TYPE_COMPUTER_SYSTEM};

public:
	virtual int type(){ return Type; }
	virtual QVariant result() CONVERT_TO_VARIANT(m_vecSystem)

protected:
	virtual void beferQuery();
	virtual QStringList query();
	virtual void record(IWbemClassObject* object, IWbemServices* service, int index);

private:
	QVector<ComputerSystem>	m_vecSystem;
};

#endif // QWMICOMPUTERSYSTEM_H
