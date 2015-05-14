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

#ifndef IQPOSTMANMIME_H
#define IQPOSTMANMIME_H

#include <QString>
#include <QObject>
#include "iqpostman_global.h"

class IQPOSTMANSHARED_EXPORT IqPostmanMime
{
    Q_GADGET
    Q_ENUMS(ContentType)
    Q_ENUMS(ContentTransferEncoding)
public:
    enum ContentType
    {
        TypeUnknown,
        TypeText,
        TypeMultipart,
        TypeMessage,
        TypeImage,
        TypeAudio,
        TypeVideo,
        TypeApplication
    };

//    enum MessageSubType
//    {
//        MessageRfc822,
//        MessagePartial,
//        MessageExternalBody
//    };

//    enum ImageSubType
//    {
//        ImageJpg,
//        ImagePng,
//        ImageBmp,
//        ImageTiff
//    };

//    enum AudioSubType
//    {
//        AudioBasic,
//        AudioMp3
//    };

//    enum VideoSubType
//    {
//        VideoMpeg,
//        VideoQuicktime
//    };

//    enum ApplicationSubType
//    {
//        ApplicationOctetStream,
//        ApplicationPostScript,
//        ApplicationRtf,
//        ApplicationPdf,
//        ApplicationMsword
//    };

    enum ContentTransferEncoding
    {
        EncodingUnknown,
        Encoding7bit,
        EncodingQuotedPrintable,
        EncodingBase64,
        Encoding8bit,
        EncodingBinary
    };

    IqPostmanMime();

    static ContentType contentTypeFromString(const QString &string);
    static ContentTransferEncoding contentTransferEncodingFromString(const QString &string);
    static QString contentTransferEncodingToString(ContentTransferEncoding encoding);
};

#endif // IQPOSTMANMIME_H
