#include "wsylist.h"

WSYList::WSYList()
{
    qsrand(QTime(0, 0, 0).msecsTo(QTime::currentTime()));
}

void WSYList::makeWSYList(bool isQingEnable, bool isZuoEnable, bool isAoEnable)
{
    this->wsyList.clear();
    if (isQingEnable)
    {
        this->wsyList.append(WSY("a", "あ", "ア"));
        this->wsyList.append(WSY("i", "い", "イ"));
        this->wsyList.append(WSY("u", "う", "ウ"));
        this->wsyList.append(WSY("e", "え", "エ"));
        this->wsyList.append(WSY("o", "お", "オ"));
        this->wsyList.append(WSY("ka", "か", "カ"));
        this->wsyList.append(WSY("ki", "き", "キ"));
        this->wsyList.append(WSY("ku", "く", "ク"));
        this->wsyList.append(WSY("ke", "け", "ケ"));
        this->wsyList.append(WSY("ko", "こ", "コ"));
        this->wsyList.append(WSY("sa", "さ", "サ"));
        this->wsyList.append(WSY("shi", "し", "シ"));
        this->wsyList.append(WSY("su", "す", "ス"));
        this->wsyList.append(WSY("se", "せ", "セ"));
        this->wsyList.append(WSY("so", "そ", "ソ"));
        this->wsyList.append(WSY("ta", "た", "タ"));
        this->wsyList.append(WSY("chi", "ち", "チ"));
        this->wsyList.append(WSY("tsu", "つ", "ツ"));
        this->wsyList.append(WSY("te", "て", "テ"));
        this->wsyList.append(WSY("to", "と", "ト"));
        this->wsyList.append(WSY("na", "な", "ナ"));
        this->wsyList.append(WSY("ni", "に", "ニ"));
        this->wsyList.append(WSY("nu", "ぬ", "ヌ"));
        this->wsyList.append(WSY("ne", "ね", "ネ"));
        this->wsyList.append(WSY("no", "の", "ノ"));
        this->wsyList.append(WSY("ha", "は", "ハ"));
        this->wsyList.append(WSY("hi", "ひ", "ヒ"));
        this->wsyList.append(WSY("fu", "ふ", "フ"));
        this->wsyList.append(WSY("he", "へ", "ヘ"));
        this->wsyList.append(WSY("ho", "ほ", "ホ"));
        this->wsyList.append(WSY("ma", "ま", "マ"));
        this->wsyList.append(WSY("mi", "み", "ミ"));
        this->wsyList.append(WSY("mu", "む", "ム"));
        this->wsyList.append(WSY("me", "め", "メ"));
        this->wsyList.append(WSY("mo", "も", "モ"));
        this->wsyList.append(WSY("ya", "や", "ヤ"));
        this->wsyList.append(WSY("i", "い", "イ", false));
        this->wsyList.append(WSY("yu", "ゆ", "ユ"));
        this->wsyList.append(WSY("e", "え", "エ", false));
        this->wsyList.append(WSY("yo", "よ", "ヨ"));
        this->wsyList.append(WSY("ra", "ら", "ラ"));
        this->wsyList.append(WSY("ri", "り", "リ"));
        this->wsyList.append(WSY("ru", "る", "ル"));
        this->wsyList.append(WSY("re", "れ", "レ"));
        this->wsyList.append(WSY("ro", "ろ", "ロ"));
        this->wsyList.append(WSY("wa", "わ", "ワ"));
        this->wsyList.append(WSY("i", "い", "イ", false));
        this->wsyList.append(WSY("u", "う", "ウ", false));
        this->wsyList.append(WSY("e", "え", "エ", false));
        this->wsyList.append(WSY("wo", "を", "ヲ"));
        this->wsyList.append(WSY("n", "ん", "ン"));
        this->wsyList.append(WSY("", "\r\n", "\r\n", false));
    }
    if (isZuoEnable)
    {
        this->wsyList.append(WSY("ga", "が", "ガ"));
        this->wsyList.append(WSY("gi", "ぎ", "ギ"));
        this->wsyList.append(WSY("gu", "ぐ", "グ"));
        this->wsyList.append(WSY("ge", "げ", "ゲ"));
        this->wsyList.append(WSY("go", "ご", "ゴ"));
        this->wsyList.append(WSY("za", "ざ", "ザ"));
        this->wsyList.append(WSY("ji", "じ", "ジ"));
        this->wsyList.append(WSY("zu", "ず", "ズ"));
        this->wsyList.append(WSY("ze", "ぜ", "ゼ"));
        this->wsyList.append(WSY("zo", "ぞ", "ゾ"));
        this->wsyList.append(WSY("da", "だ", "ダ"));
        this->wsyList.append(WSY("ji", "ぢ", "ヂ"));
        this->wsyList.append(WSY("zu", "づ", "ヅ"));
        this->wsyList.append(WSY("de", "で", "デ"));
        this->wsyList.append(WSY("do", "ど", "ド"));
        this->wsyList.append(WSY("ba", "ば", "バ"));
        this->wsyList.append(WSY("bi", "び", "ビ"));
        this->wsyList.append(WSY("bu", "ぶ", "ブ"));
        this->wsyList.append(WSY("be", "べ", "ベ"));
        this->wsyList.append(WSY("bo", "ぼ", "ボ"));
        this->wsyList.append(WSY("pa", "ぱ", "パ"));
        this->wsyList.append(WSY("pi", "ぴ", "ピ"));
        this->wsyList.append(WSY("pu", "ぷ", "プ"));
        this->wsyList.append(WSY("pe", "ぺ", "ペ"));
        this->wsyList.append(WSY("po", "ぽ", "ポ"));
        this->wsyList.append(WSY("", "\r\n", "\r\n", false));
    }
    if (isAoEnable)
    {
        this->wsyList.append(WSY("kya", "きゃ", "キャ"));
        this->wsyList.append(WSY("kyu", "きゅ", "キュ"));
        this->wsyList.append(WSY("kyo", "きょ", "キョ"));
        this->wsyList.append(WSY("sha", "しゃ", "シャ"));
        this->wsyList.append(WSY("shu", "しゅ", "シュ"));
        this->wsyList.append(WSY("sho", "しょ", "ショ"));
        this->wsyList.append(WSY("cha", "ちゃ", "チャ"));
        this->wsyList.append(WSY("chu", "ちゅ", "チュ"));
        this->wsyList.append(WSY("cho", "ちょ", "チョ"));
        this->wsyList.append(WSY("nya", "にゃ", "ニャ"));
        this->wsyList.append(WSY("nyu", "にゅ", "ニュ"));
        this->wsyList.append(WSY("nyo", "にょ", "ニョ"));
        this->wsyList.append(WSY("hya", "ひゃ", "ヒャ"));
        this->wsyList.append(WSY("hyu", "ひゅ", "ヒュ"));
        this->wsyList.append(WSY("hyo", "ひょ", "ヒョ"));
        this->wsyList.append(WSY("mya", "みゃ", "ミャ"));
        this->wsyList.append(WSY("myu", "みゅ", "ミュ"));
        this->wsyList.append(WSY("myo", "みょ", "ミョ"));
        this->wsyList.append(WSY("rya", "りゃ", "リャ"));
        this->wsyList.append(WSY("ryu", "りゅ", "リュ"));
        this->wsyList.append(WSY("ryo", "りょ", "リョ"));
        this->wsyList.append(WSY("gya", "ぎゃ", "ギャ"));
        this->wsyList.append(WSY("gyu", "ぎゅ", "ギュ"));
        this->wsyList.append(WSY("gyo", "ぎょ", "ギョ"));
        this->wsyList.append(WSY("ja", "じゃ", "ジャ"));
        this->wsyList.append(WSY("ju", "じゅ", "ジュ"));
        this->wsyList.append(WSY("jo", "じょ", "ジョ"));
        this->wsyList.append(WSY("bya", "びゃ", "ビャ"));
        this->wsyList.append(WSY("byu", "びゅ", "ビュ"));
        this->wsyList.append(WSY("byo", "びょ", "ビョ"));
        this->wsyList.append(WSY("pya", "ぴゃ", "ピャ"));
        this->wsyList.append(WSY("pyu", "ぴゅ", "ピュ"));
        this->wsyList.append(WSY("pyo", "ぴょ", "ピョ"));
    }
}

QVector<WSY> WSYList::getWSYList()
{
    return this->wsyList;
}

WSY WSYList::randomChoose()
{
    int i = 0;
    do {
        i = qrand() % this->wsyList.size();
    } while(!this->wsyList[i].isSelectable());
    return this->wsyList[i];
}
