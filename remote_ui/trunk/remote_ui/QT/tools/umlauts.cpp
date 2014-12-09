#include "tools/umlauts.h"

namespace Umlauts {

    QString replaceUmlauts(QString qs_text)
    {
        qs_text.replace(QChar(129), QString::fromUtf8("ü"));
        qs_text.replace(QChar(130), QString::fromUtf8("é"));
        qs_text.replace(QChar(131), QString::fromUtf8("â"));
        qs_text.replace(QChar(132), QString::fromUtf8("ä"));
        qs_text.replace(QChar(133), QString::fromUtf8("à"));
        qs_text.replace(QChar(134), QString::fromUtf8("å"));
        qs_text.replace(QChar(135), QString::fromUtf8("ç"));
        qs_text.replace(QChar(136), QString::fromUtf8("ê"));
        qs_text.replace(QChar(137), QString::fromUtf8("ë"));
        qs_text.replace(QChar(138), QString::fromUtf8("è"));
        qs_text.replace(QChar(139), QString::fromUtf8("ï"));
        qs_text.replace(QChar(140), QString::fromUtf8("î"));
        qs_text.replace(QChar(141), QString::fromUtf8("ì"));
        qs_text.replace(QChar(142), QString::fromUtf8("Ä"));


        qs_text.replace(QChar(145), QString::fromUtf8("æ"));
        qs_text.replace(QChar(146), QString::fromUtf8("Æ"));
        qs_text.replace(QChar(147), QString::fromUtf8("ô"));
        qs_text.replace(QChar(148), QString::fromUtf8("ö"));
        qs_text.replace(QChar(149), QString::fromUtf8("ò"));
        qs_text.replace(QChar(150), QString::fromUtf8("û"));
        qs_text.replace(QChar(153), QString::fromUtf8("Ö"));
        qs_text.replace(QChar(154), QString::fromUtf8("Ü"));
        qs_text.replace(QChar(225), QString::fromUtf8("ß"));
        qs_text.replace(QChar(245), QString::fromUtf8("ä"));

        qs_text.replace("Ã¤", "ä");
        qs_text.replace("Ã–", "Ö");
        qs_text.replace("Ã¶", "ö");
        qs_text.replace("Ãœ", "Ü");
        qs_text.replace("Ã¼", "ü");
        qs_text.replace("ÃŸ", "ß");
        qs_text.replace("€", "EUR");
        qs_text.replace("„", "\"");
        qs_text.replace("“", "\"");

        qs_text.replace("\t", "   ");

        return qs_text;
    }

}
