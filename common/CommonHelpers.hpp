#pragma once

#include <QJsonArray>
#include <QJsonObject>
#include <QString>
struct ShadowSocksRServerObject
{
    QString address;
    QString method;
    QString password;
    QString protocol;
    QString protocol_param;
    QString obfs;
    QString obfs_param;
    QString remarks; // Unused
    QString group;   // Unused
    int port;
    ShadowSocksRServerObject()
        : address("0.0.0.0"), method("rc4"), password(""), protocol("origin"), protocol_param(""), obfs("plain"), obfs_param(""), remarks(""),
          group(""), port(0)
    {
    }
#define _X_(json, key, type) this->key = json[#key].to##type()
    void loadJson(const QJsonObject &o)
    {
        _X_(o, address, String);
        _X_(o, method, String);
        _X_(o, password, String);
        _X_(o, protocol, String);
        _X_(o, protocol_param, String);
        _X_(o, obfs, String);
        _X_(o, obfs_param, String);
        _X_(o, remarks, String);
        _X_(o, group, String);
        _X_(o, port, Int);
    }
#undef _X_
    [[nodiscard]] static ShadowSocksRServerObject fromJson(const QJsonObject &o)
    {
        ShadowSocksRServerObject out;
        out.loadJson(o);
        return out;
    }
#define _X_(json, key) json[#key] = key
    QJsonObject toJson() const
    {
        QJsonObject out;
        _X_(out, address);
        _X_(out, method);
        _X_(out, password);
        _X_(out, protocol);
        _X_(out, protocol_param);
        _X_(out, obfs);
        _X_(out, obfs_param);
        _X_(out, remarks);
        _X_(out, group);
        _X_(out, port);
        return out;
    }
#undef _X_
};

QString SafeBase64Decode(QString string);
QString SafeBase64Encode(const QString &string, bool trim = true);
