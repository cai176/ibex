#ifndef ALGORITHMPLUGINMGR_H
#define ALGORITHMPLUGINMGR_H

#include <QObject>
#include <QDir>
#include "ialgorithm.h"
#include <QMap>

class FiltersDialog;
class FilterPluginMgr : public QObject
{
    Q_OBJECT
public:
    explicit FilterPluginMgr(QObject *parent, QString path);
    explicit FilterPluginMgr(QObject *parent, FiltersDialog& Dialog);
    void LoadPlugins();
    QMap<int,IAlgorithm*> GetWidgetList();

signals:

public slots:
    void OnActivateFilterPluginDialog();
private:
    QString m_path;
    QDir m_pluginsDir;
    FiltersDialog& m_dialog;
    QMap<int,IAlgorithm*> m_algorithmContainer;

};

#endif // ALGORITHMPLUGINMGR_H
