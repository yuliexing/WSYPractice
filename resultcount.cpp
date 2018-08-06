#include "resultcount.h"

ResultCount::ResultCount()
{
    clear();
}

void ResultCount::clear()
{
    totalCount = 0;
    correctCount = 0;
    errorCount = 0;
    specialCount = 0;
    maxCombo = 0;

    correctMap.clear();
    errorMap.clear();
    specialMap.clear();
}

void ResultCount::dealWithResult(QString jm, bool result)
{
    totalCount++;
    if (result)
    {
        if (correctMap.contains(jm))
        {
            correctMap[jm]++;
        }
        else
        {
            correctMap.insert(jm, 1);
        }
        correctCount++;
    }
    else
    {
        if (errorMap.contains(jm))
        {
            errorMap[jm]++;
        }
        else
        {
            errorMap.insert(jm, 1);
        }
        errorCount++;
    }
}

void ResultCount::dealWithSpecial(QString jm, WSY wsy)
{
    if (!specialMap.contains(jm))
    {
        specialMap.insert(jm, wsy);
    }
    specialCount++;
}

void ResultCount::dealWithCombo(int combo)
{
    if (combo > this->maxCombo)
        this->maxCombo = combo;
}

QString ResultCount::getResult()
{
    QString str = "";
    str += "---------------------------   Result   ---------------------------\n";
    str += "Total count: " + QString::number(totalCount) + "\n";
    str += "✓ count: " + QString::number(correctCount) + "\t";
    str += "✓ rate: " + QString::number((double)correctCount / totalCount * 100) + "%\n";
    str += "✗ count: " + QString::number(errorCount) + "\t";
    str += "✗ rate: " + QString::number((double)errorCount / totalCount * 100) + "%\n";
    str += "Max combo: " + QString::number(maxCombo) + "\n";

    if (specialMap.uniqueKeys().size() > 0)
    {
        str += "\nSpecial Error:\n";
        for (int i = 0; i < specialMap.uniqueKeys().size();i++)
        {
            QString key = specialMap.uniqueKeys().at(i);
            WSY value = specialMap.value(key);
            str += QString::number(i + 1) + "." + (i < 9 ? "  " : " ") + key + " | " + value.toString()
                    + " " +QString::number(errorMap.value(key));
            if ( (i + 1) % 3 == 0)
            {
                str += "\n";
            }
            else
            {
                str += "    \t";
            }
        }
    }

    if (errorMap.uniqueKeys().size() > 0)
    {
        str += "\nError list:\n";
        for (int i = 0; i < errorMap.uniqueKeys().size();i++)
        {
            QString key = errorMap.uniqueKeys().at(i);
            int value = errorMap.value(key);
            str += QString::number(i + 1) + "." + (i < 9 ? "  " : " ")+ key + " " + QString::number(value);
            if (specialMap.contains(key))
            {
                str += " ● ";
            }
            if ( (i + 1) % 3 == 0)
            {
                str += "\n";
            }
            else
            {
                str += "   \t";
            }
        }
    }

#ifdef DEBUG
    str += "\nCorrect list:\n";
    for (int i = 0; i < correctMap.uniqueKeys().size();i++)
    {
        QString key = correctMap.uniqueKeys().at(i);
        int value = correctMap.value(key);
        str += QString::number(i + 1) + "." + (i < 9 ? "  " : " ")+ key + " " + QString::number(value);
        if ( (i + 1) % 2 == 0)
        {
            str += "\n";
        }
        else
        {
            str += "   \t";
        }
    }
#endif

    str += "\n---------------------------    end    ---------------------------\n";
    return str;
}
