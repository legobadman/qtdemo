#ifndef _UI_COMMON_H__
#define _UI_COMMON_H__


#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
#define QtSkipEmptyParts Qt::SkipEmptyParts
#define qt_unordered_map std::unordered_map
#else

#define QtSkipEmptyParts QString::SkipEmptyParts
#define qt_unordered_map std::map
#endif



struct TIMELINE_INFO
{
    int beginFrame;
    int endFrame;
    int currFrame;
    bool bAlways;
    int timelinefps;

    TIMELINE_INFO() : beginFrame(0), endFrame(0), currFrame(0), bAlways(false), timelinefps(24) {}
};


inline QPair<int, int> numframes(qreal scaleX, qreal scaleY)
{
    int wtfX = 10 * scaleX * 1;
    int wtfY = 10 * scaleY * 1;
    int nX = 10, nY = 5;
    if (4 <= scaleX && scaleX < 12)
    {
        nX = 20;
    }
    else if (12 <= scaleX)
    {
        nX = 40;
    }

    if (2 <= scaleY && scaleY < 4)
    {
        nY = 10;
    }
    else if (4 <= scaleY)
    {
        nY = 20;
    }
    else if (8 <= scaleY)
    {
        nY = 40;
    }
    return { nX, nY };
}


struct CURVE_RANGE {
    qreal xFrom;
    qreal xTo;
   
    bool operator==(const CURVE_RANGE& rhs) const {
        return xFrom == rhs.xFrom && xTo == rhs.xTo;
    }
};


struct SLIDER_INFO {
    qreal step;
    qreal min;
    qreal max;
    SLIDER_INFO() : step(1.), min(0.), max(100.) {}
};
Q_DECLARE_METATYPE(SLIDER_INFO)


#endif
