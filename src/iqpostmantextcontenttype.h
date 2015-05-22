/**********************************************************************************
 * Copyright © 2015 Pavel A. Puchkov                                              *
 *                                                                                *
 * This file is part of IqPostman.                                                *
 *                                                                                *
 * IqPostman is free software: you can redistribute it and/or modify              *
 * it under the terms of the GNU Lesser General Public License as published by    *
 * the Free Software Foundation, either version 3 of the License, or              *
 * (at your option) any later version.                                            *
 *                                                                                *
 * IqPostman is distributed in the hope that it will be useful,                   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of                 *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                  *
 * GNU Lesser General Public License for more details.                            *
 *                                                                                *
 * You should have received a copy of the GNU Lesser General Public License       *
 * along with IqPostman.  If not, see <http://www.gnu.org/licenses/>.             *
 **********************************************************************************/

#ifndef IQPOSTMANTEXTCONTENTTYPE_H
#define IQPOSTMANTEXTCONTENTTYPE_H

#include "iqpostmanabstractcontenttype.h"
#include "iqpostman_global.h"
#include <QHash>

class IQPOSTMANSHARED_EXPORT IqPostmanTextContentType : public IqPostmanAbstractContentType
{
    Q_OBJECT
    Q_PROPERTY(SubType subType READ subType WRITE setSubType NOTIFY subTypeChanged)
    Q_PROPERTY(QString charset READ charset WRITE setCharset NOTIFY charsetChanged)
    Q_ENUMS(SubType)
public:
    enum SubType
    {
        UnknownSubType,
        PlainSubType,
        RichtextSubType,
        EnrichedSubType,
        TabSeparatedValuesSubType,
        HtmlSubType
    };

    explicit IqPostmanTextContentType(QObject *parent = Q_NULLPTR);

    virtual IqPostmanAbstractContentType::ContentType type() const Q_DECL_OVERRIDE;
    virtual QString typeName() const Q_DECL_OVERRIDE;
    static QString staticTypeName();

protected:
    virtual int subTypeNumber() const Q_DECL_OVERRIDE;
    virtual void setSubTypeFromNumber(int subTypeNumber) Q_DECL_OVERRIDE;
    virtual QHash<int, QString> subTypeNames() const Q_DECL_OVERRIDE;
    virtual bool setData(const QHash<QString, QString> &data) Q_DECL_OVERRIDE;
    virtual QHash<QString, QString> data() const Q_DECL_OVERRIDE;

public:
    SubType subType() const;
    void setSubType(const SubType &subType);

    QString charset() const;
    void setCharset(const QString &charset);

signals:
    void subTypeChanged();
    void charsetChanged();

private:
    SubType m_subType;
    static QHash<SubType, QString> m_subTypeNames;
    static QHash<int, QString> m_subTypeIntNames;
    QString m_charset;
};

#endif // IQPOSTMANTEXTCONTENTTYPE_H
