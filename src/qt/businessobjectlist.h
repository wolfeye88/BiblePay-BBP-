#ifndef BUSINESSOBJECTLIST_H
#define BUSINESSOBJECTLIST_H

#include <QWidget>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QMenu>
#include <QTableWidget>

class OptionsModel;
class PlatformStyle;
class WalletModel;


namespace Ui {
class BusinessObjectList;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class BusinessObjectList : public QWidget
{
    Q_OBJECT

public:
    explicit BusinessObjectList(const PlatformStyle *platformStyle, QWidget *parent = 0);
    ~BusinessObjectList();
	void setModel(WalletModel *model);
	void UpdateObject(std::string objType);

private Q_SLOTS:
    void slotNavigateTo();
	void slotCustomMenuRequested(QPoint pos);
	void slotView();
	void slotList();
	void slotWriteOrphan();

private:
    Ui::BusinessObjectList *ui;
	WalletModel *model;
    
private:
    void createUI(const QStringList &headers, const QString &pStr);
    QVector<QVector<QString> > SplitData(const QString &pStr);
    QStringList GetHeaders();


};

#endif // BUSINESSOBJECTLIST_H
