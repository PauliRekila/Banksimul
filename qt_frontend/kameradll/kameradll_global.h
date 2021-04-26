#ifndef KAMERADLL_GLOBAL_H
#define KAMERADLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KAMERADLL_LIBRARY)
#  define KAMERADLL_EXPORT Q_DECL_EXPORT
#else
#  define KAMERADLL_EXPORT Q_DECL_IMPORT
#endif

#endif // KAMERADLL_GLOBAL_H
