#ifndef ROOMNAME_H
#define ROOMNAME_H

#include <QString>
#include <QColor>

namespace BuildingEditor {
    class RoomName
    {
    public:
        QString label;
        QString internalName;
        QColor color;
    };
}

#endif // ROOMNAME_H
